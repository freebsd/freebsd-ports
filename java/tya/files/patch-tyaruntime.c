--- ./tyaruntime.c.orig	Tue Oct 28 00:35:00 2003
+++ ./tyaruntime.c	Tue Oct 28 00:35:15 2003
@@ -126,8 +126,8 @@
 {
    FASTINVPREPARE();
 }
-#endif USEASM
-#endif TRY_FAST_INVOKE
+#endif /* USEASM */
+#endif /* TRY_FAST_INVOKE */
 
 
 //---------------------------------------------------------------------------------
