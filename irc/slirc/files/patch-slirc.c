--- ./slirc.c.orig	1999-08-23 11:15:11.000000000 -0400
+++ ./slirc.c	2009-01-18 22:11:53.000000000 -0500
@@ -81,7 +81,7 @@
    char buf[130];
    
    sprintf(buf, "Caught sig %d (%s)", signum, Top2);
-   SLang_doerror(buf);
+   SLang_verror(signum, buf);
    if (VF_reset) SLexecute_function(VF_reset);
    exit(1);
 }
@@ -242,7 +242,7 @@
 {
    char secs[8];
 	 
-	 sprintf(Status, "%s -> %s  Server[%s]  %s",
+	 snprintf(Status, sizeof(Status), "%s -> %s  Server[%s]  %s",
 	   NickName, Target, ServerName, StatMsg);
    
    SLsmg_gotorc(start, 0);
@@ -339,13 +339,15 @@
    
    /* now for scripts search-path */
    if((q = getenv("HOME")))
-     sprintf(SLirc_Load_Path,"%s/.slirc/scripts:",q);
+     snprintf(SLirc_Load_Path, 196, "%s/.slirc/scripts",q);
    else
-     sprintf(SLirc_Load_Path,"/home/%s/.slirc/scripts:",p);
+     snprintf(SLirc_Load_Path, 196, "/home/%s/.slirc/scripts",p);
 
 	 if (2 != SLpath_file_exists(SLirc_Load_Path))
 	   SLirc_Load_Path[0] = '\0';
-   
+   	 else
+	   strcat(SLirc_Load_Path, ":");
+
 	 strcat(SLirc_Load_Path,SCRIPTPATH); /* SCRIPTPATH defined in Makefile */
 }
 
@@ -758,7 +760,7 @@
 	SLsmg_reset_smg();
 	SLang_reset_tty();
   if (VF_reset) SLexecute_function(VF_reset);
-	SLang_doerror(st);
+	SLang_verror(SL_INTRINSIC_ERROR, st);
 	puts(st);
 	exit(1);
 }
@@ -774,8 +776,8 @@
 
 static void ClearSomeErrors(void)
 {
-	if (SLang_Error && SLang_Error != USER_BREAK) {
-		SLang_Error = 0;
+	if (USER_BREAK != SLang_get_error()) {
+		SLang_set_error(0);
 		SLsmg_touch_lines(0, SLtt_Screen_Rows);
 		SLirc_UpdateDisplay();
 		SLang_input_pending(20);
@@ -1016,7 +1018,7 @@
 	SLtt_get_terminfo();					/* Get the terminal info. */
 	SLtt_Use_Ansi_Colors = 1;
 	if (-1 == SLkp_init()) {
-		SLang_doerror("SLkp_init failed.");
+		SLang_verror(SL_INTRINSIC_ERROR, "SLkp_init failed.");
 		exit(1);
 	}
 
@@ -1026,7 +1028,7 @@
 	 *   (actually, opost's ignored in slang-1.0.3 )
 	 */
 	if (-1 == SLang_init_tty(abort_char, 0, 0)) {
-		SLang_doerror("Unable to initialize the terminal.");
+		SLang_verror(SL_INTRINSIC_ERROR, "Unable to initialize the terminal.");
 		exit(1);
 	}
 	SLsmg_init_smg(); /* this does get_screen_size inside. */
@@ -1073,9 +1075,9 @@
 	SetStatus("Loading SLirc init script...");
 	SLirc_UpdateDisplay();
 	SLang_load_file(argv[1] ? argv[1] : "init.sl");
-	if (SLang_Error) {
-		SLang_doerror("Oh, shit. Who fucked up that file, then?");
-		SLang_Error = 0;
+	if (SLang_get_error()) {
+		SLang_verror(SL_INTRINSIC_ERROR, "Oh, shit. Who fucked up that file, then?");
+		SLang_set_error(0);
 	}
 	SLtt_Use_Ansi_Colors = UseColours;
 	SLirc_UpdateDisplay();
@@ -1087,7 +1089,7 @@
 	check_timed = SLang_get_function("check_timed");
 	if (!check_timed) Fatal("check_timed is undefined");
 	expiry = time(NULL)+5;
-	while (SLang_Error != USER_BREAK) {
+	while (USER_BREAK != SLang_get_error()) {
 		int r,stkdep;
 		unsigned int tim;
 		
@@ -1106,7 +1108,7 @@
 		tim = time(NULL);
 		if (tim<expiry) continue;
 		expiry += 5;
-		stkdep = _SLstack_depth();
+		stkdep = SLstack_depth();
 		r = SLexecute_function(check_timed);
 		if (r==-1) Fatal("SLexecute_function(check_timed)?");
 #		if 0
@@ -1114,8 +1116,8 @@
 		if (!r) Fatal("check_timed is undefined");
 #		endif
 		SLirc_UpdateDisplay();
-		stkdep = _SLstack_depth() - stkdep; /* % items left on stack. */
-		if (stkdep && SLang_Error != USER_BREAK) {
+		stkdep = SLstack_depth() - stkdep; /* % items left on stack. */
+		if (stkdep && USER_BREAK != SLang_get_error()) {
 			SLang_verror(SL_APPLICATION_ERROR,
 		  	"Eeek... check_timed() left %d units on stack",stkdep);
 			if (stkdep>0) SLdo_pop_n(stkdep);
