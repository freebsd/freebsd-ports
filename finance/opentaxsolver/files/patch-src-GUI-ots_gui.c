--- src/GUI/ots_gui.c.orig	2008-02-10 12:57:32.000000000 -0700
+++ src/GUI/ots_gui.c	2008-02-19 18:17:30.000000000 -0700
@@ -1026,7 +1026,7 @@
   }
  else
   {
-   sprintf(tmpstr,"%s%s", invocation_path, strg);
+   snprintf(tmpstr, sizeof(tmpstr), "%s%s", invocation_path, strg);
    printf("Setting Tax Program to be: '%s'\n", tmpstr);
    taxsolvecmd = strdup(tmpstr);
    strcpy(taxsolvestrng,tmpstr);
@@ -1037,8 +1037,8 @@
    if (k>0) k--;
    while ((k>0) && (tmpstr[k]!=slashchr)) k--;
    if (tmpstr[k]==slashchr)  tmpstr[k+1] = '\0';
-   else  {sprintf(tmpstr,".%c", slashchr);}
-   sprintf(directory_dat,"%sexamples_and_templates%c", tmpstr, slashchr);
+   else  {snprintf(tmpstr, sizeof(tmpstr), ".%c", slashchr);}
+   snprintf(directory_dat, sizeof(directory_dat), "%sexamples_and_templates%c", "%%PREFIX%%/share/ots/", slashchr);
    /* CA_540  MA_1  NC_400  NJ_1040  NY_IT201  OH_1040  PA_40  US_1040  US_1040_Sched_C  VA_760 */
    if (strstr(strg,"CA_540")) strcat(directory_dat,"CA_540"); else
    if (strstr(strg,"MA_1")) strcat(directory_dat,"MA_1"); else
@@ -1118,7 +1118,7 @@
  main_panel = 
  OtkMakePanel( OtkOuterWindow, Otk_Raised, Otk_LightGray, 1, 7.5, 98, 87 );	/* Main Panel. */
  Otk_SetBorderThickness( main_panel, 0.25 );
- sprintf(tmpstr,"%s..%csrc%cGUI%cotslogo.ppm", invocation_path, slashchr, slashchr, slashchr );
+ snprintf(tmpstr, sizeof(tmpstr), "%%PREFIX%%/share/ots/otslogo.ppm");
  subpanel = OtkMakePanel( main_panel, Otk_Raised, Otk_LightGray, 18.5, 2, 63, 17 );
  Otk_SetBorderThickness( subpanel, 0.75 );
  testfile = fopen(tmpstr,"r");
