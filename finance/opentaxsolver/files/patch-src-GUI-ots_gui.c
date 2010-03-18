--- src/GUI/ots_gui.c.orig	2010-03-02 06:46:32.000000000 -0700
+++ src/GUI/ots_gui.c	2010-03-08 17:55:11.000000000 -0700
@@ -638,7 +638,7 @@
  /* Now create enough tabbed-panels to hold all the lines. */
   npanels = nlines / lines_per_page + 1;
   panelnames = (char **)malloc( (npanels+1) * sizeof(char *));
-  for (j=0; j<npanels; j++) {panelnames[j] = (char *)malloc(30); sprintf( panelnames[j], "Page %d ", j+1); }
+  for (j=0; j<npanels; j++) {panelnames[j] = (char *)malloc(30); snprintf(panelnames[j], sizeof(panelnames[j]), "Page %d ", j+1); }
   Panels = Otk_Tabbed_Panel_New( main_panel, npanels, panelnames, Otk_LightGray, 1, 1, 98, 98, 5 );
   TabbedPanel = Panels;
 
@@ -698,7 +698,7 @@
      switch (entry->kind)
       {
        case VKIND_FLOAT:  // printf("Formbox: '%s'\n", messg);
-		sprintf(messg, "%12.2f", entry->value ); 
+		snprintf(messg, sizeof(messg), "%12.2f", entry->value ); 
 		pos_x = leftmargin;
 		leftmargin = leftmargin + box_width + 1.5;
 		pos_y = (float)linenum * 9.0 + 6.5;
@@ -986,9 +986,9 @@
    return;   
   }
  if (PLATFORM_KIND==Posix_Platform)
-  sprintf(cmd,"%s %s &", taxsolvecmd, working_file );
+  snprintf(cmd, sizeof(cmd), "%s %s &", taxsolvecmd, working_file );
  else
-  sprintf(cmd,"%s %s", taxsolvecmd, working_file );
+  snprintf(cmd, sizeof(cmd), "%s %s", taxsolvecmd, working_file );
 
  printf("Invoking '%s'\n", cmd );
  system(cmd);	/* Invoke the TaxSolver. */
@@ -1022,7 +1022,7 @@
 
 void togprntcmd_in(void *x)
 { 
- sprintf(printer_command,"%s %s", base_printer_command, wrkingfname);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, wrkingfname);
  Otk_Modify_Text( printerformbox, printer_command );
 }
 
@@ -1030,7 +1030,7 @@
 { char tmpstr[MaxFname];
   int k;
  predict_output_filename(wrkingfname,tmpstr);
- sprintf(printer_command,"%s %s", base_printer_command, tmpstr);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, tmpstr);
  Otk_Modify_Text( printerformbox, printer_command );
 }
 
@@ -1058,7 +1058,7 @@
  Otk_Add_BoundingBox( printpopup, Otk_Blue, 1.0, 18.0, 16.0, 63.0, 47.0 );
 
  if (working_file==0) strcpy(wrkingfname,filename_dat); else strcpy(wrkingfname,working_file);
- sprintf(printer_command,"%s %s", base_printer_command, wrkingfname);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, wrkingfname);
 
  OtkMakeTextLabel( printpopup, "Print Command:", Otk_Black, /*scale=*/ 1.5, /*weight=*/ 1, /*x=*/ 4, /*y=*/ 57 );
  printerformbox = OtkMakeTextFormBox( printpopup, printer_command, 60,  28.5, 55, 68, 18, acceptprinter_command2, 0 );
@@ -1117,15 +1117,15 @@
    if (k>0) k--;
    while ((k>0) && (tmpstr[k]!=slashchr)) k--;
    if (tmpstr[k]==slashchr)  tmpstr[k+1] = '\0';
-   else  {sprintf(tmpstr,".%c", slashchr);}
-   sprintf(directory_dat,"%sexamples_and_templates%c", tmpstr, slashchr);
+   else  {snprintf(tmpstr, sizeof(tmpstr), ".%c", slashchr);}
+   snprintf(directory_dat, sizeof(directory_dat), "%sexamples_and_templates%c", tmpstr, slashchr);
    Otk_Browse_Files( "Select TaxSolver:", MaxFname, directory_dat, wildcards_dat, taxsolvestrng, open_taxfile );
    return;
   }
  else
   {
    selected_other = 0;
-   sprintf(tmpstr,"%s%s", invocation_path, strg);
+   snprintf(tmpstr, sizeof(tmpstr), "%s%s", invocation_path, strg);
    printf("Setting Tax Program to be: '%s'\n", tmpstr);
    taxsolvecmd = strdup(tmpstr);
    strcpy(taxsolvestrng,tmpstr);
@@ -1136,8 +1136,8 @@
    if (k>0) k--;
    while ((k>0) && (tmpstr[k]!=slashchr)) k--;
    if (tmpstr[k]==slashchr)  tmpstr[k+1] = '\0';
-   else  {sprintf(tmpstr,".%c", slashchr);}
-   sprintf(directory_dat,"%sexamples_and_templates%c", tmpstr, slashchr);
+   else  {snprintf(tmpstr, sizeof(tmpstr), ".%c", slashchr);}
+   snprintf(directory_dat, sizeof(directory_dat), "%sexamples_and_templates%c", tmpstr, slashchr);
 
    sel = strstr( strg, "_2009" );
    sel[0] = '\0';
@@ -1208,7 +1208,7 @@
    {printf("Unknown command-line parameter '%s'\n", argv[argn]); /* exit(1); */ }
   argn = argn + 1;
  }
- sprintf(vrsnmssg,"OTS GUI v%1.2f", version);  printf("%s\n\n",vrsnmssg);
+ snprintf(vrsnmssg, sizeof(vrsnmssg), "OTS GUI v%1.2f", version);  printf("%s\n\n",vrsnmssg);
  invocation_path = strdup(argv[0]);
  k = strlen(invocation_path)-1;
  while ((k>0) && (invocation_path[k]!=slashchr)) k--;
@@ -1234,7 +1234,7 @@
  main_panel = 
  OtkMakePanel( bckgrnd, Otk_Raised, Otk_LightGray, 1, 7.5, 98, 87 );	/* Main Panel. */
  Otk_SetBorderThickness( main_panel, 0.25 );
- sprintf(tmpstr,"%s..%csrc%cGUI%cotslogo.ppm", invocation_path, slashchr, slashchr, slashchr );
+ snprintf(tmpstr, sizeof(tmpstr), "%%PREFIX%%/share/ots/otslogo.ppm");
  subpanel = OtkMakePanel( main_panel, Otk_Raised, Otk_LightGray, 18.5, 2, 63, 17 );
  Otk_SetBorderThickness( subpanel, 0.75 );
  testfile = fopen(tmpstr,"r");
