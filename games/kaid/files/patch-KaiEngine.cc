--- KaiEngine.cc.orig	Wed Feb  9 19:26:59 2005
+++ KaiEngine.cc	Sat Mar  5 20:53:51 2005
@@ -14,9 +14,14 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
+#include <errno.h>
+#include <pwd.h>
+#ifdef PLATFORM_freebsd
+#    include <login_cap.h>
+#    include <netinet/in.h>
+#endif
 
-#ifdef PLATFORM_macosx_jaguar
-#    include <sys/socket.h>
+#ifdef PLATFORM_bsd
 #    include <netinet/in_systm.h>
 #    include <netinet/if_ether.h>
 #    include <netinet/ip.h>
@@ -80,6 +85,32 @@
 {
 	m_bTerminate = false;
 	m_cSniffer = new CPktSnifferThread (this, m_cConf);
+	// After we have the networking set up, we no longer need
+	// the privileges that we are started with.
+	if(! m_cConf->User.empty()) {
+		const struct passwd *pwd = getpwnam(m_cConf->User.c_str());
+		if(pwd == 0) {
+			string err = "Unknown switch-to User: ";
+			err += m_cConf->User;
+			debuglog("KAID",err);
+			throw ThreadException(ThreadException::errUnknown);
+		}
+#if defined(PLATFORM_freebsd)
+		login_cap_t *lc = login_getpwclass(pwd);
+		if(lc == 0 ||
+                   setusercontext(lc, pwd, pwd->pw_uid, LOGIN_SETALL) != 0) {
+#else
+		if(initgroups(m_cConf->User.c_str(), pwd->pw_gid) != 0 ||
+		   setuid(pwd->pw_uid) != 0) {
+#endif
+			string err = "Unable to switch to User: ";
+			err += m_cConf->User;
+			err += ": ";
+			err += strerror(errno);
+			debuglog("KAID",err);
+			throw ThreadException(ThreadException::errUnknown);
+		}
+	}
 	m_cTOrb = new COrbStreamThread (this, m_cConf);
 	m_cUOrb = new COrbDgramThread (this, m_cConf);
 	
@@ -142,9 +173,10 @@
 	}
 	catch(SocketException & excep)
 	{
-	}
-	catch(...)
-	{
+		string err = "Failed to bind UI socket: ";
+		err += (const char *)excep;
+		debuglog("KAID",err);
+		throw ThreadException(ThreadException::errUnknown);
 	}
 	
 	string mlm = "Manual";
@@ -1425,6 +1457,11 @@
 	srcaddy = (struct ether_addr *) ep->ether_shost;
 	dstaddy = (struct ether_addr *) ep->ether_dhost;
 
+#if defined(PLATFORM_bsd) && \
+    !(defined(PLATFORM_macosx_1) || defined(PLATFORM_macosx_jaguar))
+#define ether_addr_octet octet
+#endif
+
 	// Get source MAC
 	sprintf (aux, "%02X%02X%02X%02X%02X%02X",
 		 srcaddy->ether_addr_octet[0], srcaddy->ether_addr_octet[1],
@@ -1447,7 +1484,7 @@
 					    sizeof (struct ether_header) +
 					    ((my_ip->ip_hl) << 2));
 	// Platform depend
-	#ifdef PLATFORM_macosx_jaguar
+	#ifdef PLATFORM_bsd
 		srcport = ntohs (my_packetheader->uh_sport);
 		dstport = ntohs (my_packetheader->uh_dport);
 	#else
@@ -1745,10 +1782,12 @@
 	// Set byte 0 of outgoing based on console
 	if (console=="0050F2" || console=="000D3A") 
 		Opcode = m_sCurrentArena.empty () ? 'X' : 'R'; // Box
-	if (console=="0009BF") 
+	else if (console=="0009BF") 
 		Opcode = m_sCurrentArena.empty () ? 'Y' : 'S'; // Cube
-	if (console=="00041F" || console=="00014A") 
+	else if (console=="00041F" || console=="00014A") 
 		Opcode = m_sCurrentArena.empty () ? 'p' : 'q'; // PS2 / PSP    
+	else
+		return;
 		
 	memcpy (newbuf + 2, packet, packet_size);
     newbuf[0] = Opcode;
@@ -2321,4 +2360,3 @@
 	}
 	m_bSeenAllDevices = !IsAnyDeviceMissing;
 }
-
