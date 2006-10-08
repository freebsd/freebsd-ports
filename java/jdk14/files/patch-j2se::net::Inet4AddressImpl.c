$FreeBSD$

--- ../../j2se/src/solaris/native/java/net/Inet4AddressImpl.c.old	Tue Jun 27 02:55:32 2006
+++ ../../j2se/src/solaris/native/java/net/Inet4AddressImpl.c	Tue Jun 27 02:55:35 2006
@@ -13,6 +13,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>
+#include <pthread.h>
 #if defined(_ALLBSD_SOURCE)
 #include <unistd.h>
 #if defined(__FreeBSD__) && __FreeBSD__ > 4
@@ -312,6 +313,34 @@
                 struct hostent *hptr,
                 HOST_R_ARGS);

+/*
+ * BSDNOTE: Since we are emulating thread-safe functions, we need to
+ * ensure they're not running in parallel.  So, setup mutexes
+ *
+ * XXXBSD: make sure it works as expected
+ * XXXBSD: move initialization to somethere earlier
+ */
+
+pthread_mutex_t _net_mutex = PTHREAD_MUTEX_INITIALIZER;
+static int _net_mutex_inited = 0;
+
+static int
+_acquire_net_mutex()
+{
+	if (_net_mutex_inited == 0) {
+		if (pthread_mutex_init(&_net_mutex, NULL))
+			return (EINVAL);
+		_net_mutex_inited = 1;
+	}
+	return (pthread_mutex_lock(&_net_mutex));
+}
+
+static int
+_release_net_mutex()
+{
+	return (pthread_mutex_unlock(&_net_mutex));
+}
+
 #endif

 /************************************************************************
@@ -355,15 +384,19 @@
 #ifdef __GLIBC__
 	gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #else
+	_acquire_net_mutex();
 	hp = JDK_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
+	_release_net_mutex();
 #endif
 	if (hp) {
 #ifdef __GLIBC__
 	    gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 			    &res2, buf2, sizeof(buf2), &hp, &h_error);
 #else
+	    _acquire_net_mutex();
 	    hp = JDK_gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 				 &res2, buf2, sizeof(buf2), &h_error);
+	    _release_net_mutex();
 #endif
 	    if (hp) {
 		/*
@@ -428,7 +461,9 @@
 #ifdef __GLIBC__
     gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #else    
+    _acquire_net_mutex();
     hp = JDK_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
+    _release_net_mutex();
 #endif

     /* With the re-entrant system calls, it's possible that the buffer
@@ -442,8 +477,10 @@
 	    gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 			    &hp, &h_error);
 #else
+	    _acquire_net_mutex();
 	    hp = JDK_gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 				 &h_error);
+	    _release_net_mutex();
 #endif
 	}
     }
@@ -531,8 +568,10 @@
     gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 		    buf, sizeof(buf), &hp, &h_error);
 #else
+    _acquire_net_mutex();
     hp = JDK_gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 			 buf, sizeof(buf), &h_error);
+    _release_net_mutex();
 #endif
     /* With the re-entrant system calls, it's possible that the buffer
      * we pass to it is not large enough to hold an exceptionally
@@ -545,8 +584,10 @@
 	    gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 			    &hent, tmp, BIG_HENT_BUF_SIZE, &hp, &h_error);
 #else
+	    _acquire_net_mutex();
 	    hp = JDK_gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 				 &hent, tmp, BIG_HENT_BUF_SIZE, &h_error);
+	    _release_net_mutex();
 #endif
 	} else {
 	    JNU_ThrowOutOfMemoryError(env, "getHostByAddr");
