--- jpwl/jpwl.h.orig	2007-11-05 14:05:07.000000000 +0100
+++ jpwl/jpwl.h	2009-03-21 12:21:21.000000000 +0100
@@ -188,7 +188,7 @@
 		jpwl_esd_ms_t *esdmark;
 		/** pointer to RED marker */
 		jpwl_red_ms_t *redmark;
-	};
+	} u;
 	/** position where the marker should go, in the pre-JPWL codestream */ 
 	unsigned long int pos;
 	/** same as before, only written as a double, so we can sort it better */
