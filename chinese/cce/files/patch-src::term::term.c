--- src/term/term.c.orig	Mon Jan 19 04:22:51 2004
+++ src/term/term.c	Sat Dec  4 11:29:39 2004
@@ -541,12 +541,14 @@
 		if (!GGIAvail && !UseSDLFirst) SDLAvail = IsSDLAvailable();
 #endif
 	
+#if defined(SUPPORT_GGILIB) || defined(SUPPORT_SDLLIB)
 		if (!GGIAvail && !SDLAvail)
 		{
 #if !defined(DEBUG) 
 			fatal("No GGI/SDL found, you can only run CCE in text console.\n");
 #endif /* DEBUG */
 		}
+#endif
 	}
 
 #endif /* __MSDOS__ */
