$FreeBSD$
--- src/GUI/ots_gui.c.orig	2012-01-13 07:12:50.000000000 -0700
+++ src/GUI/ots_gui.c	2012-02-07 08:14:06.000000000 -0700
@@ -731,7 +731,7 @@
   npanels = nlines / lines_per_page + 1;
   if (npanels < 2) npanels = 2;
   panelnames = (char **)malloc( (npanels+1) * sizeof(char *));
-  for (j=0; j<npanels; j++) {panelnames[j] = (char *)malloc(30); sprintf( panelnames[j], "Page %d ", j+1); }
+  for (j=0; j<npanels; j++) {int len = 30;panelnames[j] = (char *)malloc(len); snprintf(panelnames[j], len, "Page %d ", j+1); }
   Panels = Otk_Tabbed_Panel_New( main_panel, npanels, panelnames, Otk_LightGray, 1, 1, 98, 98, 5 );
   TabbedPanel = Panels;
 
@@ -791,7 +791,7 @@
      switch (entry->kind)
       {
        case VKIND_FLOAT:  // printf("Formbox: '%s'\n", messg);
-		sprintf(messg, "%12.2f", entry->value ); 
+		snprintf(messg, sizeof(messg), "%12.2f", entry->value ); 
 		pos_x = leftmargin;
 		leftmargin = leftmargin + box_width + 1.5;
 		pos_y = (float)linenum * 9.0 + 6.5;
@@ -1142,9 +1142,9 @@
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
@@ -1166,7 +1166,7 @@
    viewfile = fopen( outfname, "rb" );
    if (viewfile == 0)
     {
-     sprintf(vline,"Cannot open: %s", outfname);
+     snprintf(vline, sizeof(vline), "Cannot open: %s", outfname);
      Otk_Add_Selection_Item( viewwin, vline, 0, 0 ); 
     }
    else
@@ -1206,7 +1206,7 @@
 
 void togprntcmd_in(void *x)
 { 
- sprintf(printer_command,"%s %s", base_printer_command, wrkingfname);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, wrkingfname);
  Otk_Modify_Text( printerformbox, printer_command );
 }
 
@@ -1214,7 +1214,7 @@
 { char tmpstr[MaxFname];
   int k;
  predict_output_filename(wrkingfname,tmpstr);
- sprintf(printer_command,"%s %s", base_printer_command, tmpstr);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, tmpstr);
  Otk_Modify_Text( printerformbox, printer_command );
 }
 
@@ -1242,7 +1242,7 @@
  Otk_Add_BoundingBox( printpopup, Otk_Blue, 1.0, 18.0, 16.0, 63.0, 47.0 );
 
  if (working_file==0) strcpy(wrkingfname,filename_dat); else strcpy(wrkingfname,working_file);
- sprintf(printer_command,"%s %s", base_printer_command, wrkingfname);
+ snprintf(printer_command, sizeof(printer_command), "%s %s", base_printer_command, wrkingfname);
 
  OtkMakeTextLabel( printpopup, "Print Command:", Otk_Black, /*scale=*/ 1.5, /*weight=*/ 1, /*x=*/ 4, /*y=*/ 57 );
  printerformbox = OtkMakeTextFormBox( printpopup, printer_command, 60,  28.5, 55, 68, 18, acceptprinter_command2, 0 );
@@ -1302,15 +1302,15 @@
    if (k>0) k--;
    while ((k>0) && (tmpstr[k]!=slashchr)) k--;
    if (tmpstr[k]==slashchr)  tmpstr[k+1] = '\0';
-   else  {sprintf(tmpstr,".%c", slashchr);}
-   sprintf(directory_dat,"%sexamples_and_templates%c", tmpstr, slashchr);
+   else  {snprintf(tmpstr, sizeof(tmpstr), ".%c", slashchr);}
+   snprintf(directory_dat, sizeof(directory_dat), "%%PREFIX%%/share/ots/examples_and_templates%c", slashchr);
    Otk_Browse_Files( "Select TaxForm:", MaxFname, directory_dat, wildcards_dat, taxsolvestrng, open_taxfile );
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
@@ -1321,8 +1321,8 @@
    if (k>0) k--;
    while ((k>0) && (tmpstr[k]!=slashchr)) k--;
    if (tmpstr[k]==slashchr)  tmpstr[k+1] = '\0';
-   else  {sprintf(tmpstr,".%c", slashchr);}
-   sprintf(directory_dat,"%sexamples_and_templates%c", tmpstr, slashchr);
+   else  {snprintf(tmpstr, sizeof(tmpstr), ".%c", slashchr);}
+   snprintf(directory_dat, sizeof(directory_dat), "%%PREFIX%%/share/ots/examples_and_templates%c", slashchr);
 
    sel = strstr( strg, "_2011" );
    if (sel != 0)
@@ -1399,7 +1399,7 @@
    {printf("Unknown command-line parameter '%s'\n", argv[argn]); /* exit(1); */ }
   argn = argn + 1;
  }
- sprintf(vrsnmssg,"OTS GUI v%1.2f", version);  printf("%s\n\n",vrsnmssg);
+ snprintf(vrsnmssg, sizeof(vrsnmssg), "OTS GUI v%1.2f", version);  printf("%s\n\n",vrsnmssg);
  invocation_path = strdup(argv[0]);
  k = strlen(invocation_path)-1;
  while ((k>0) && (invocation_path[k]!=slashchr)) k--;
@@ -1436,7 +1436,7 @@
   OtkMakeImagePanel_ImgPtr( subpanel, logo_image, 1.5, 5.0, 96.8, 89.85 );
  }
 #else
- sprintf(tmpstr,"%s..%csrc%cGUI%cotslogo.ppm", invocation_path, slashchr, slashchr, slashchr );
+ snprintf(tmpstr, sizeof(tmpstr), "%%PREFIX%%/share/ots/otslogo.ppm");
  testfile = fopen(tmpstr,"r");	/* External image-file. */
  if (testfile!=0)
   { /* Only attempt to show image if image-file is where we expect to find it. */
