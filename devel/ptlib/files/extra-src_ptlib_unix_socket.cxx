--- src/ptlib/unix/socket.cxx.orig	2009-12-12 11:42:03.000000000 +0800
+++ src/ptlib/unix/socket.cxx	2009-12-12 11:46:09.000000000 +0800
@@ -1144,10 +1144,6 @@ PBoolean process_rtentry(struct rt_msghd
   if ((~rtm->rtm_flags&RTF_LLINFO)
 #if defined(P_NETBSD) || defined(P_QNX)
         && (~rtm->rtm_flags&RTF_CLONED)     // Net BSD has flag one way
-#elif !defined(P_OPENBSD)
-        && (~rtm->rtm_flags&RTF_WASCLONED)  // Free BSD/MAC has it another
-#else
-                                            // Open BSD does not have it at all!
 #endif
      ) {
 
