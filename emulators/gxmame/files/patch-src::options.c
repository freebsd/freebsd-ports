--- src/options.c.orig	Sat Oct 23 18:16:28 2004
+++ src/options.c	Sat Oct 23 18:17:37 2004
@@ -7298,8 +7298,6 @@
 						"%s "				/* newext */
 						"-%sxsync "
 						"-%sprivatecmap "
-						"-%sxil "
-						"-%smtxil "
 						"%s ",				/* Video mode */
 						x11mode,
 						(target->cursor)?"":"no",
@@ -7308,8 +7306,6 @@
 						newext?newext:"",
 						(target->xsync)?"":"no",
 						(target->privatecmap)?"":"no",
-						(target->xil)?"":"no",
-						(target->mtxil)?"":"no",
 						Video_Mode_option?Video_Mode_option:""
 						);
 		}
@@ -7323,8 +7319,6 @@
 						"%s "				/* newext */
 						"-%sxsync "
 						"-%sprivatecmap "
-						"-%sxil "
-						"-%smtxil "
 						"%s ",				/* Video mode */
 						target->x11_mode,
 						(target->cursor)?"":"no",
@@ -7334,8 +7328,6 @@
 						newext?newext:"",
 						(target->xsync)?"":"no",
 						(target->privatecmap)?"":"no",
-						(target->xil)?"":"no",
-						(target->mtxil)?"":"no",
 						Video_Mode_option?Video_Mode_option:""
 						);
 		}
