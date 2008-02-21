--- io.c.orig	2007-07-01 15:19:57.000000000 -0400
+++ io.c	2008-02-21 11:30:53.000000000 -0500
@@ -17,6 +17,7 @@
 static void rewrite_contest_file(void);
 static void write_call_library_file(void);
 static gint process_tmp_file(const gchar *filnam);
+static char* chomp(char *s);
 
 static void fill_iend_array(void)
 {
@@ -99,24 +100,22 @@
   strcat(contest_line, cr_array[qnum].tx);
   strcpy(field_hold, cr_array[qnum].prefix);
   right_blank_pad(field_hold, sizeof(cr_array[qnum].prefix));
-  strcat(contest_line, field_hold);
-  add_eol_chars (contest_line);
+  sprintf(contest_line,"%s%s\n",contest_line,field_hold);
 }
 
 static void read_ini_file(void)
 {
   FILE *fp;
   gchar filnam[13], msg[49], contest_ini_line[76];
-  gint i, icolon, lcil, socil;
+  gint i, socil;
+  char *token;
   guint answer;
 
-  strcpy(filnam, contest_file_base);
-  strcat(filnam, ".INI");
+  snprintf(filnam,sizeof(filnam), "%s.INI", contest_file_base);
   fp = fopen(filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, filnam);
-    strcat(msg, " does not exist.  Use default? (Y/N)");
+    snprintf(msg,sizeof(msg),"%s does not exist.  Use default? (Y/N)");
     play_bells (DUPE_SOUND);
     answer = boxed_message (msg, 0, LT_GRAY);
     if(toupper_ui(answer)=='Y') fp = fopen("DEFAULT.INI","r");
@@ -125,53 +124,41 @@
   socil = sizeof(contest_ini_line);
   for(i=0; i<MAX_INIT_ITEMS; i++)
    {
-    fgets(contest_ini_line, socil, fp);
-    if(feof(fp)) break;
-    icolon = kb_index (contest_ini_line, ":");
-    if(icolon>-1)
-     {
-      lcil = strlen(contest_ini_line);
-      if(contest_ini_line[lcil-1]=='\n') contest_ini_line[lcil-1] = '\0';
-      if(contest_ini_line[lcil-2]=='\r') contest_ini_line[lcil-2] = '\0';
-      lcil = strlen(contest_ini_line);
-      if(lcil>icolon+1)
-       concat(init_screen_choices[i], contest_ini_line,
-              icolon+1, lcil-1, COPY);
-     }
+    if(fgets(contest_ini_line, socil, fp) == NULL)
+	break;
+    token = strtok(contest_ini_line, ":\r\n");
+    if (token != NULL)
+      {
+	token = strtok(NULL,":\r\n");
+	if (token != NULL)
+	  strcpy(init_screen_choices[i], token);
+      }
    }
   for(i=0; i<MAX_SET_ITEMS; i++)
    {
-    fgets(contest_ini_line, socil, fp);
-    if(feof(fp)) break;
-    icolon = kb_index (contest_ini_line, ":");
-    if(icolon>-1)
-     {
-      lcil = strlen(contest_ini_line);
-      if(contest_ini_line[lcil-1]=='\n') contest_ini_line[lcil-1] = '\0';
-      if(contest_ini_line[lcil-2]=='\r') contest_ini_line[lcil-2] = '\0';
-      lcil = strlen(contest_ini_line);
-      if(lcil>icolon+1)
-       concat(set_screen_choices[i], contest_ini_line,
-              icolon+1, lcil-1, COPY);
-     }
+    if(fgets(contest_ini_line, socil, fp) == NULL)
+      break;
+    token = strtok(contest_ini_line, ":\r\n");
+    if (token != NULL)
+      {
+	token = strtok(NULL,":\r\n");
+	if (token != NULL) 
+	  strcpy(set_screen_choices[i], token);
+      }
    }
   if(!strcmp(set_screen_choices[1], "<NEVER>"))
    strcpy(set_screen_choices[1], dupe_bracket[0]);
   for(i=0; i<MAX_KEYER_ITEMS; i++)
    {
-    fgets(contest_ini_line, socil, fp);
-    if(feof(fp)) break;
-    icolon = kb_index (contest_ini_line, ":");
-    if(icolon>-1)
-     {
-      lcil = strlen(contest_ini_line);
-      if(contest_ini_line[lcil-1]=='\n') contest_ini_line[lcil-1] = '\0';
-      if(contest_ini_line[lcil-2]=='\r') contest_ini_line[lcil-2] = '\0';
-      lcil = strlen(contest_ini_line);
-      if(lcil>icolon+1)
-       concat(keyer_screen_choices[i], contest_ini_line,
-              icolon+1, lcil-1, COPY);
-     }
+    if(fgets(contest_ini_line, socil, fp) == NULL)
+      break;
+    token = strtok(contest_ini_line, ":\r\n");
+    if(token != NULL)
+      {
+	token = strtok(NULL,":\r\n");
+	if (token != NULL)
+	  strcpy(keyer_screen_choices[i], token);
+      }
    }
   fclose(fp);
 }
