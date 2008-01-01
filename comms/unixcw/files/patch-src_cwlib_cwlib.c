--- src/cwlib/cwlib.c.orig	2006-06-22 21:54:01.000000000 -0400
+++ src/cwlib/cwlib.c	2008-01-01 11:54:49.000000000 -0500
@@ -63,6 +63,7 @@
 
 #if defined(BSD)
 # define ERR_NO_SUPPORT EPROTONOSUPPORT
+# define RTSIG_MAX NSIG
 #else
 # define ERR_NO_SUPPORT EPROTO
 #endif
@@ -2837,8 +2838,14 @@
        * crude, but perhaps just slightly better than doing nothing.
        */
       if (cw_volume > 0)
+/* FreeBSD at least uses hz directly, I'll assume other BSDs do too. - db */
+#ifdef BSD
+	argument = frequency != TONE_SILENT
+		? frequency : 0;
+#else
         argument = frequency != TONE_SILENT
                    ? KIOCSOUND_CLOCK_TICK_RATE / frequency : 0;
+#endif
       else
         argument = 0;
 
