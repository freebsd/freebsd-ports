
Add -C user@host support instead of just -C user and add support for
IPv6 in ftpusers.

FreeBSD does not have _PASSWORD_CHGNOW defined, so use direct constant
instead.

We are sure, that we have good LOGIN_NAME_MAX from tnftpd.h, so use it
instead of unnecessarily conservative _POSIX_LOGIN_NAME_MAX.

--- src/ftpd.c.orig	Wed Sep 27 07:22:18 2006
+++ src/ftpd.c	Thu Dec 14 00:19:55 2006
@@ -371,6 +371,24 @@
 			break;
 
 		case 'C':
+			if ((p = strchr(optarg, '@')) != NULL) {
+				*p++ = '\0';
+				strlcpy(remotehost, p, MAXHOSTNAMELEN + 1);
+				if (inet_pton(AF_INET, p,
+				    &his_addr.su_addr) == 1) {
+					his_addr.su_family = AF_INET;
+					his_addr.su_len =
+					    sizeof(his_addr.si_su.su_sin);
+#ifdef INET6
+				} else if (inet_pton(AF_INET6, p,
+				    &his_addr.su_6addr) == 1) {
+					his_addr.su_family = AF_INET6;
+					his_addr.su_len =
+					    sizeof(his_addr.si_su.su_sin6);
+#endif
+				} else
+					his_addr.su_family = AF_UNSPEC;
+			}
 			pw = sgetpwnam(optarg);
 			exit(checkaccess(optarg) ? 0 : 1);
 			/* NOTREACHED */
@@ -496,12 +514,12 @@
 		exit(1);
 	} else if (l <= 0) {
 		syslog(LOG_WARNING, "using conservative LOGIN_NAME_MAX value");
-		curname_len = _POSIX_LOGIN_NAME_MAX;
+		curname_len = LOGIN_NAME_MAX;
 	} else 
 		curname_len = (size_t)l;
 #else
 	/* using conservative LOGIN_NAME_MAX value */
-	curname_len = _POSIX_LOGIN_NAME_MAX;
+	curname_len = LOGIN_NAME_MAX;
 #endif
 	curname = malloc(curname_len);
 	if (curname == NULL) {
@@ -1166,18 +1184,38 @@
 
 					/* have a host specifier */
 		if ((p = strchr(word, '@')) != NULL) {
-			unsigned long	net, mask, addr;
-			int		bits;
+			char		net[16], mask[16], *addr;
+			int		addrlen, bits, bytes, a;
 
 			*p++ = '\0';
 					/* check against network or CIDR */
-			if (isdigit((unsigned char)*p) &&
-			    (bits = inet_net_pton(AF_INET, p,
-			    &net, sizeof(net))) != -1) {
-				net = ntohl(net);
-				mask = 0xffffffffU << (32 - bits);
-				addr = ntohl(his_addr.su_addr.s_addr);
-				if ((addr & mask) != net)
+			memset(net, 0x00, sizeof(net));
+			if ((bits = inet_net_pton(his_addr.su_family, p, net,
+			    sizeof(net))) != -1) {
+#ifdef INET6
+				if (his_addr.su_family == AF_INET) {
+#endif
+					addrlen = 4;
+					addr = (char *)&his_addr.su_addr;
+#ifdef INET6
+				} else {
+					addrlen = 16;
+					addr = (char *)&his_addr.su_6addr;
+				}
+#endif
+				bytes = bits / 8;
+				bits = bits % 8;
+				if (bytes > 0)
+					memset(mask, 0xFF, bytes);
+				if (bytes < addrlen)
+					mask[bytes] = 0xFF << (8 - bits);
+				if (bytes + 1 < addrlen)
+					memset(mask + bytes + 1, 0x00,
+					    addrlen - bytes - 1);
+				for (a = 0; a < addrlen; a++)
+					if ((addr[a] & mask[a]) != net[a])
+						break;
+				if (a < addrlen)
 					continue;
 
 					/* check against hostname glob */
@@ -3744,7 +3782,7 @@
 	expire = pwent->pw_expire;
 #endif
 #if HAVE_PW_CHANGE
-	change = (pwent->pw_change == _PASSWORD_CHGNOW)? now : pwent->pw_change;
+	change = (pwent->pw_change == -1)? now : pwent->pw_change;
 #endif
 #endif
 