@@ -187,17 +174,14 @@
   fp = fopen(filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, "Error reading ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error reading %s", filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
   icall_count = 0;
   socl = sizeof(contest_line);
-  for( ; ; )
+  while(fgets(contest_line, socl, fp) != NULL)
    {
-    fgets(contest_line, socl, fp);
-    if(feof(fp)) break;
     icall_count++;
     fill_cr_array_all (contest_line, icall_count);
    }
@@ -257,16 +241,13 @@
   gchar filnam[13], contest_line[76];
 
   ded_num = 0;
-  strcpy(filnam, contest_file_base);
-  strcat(filnam, ".DED");
+  sprintf(filnam,"%s.DED", filnam);
   fp = fopen(filnam, "r");
   if(fp==NULL)
    return;
   socl = sizeof(contest_line);
-  for( ; ; )
+  while(fgets(contest_line, socl, fp) != NULL)
    {
-    fgets(contest_line, socl, fp);
-    if(feof(fp)) break;
     ded_num++;
     strcpy(ded_array[ded_num], contest_line);
    }
@@ -276,7 +257,7 @@
 static void read_locus_file(void)
 {
   FILE *fp;
-  gint i, j, lcil, icn, soli;
+  gint i, j, icn, soli;
   gchar filnam[13], msg[49], clat[5], clong[6];
   gchar line_in[80];
   gint n=0;
@@ -320,20 +301,14 @@
   fp = fopen(filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, "Error reading ");
-    strcat(msg, filnam);
+     snprintf(msg,sizeof(msg),"Error reading %s",filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
   soli = sizeof(line_in);
-  for( ; ; )
+  while(fgets(line_in, soli, fp) != NULL)
    {
-    fgets(line_in, soli, fp);
-    if(feof(fp)) break;
-    lcil = strlen(line_in);
-    if(line_in[lcil-1]=='\n') line_in[lcil-1] = '\0';
-    if(line_in[lcil-2]=='\r') line_in[lcil-2] = '\0';
-    lcil = strlen(line_in);
+    chomp(line_in);
     n++;
     concat(loci.locus_name[n], line_in,
            col_num[icn][0], col_num[icn][1], COPY);
@@ -376,8 +351,7 @@
   fp = fopen(filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, "Error reading ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error reading %s",filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
@@ -385,12 +359,12 @@
    contest_nc[i][0] = '\0';
   for(i=0; i<MAX_COUNTRIES; i++)
    {
-    countries.country_name[i][0] = '\0';
-    countries.country_abv[i][0] = '\0';
-    countries.country_syn[i][0] = '\0';
-    countries.continent_abv[i][0] = '\0';
-    countries.zones_in_country[i][0] = '\0';
-    countries.country_lat[i] = 0.;
+    countries.country_name[i][0] = '\0';
+    countries.country_abv[i][0] = '\0';
+    countries.country_syn[i][0] = '\0';
+    countries.continent_abv[i][0] = '\0';
+    countries.zones_in_country[i][0] = '\0';
+    countries.country_lat[i] = 0.;
     countries.country_long[i] = 0.;
    }
   for(i=0; i<6; i++)
@@ -401,13 +375,9 @@
      countries.izone_worked[i][j] = 0;
    }
   soli = sizeof(line_in);
-  for( ; ; )
+  while(fgets(line_in, soli, fp) != NULL)
    {
-    fgets(line_in, soli, fp);
-    if(feof(fp)) break;
-    lcil = strlen(line_in);
-    if(line_in[lcil-1]=='\n') line_in[lcil-1] = '\0';
-    if(line_in[lcil-2]=='\r') line_in[lcil-2] = '\0';
+    chomp(line_in);
     lcil = strlen(line_in);
     if(line_in[0]=='-')
      {
@@ -456,11 +426,11 @@
   countries.country_lat[0] = -89.;
   for(i=0; i<=n; i++)
    {
-    right_blank_unpad (countries.country_name[i]);
-    right_blank_unpad (countries.country_abv[i]);
-    right_blank_unpad (countries.country_syn[i]);
-    right_blank_unpad (countries.continent_abv[i]);
-    right_blank_unpad (countries.zones_in_country[i]);
+    right_blank_unpad (countries.country_name[i]);
+    right_blank_unpad (countries.country_abv[i]);
+    right_blank_unpad (countries.country_syn[i]);
+    right_blank_unpad (countries.continent_abv[i]);
+    right_blank_unpad (countries.zones_in_country[i]);
    }
   for(i=0; i<=notc; i++)
    {
@@ -491,16 +461,16 @@
            for(k=j; k<=n; k++)
             {
              strcpy(countries.country_name[k],
-                    countries.country_name[k+1]);
+                    countries.country_name[k+1]);
              strcpy(countries.country_abv[k],
-                    countries.country_abv[k+1]);
+                    countries.country_abv[k+1]);
              strcpy(countries.country_syn[k],
-                    countries.country_syn[k+1]);
+                    countries.country_syn[k+1]);
              strcpy(countries.continent_abv[k],
-                    countries.continent_abv[k+1]);
+                    countries.continent_abv[k+1]);
              strcpy(countries.zones_in_country[k],
-                    countries.zones_in_country[k+1]);
-             countries.country_lat[k] = countries.country_lat[k+1];
+                    countries.zones_in_country[k+1]);
+             countries.country_lat[k] = countries.country_lat[k+1];
              countries.country_long[k] = countries.country_long[k+1];
             }
            n--;
@@ -557,19 +527,14 @@
   fp = fopen(clib.filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, "Error reading ");
-    strcat(msg, clib.filnam);
+    snprintf(msg, sizeof(msg), "Error reading %s", clib.filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
   soli = sizeof(line_in);
-  for( ; ; )
+  while(fgets(line_in, soli, fp) != NULL)
    {
-    fgets(line_in, soli, fp);
-    if(feof(fp)) break;
-    lcil = strlen(line_in);
-    if(line_in[lcil-1]=='\n') line_in[lcil-1] = '\0';
-    if(line_in[lcil-2]=='\r') line_in[lcil-2] = '\0';
+    chomp(line_in);
     right_blank_pad (line_in, soli);
     lcil = strlen(line_in);
     n++;
@@ -595,9 +560,9 @@
   fclose(fp);
   for(i=0; i<=n; i++)
    {
-    right_blank_unpad (clib.call[i]);
-    right_blank_unpad (clib.country[i]);
-    right_blank_unpad (clib.section[i]);
+    right_blank_unpad (clib.call[i]);
+    right_blank_unpad (clib.country[i]);
+    right_blank_unpad (clib.section[i]);
     right_blank_unpad (clib.county[i]);
    }
   clib.number_of_calls = n+1;
@@ -606,7 +571,6 @@
 static void read_help_file(void)
 {
   FILE *fp;
-  gint lcil, soli;
   gchar filnam[13], msg[49];
   gchar line_in[80];
   gint n=-1;
@@ -622,19 +586,13 @@
   fp = fopen(filnam, "r");
   if(fp==NULL)
    {
-    strcpy(msg, "Error reading ");
-    strcat(msg, filnam);
+    snprintf(msg,sizeof(msg), "Error reading %s",filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
-  soli = sizeof(line_in);
-  for( ; ; )
+  while(fgets(line_in, sizeof(line_in), fp) != NULL)
    {
-    fgets(line_in, soli, fp);
-    if(feof(fp)) break;
-    lcil = strlen(line_in);
-    if(line_in[lcil-1]=='\n') line_in[lcil-1] = '\0';
-    if(line_in[lcil-2]=='\r') line_in[lcil-2] = '\0';
+    chomp(line_in);
     n++;
     strcpy(helpbv.help_lines[n], line_in);
    }
@@ -652,13 +610,10 @@
   fp = fopen(filnam, "w");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, filnam);
+    snprintf(msg,sizeof(msg),"Error writing %s",filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
-//  fflush(fp);
-//  fsync(fileno(fp));
   fclose(fp);
 }
 
@@ -672,11 +627,7 @@
    concat(filnam_hold, filnam, 0, idot-1, COPY);
   else
    strcpy(filnam_hold, filnam);
-  strcpy(msg, "cp ");
-  strcat(msg, filnam);
-  strcat(msg, " ");
-  strcat(msg, filnam_hold);
-  strcat(msg, ".BAK");
+  snprintf(msg, sizeof(msg), "cp %s %s.BAK",filnam,filnam_hold);
   icopy = system(msg);
   return icopy;
 }
@@ -687,13 +638,11 @@
   gchar filnam[13], msg[49], contest_ini_line[76];
   gint i;
 
-  strcpy(filnam, contest_file_base);
-  strcat(filnam, ".INI");
+  snprintf(filnam, sizeof(filnam), "%s.INI", contest_file_base);
   fp = fopen(filnam, "w");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error writing %s", filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
@@ -703,8 +652,7 @@
     left_blank_unpad(contest_ini_line);
     strcat(contest_ini_line, ":");
     strcat(contest_ini_line, init_screen_choices[i]);
-    add_eol_chars (contest_ini_line);
-    fputs(contest_ini_line, fp);
+    fprintf(fp,"%s\n",contest_ini_line);
    }
   for(i=0; i<MAX_SET_ITEMS; i++)
    {
@@ -712,8 +660,7 @@
     left_blank_unpad(contest_ini_line);
     strcat(contest_ini_line, ":");
     strcat(contest_ini_line, set_screen_choices[i]);
-    add_eol_chars (contest_ini_line);
-    fputs(contest_ini_line, fp);
+    fprintf(fp,"%s\n",contest_ini_line);
    }
   for(i=0; i<MAX_KEYER_ITEMS; i++)
    {
@@ -721,8 +668,7 @@
     left_blank_unpad(contest_ini_line);
     strcat(contest_ini_line, ":");
     strcat(contest_ini_line, keyer_screen_choices[i]);
-    add_eol_chars (contest_ini_line);
-    fputs(contest_ini_line, fp);
+    fprintf(fp,"%s\n",contest_ini_line);
    }
   fflush(fp);
   fsync(fileno(fp));
@@ -738,8 +684,7 @@
   fp = fopen(filnam, "a");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error writing %s", filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
@@ -757,21 +702,18 @@
   FILE *fp;
   gchar filnam[13], msg[49], contest_line[76];
 
-  strcpy(filnam, contest_file_base);
-  strcat(filnam, ".DED");
+  snprintf(filnam, sizeof(filnam), "%s.DED", contest_file_base);
   fp = fopen(filnam, "a");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error writing %s",filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
   strcpy(contest_line, cmd);
-  add_eol_chars (contest_line);
-  fputs(contest_line, fp);
+  fprintf(fp,"%s\n",contest_line);
   make_contest_line (contest_line, qnum);
-  fputs(contest_line, fp);
+  fprintf(fp, "%s\n", contest_line);
   fflush(fp);
   fsync(fileno(fp));
   fclose(fp);
@@ -789,8 +731,7 @@
   fp = fopen(filnam, "w");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, filnam);
+    snprintf(msg, sizeof(msg), "Error writing %s", filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
@@ -813,8 +754,7 @@
   fp = fopen(clib.filnam, "w");
   if(fp==NULL)
    {
-    strcpy(msg, "Error writing ");
-    strcat(msg, clib.filnam);
+    snprintf(msg, sizeof(msg),"Error writing %s",clib.filnam);
     rw_error_box (main_drawing_area, msg);
     return;
    }
@@ -856,8 +796,7 @@
     strcat(library_line, " ");
     strcat(library_line, clib.check[9999]);
     right_blank_unpad(library_line);
-    add_eol_chars (library_line);
-    fputs(library_line, fp);
+    fprintf(fp,"%s\n",library_line);
    }
   fflush(fp);
   fsync(fileno(fp));
@@ -867,24 +806,35 @@
 static gint process_tmp_file(const gchar *filnam)
 {
   FILE *fp;
+  FILE *pfp;
   gchar filnam_hold[14], psc_line[81], system_line[41];
   gint ami_running=-1;
 
-  strcpy(filnam_hold, filnam);
-  strcat(filnam_hold, ".tmp");
-  strcpy(system_line, "ps -C ");
-  strcat(system_line, filnam);
-  strcat(system_line, " | sort > ");
-  strcat(system_line, filnam_hold);
-  system(system_line);
-  fp = fopen(filnam_hold, "r");
-  if(fp!=NULL)
+  snprintf(system_line, sizeof(system_line) - 1, "ps|grep %s|grep -v grep",
+	 filnam);
+  pfp = popen(system_line, "r");
+  if(pfp!=NULL)
    {
-    fgets(psc_line, sizeof(psc_line), fp);
+    fgets(psc_line, sizeof(psc_line), pfp);
     if(kb_index (psc_line, filnam)>-1)
      ami_running = 0;
-    fclose(fp);
-    remove(filnam_hold);
+    fclose(pfp);
    }
   return ami_running;
 }
+
+static char*
+chomp(char *s)
+{
+  char *p;
+
+  p = strchr(s, '\n');
+  if (p != NULL)
+    {
+      *p = '\0';
+      p--;
+      if (*p == '\r')
+	*p = '\0';
+    }
+}
+    
