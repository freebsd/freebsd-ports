--- src/ptlib/unix/socket.cxx.old	2007-10-19 02:22:32.000000000 -0400
+++ src/ptlib/unix/socket.cxx	2009-02-09 20:05:59.000000000 -0500
@@ -1446,7 +1446,7 @@
   if ((~rtm->rtm_flags&RTF_LLINFO)
 #if defined(P_NETBSD) || defined(P_QNX)
         && (~rtm->rtm_flags&RTF_CLONED)     // Net BSD has flag one way
-#elif !defined(P_OPENBSD)
+#elif !defined(P_OPENBSD) && defined(RTF_WASCLONED)
         && (~rtm->rtm_flags&RTF_WASCLONED)  // Free BSD/MAC has it another
 #else
                                             // Open BSD does not have it at all!
