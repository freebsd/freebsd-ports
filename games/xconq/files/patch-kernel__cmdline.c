--- kernel/cmdline.c.orig
+++ kernel/cmdline.c
@@ -329,7 +329,7 @@
 	    printf("    %s\n");
 	    if (mainmodule->blurb != lispnil) {
 	    	append_blurb_strings(blurb, mainmodule->blurb);
-	    	printf(blurb);
+	    	printf("%s", blurb);
 	    } else {
 	    	printf("(no description)");
 	    }
