--- xttpd.cc.orig	2016-01-23 13:26:42 UTC
+++ xttpd.cc
@@ -258,7 +258,21 @@ static void setupSocket (sockaddr_storag
       Global::xperror ("setsockopt");
     }
   }
-  bool bound = (bind(s,(sockaddr *)&addr,sizeof(addr))==0);
+
+  // 2016-02-21  Manfred Antar reported "bind: Invalid argument" occurring on
+  // FreeBSD and OS X as a regression from 2.14 when trying to bind port
+  // 8080, with or without an explicit address.  The only change that should
+  // have been visible to bind is that the size argument got bigger.  The
+  // FreeBSD man page for bind states that EINVAL can be raised if "the
+  // addrlen argument is not a valid length for the address family."  I guess
+  // this means that apps making use of sockaddr_storage are supposed to lie
+  // about the length.  The linux man page similarly states that EINVAL can
+  // be raised if "the addrlen is wrong" but the problem does not reproduce
+  // with my libc.
+  const socklen_t addrlen (addr.ss_family==AF_INET6 ? sizeof(sockaddr_in6)
+                                                    : sizeof(sockaddr_in));
+
+  bool bound = (bind(s,(sockaddr *)&addr,addrlen)==0);
   int yerrno = errno;
   if (!bound && addr.ss_family == AF_INET6) {
 
@@ -288,7 +302,7 @@ static void setupSocket (sockaddr_storag
 
     for (unsigned magic=4; !bound && magic>0; --magic) {
       ((sockaddr_in6 *)&addr)->sin6_scope_id = magic;
-      bound = (bind(s,(sockaddr *)&addr,sizeof(addr))==0);
+      bound = (bind(s,(sockaddr *)&addr,addrlen)==0);
     }
   }
   // Report the error from the first failure so that it won't be obscured by
