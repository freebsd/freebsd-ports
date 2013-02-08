--- event.c.orig
+++ event.c
@@ -134,7 +134,7 @@
 set_special_event_handling()
 {
     if (In_special_event_mode)
-	return;
+	return(0);
 
     xv_set(message_panel,
 			PANEL_BACKGROUND_PROC,	play_back_proc,
@@ -151,7 +151,7 @@
 clr_special_event_handling()
 {
     if (!In_special_event_mode)
-	return;
+	return(0);
 
     xv_set(message_panel,
 			PANEL_BACKGROUND_PROC,	NULL,
@@ -761,7 +761,7 @@
 	    p = xv_mem_create(64, 64, 8);
 	    if (p == NULL) {
 		fprintf(stderr, "begin_preview: xv_mem_create returned NULL\n");
-		return;
+		return(0);
 	    }
 	}
 	if (selptr->si_before_preview == NULL) {
@@ -775,7 +775,7 @@
 	    if (selptr->si_before_preview == NULL) {
 		fprintf(stderr,
 			"begin_preview: error, couldn't create server image\n");
-		return;
+		return(0);
 	    }
 	}
 
