--- elogs.c.orig	2007-11-22 13:24:56.000000000 -0500
+++ elogs.c	2007-11-22 14:19:17.000000000 -0500
@@ -56,7 +56,6 @@
   gchar locus_line[4], ops_line[45];
   gint iqsos[2] = {0, 0}, idupes[2] = {0, 0}, ipoints[2] = {0, 0};
   gint mults[2] = {0, 0}, izones[2] = {0, 0}, nlw[2] = {0, 0};
-  gchar skip_line[3] = {'\r', '\n', '\0'};
   const gchar *stpr = "State/Province: ";
   const gchar *category_choices[8] = {"Single Operator",
                "Single Operator, Assisted",
@@ -106,9 +105,7 @@
   concat(line_out, cr_array[1].date, 4, 5, !COPY);
   strcat(line_out, " ");
   strcat(line_out, select_contest_items[isel_contest]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Call: ");
   strcpy(station, init_screen_choices[0]);
@@ -169,9 +166,7 @@
      strcat(line_out, "Section: ___");
      break;
    }
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp, "%s\n\n", line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Category: ");
   for(i=0; i<8; i++)
@@ -192,16 +187,12 @@
       strcpy(ops_line, "");
      break;
     }
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp, "%s\n\n", line_out);
   if(strlen(ops_line))
    {
     concat(line_out, blank80, 0, margin, COPY);
     strcat(line_out, ops_line);
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
-    fputs(skip_line, fp);
+    fprintf(fp, "%s\n\n", line_out);
    }
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Mode: ");
@@ -211,24 +202,18 @@
   strcat(line_out, power_line);
   concat(line_out, blank80, 0, 9, !COPY);
   strcat(line_out, "Hours of Operation: __");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
-  fputs(skip_line, fp);
+  fprintf(fp, "%s\n\n\n", line_out);
   switch (isel_contest)
    {
     case DX :
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               Net        QSO        Country        Claimed");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               QSOs      Points       Mults          Score");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp, "%s\n\n", line_out);
      for(i=0; i<6; i++)
       {
        concat(line_out, blank80, 0, margin+2, COPY);
@@ -247,10 +232,9 @@
        int_to_comma (score_mb.mults[mode][i], sum_line);
        left_blank_pad (sum_line, sizeof(sum_line));
        strcat(line_out, sum_line);
-       add_eol_chars (line_out);
-       fputs(line_out, fp);
+       fprintf(fp,"%s\n", line_out);
       }
-     fputs(skip_line, fp);
+     fprintf(fp,"\n");
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "All Bands");
      concat(line_out, blank80, 0, 3, !COPY);
@@ -269,21 +253,17 @@
      int_to_comma (ipoints[mode]*mults[mode], score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
     case FD :
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               Net CW      Net PH");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "                QSOs        QSOs");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      for(i=0; i<6; i++)
       {
        concat(line_out, blank80, 0, margin+2, COPY);
@@ -297,10 +277,9 @@
        int_to_comma (score_mb.qsos[PH][i]-score_mb.dupes[PH][i], sum_line);
        left_blank_pad (sum_line, sizeof(sum_line));
        strcat(line_out, sum_line);
-       add_eol_chars (line_out);
-       fputs(line_out, fp);
+       fprintf(fp,"%s\n",line_out);
       }
-     fputs(skip_line, fp);
+     fprintf(fp,"\n");
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "All Bands");
      concat(line_out, blank80, 0, 4, !COPY);
@@ -315,8 +294,7 @@
      int_to_comma (iqsos[CW]-idupes[CW]+iqsos[PH]-idupes[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "QSO Points");
      concat(line_out, blank80, 0, 3, !COPY);
@@ -331,8 +309,7 @@
      int_to_comma (ipoints[CW]+ipoints[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Power Multiplier");
      concat(line_out, blank80, 0, 21, !COPY);
@@ -345,43 +322,34 @@
      int_to_comma (pm, sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "QSO Score");
      concat(line_out, blank80, 0, 28, !COPY);
      int_to_comma (pm*(ipoints[CW]+ipoints[PH]), sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Bonus Points");
      concat(line_out, blank80, 0, 24, !COPY);
      concat(line_out, under_line, 0, 6, !COPY);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Claimed Score");
      concat(line_out, blank80, 0, 23, !COPY);
      concat(line_out, under_line, 0, 6, !COPY);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
     case WPX :
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               Net        QSO        Prefix         Claimed");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               QSOs      Points       Mults          Score");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      for(i=0; i<6; i++)
       {
        concat(line_out, blank80, 0, margin+2, COPY);
@@ -400,10 +368,9 @@
        int_to_comma (score_mb.mults[mode][i], sum_line);
        left_blank_pad (sum_line, sizeof(sum_line));
        strcat(line_out, sum_line);
-       add_eol_chars (line_out);
-       fputs(line_out, fp);
+       fprintf(fp,"%s\n",line_out);
       }
-     fputs(skip_line, fp);
+     fprintf(fp,"\n");
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "All Bands");
      concat(line_out, blank80, 0, 3, !COPY);
@@ -422,8 +389,7 @@
      int_to_comma (ipoints[mode]*mults[mode], score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
     case CQP :
      break;
@@ -431,14 +397,11 @@
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "              Net       QSO       Country     Zone       Claimed");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "              QSOs     Points      Mults      Mults       Score");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      for(i=0; i<6; i++)
       {
        concat(line_out, blank80, 0, margin+2, COPY);
@@ -461,10 +424,9 @@
        int_to_comma (score_mb.zones[mode][i], sum_line);
        left_blank_pad (sum_line, sizeof(sum_line));
        strcat(line_out, sum_line);
-       add_eol_chars (line_out);
-       fputs(line_out, fp);
+       fprintf(fp,"%s\n",line_out);
       }
-     fputs(skip_line, fp);
+     fprintf(fp,"\n");
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "All Bands");
      concat(line_out, blank80, 0, 2, !COPY);
@@ -487,22 +449,17 @@
      int_to_comma (ipoints[mode]*(mults[mode]+izones[mode]), score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
     case SS :
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               Net        QSO        Section        Claimed");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               QSOs      Points       Mults          Score");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      concat(line_out, blank80, 0, 12, !COPY);
      int_to_comma (iqsos[mode]-idupes[mode], sum_line);
@@ -520,21 +477,15 @@
      int_to_comma (ipoints[mode]*mults[mode], score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "                     ARRL Sections Check-Off List");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "               (Sections worked marked with an asterisk)");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      for(j=1; j<11; j++)
       {
        concat(line_out, blank80, 0, margin, COPY);
@@ -554,8 +505,7 @@
          strcat(line_out, mult_line);
          strcat(line_out, locus_line);
         }
-       add_eol_chars (line_out);
-       fputs(line_out, fp);
+       fprintf(fp,"%s\n",line_out);
       }
      break;
     case A160 :
@@ -565,18 +515,14 @@
      int_to_comma (iqsos[CW]-idupes[CW], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "QSO Points");
      concat(line_out, blank80, 0, 9, !COPY);
      int_to_comma (ipoints[CW], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "States/Prov");
      for(i=0; i<2; i++)
@@ -587,9 +533,7 @@
      int_to_comma (nlw[CW], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Countries");
      nlw[0] = 0;
@@ -602,18 +546,14 @@
      int_to_comma (nlw[CW], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Total Mults");
      concat(line_out, blank80, 0, 8, !COPY);
      int_to_comma (mults[CW], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Claimed Score");
      concat(line_out, blank80, 0, 1, !COPY);
@@ -621,16 +561,13 @@
                    score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
     case TEN :
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out,
       "                        CW          Phone           All");
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "QSOs");
      concat(line_out, blank80, 0, 15, !COPY);
@@ -645,9 +582,7 @@
      int_to_comma (iqsos[CW]-idupes[CW]+iqsos[PH]-idupes[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "QSO Points");
      concat(line_out, blank80, 0, 9, !COPY);
@@ -662,9 +597,7 @@
      int_to_comma (ipoints[CW]+ipoints[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "States/Prov");
      for(i=0; i<2; i++)
@@ -683,9 +616,7 @@
      int_to_comma (nlw[CW]+nlw[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Countries");
      nlw[0] = 0;
@@ -706,9 +637,7 @@
      int_to_comma (nlw[CW]+nlw[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Total Mults");
      concat(line_out, blank80, 0, 8, !COPY);
@@ -723,9 +652,7 @@
      int_to_comma (mults[CW]+mults[PH], sum_line);
      left_blank_pad (sum_line, sizeof(sum_line));
      strcat(line_out, sum_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
-     fputs(skip_line, fp);
+     fprintf(fp,"%s\n\n",line_out);
      concat(line_out, blank80, 0, margin, COPY);
      strcat(line_out, "Claimed Score");
      concat(line_out, blank80, 0, 30, !COPY);
@@ -733,76 +660,51 @@
                    score_line);
      left_blank_pad (score_line, sizeof(score_line));
      strcat(line_out, score_line);
-     add_eol_chars (line_out);
-     fputs(line_out, fp);
+     fprintf(fp,"%s\n",line_out);
      break;
    }
-  fputs(skip_line, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"\n\n");
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out,
    "Club Participation?  ( ) Yes  ( ) No   If yes, print name below.");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Name of Club: ");
   concat(line_out, under_line, 0, 49, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Rigs: ");
   concat(line_out, under_line, 0, 57, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   concat(line_out, under_line, 0, 63, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Antennas: ");
   concat(line_out, under_line, 0, 53, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   concat(line_out, under_line, 0, 63, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Remarks: ");
   concat(line_out, under_line, 0, 54, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   concat(line_out, under_line, 0, 63, !COPY);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n%s\n\n",line_out,line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out,
    "This is to certify that in this contest I have operated my");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out,
    "transmitter within the limitations of my license and have");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out,
    "observed fully the rules and regulations of the contest.");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, "Date ");
   concat(line_out, under_line, 0, 9, !COPY);
@@ -810,25 +712,20 @@
   concat(line_out, under_line, 0, 22, !COPY);
   strcat(line_out, ", ");
   strcat(line_out, init_screen_choices[1]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(skip_line, fp);
+  fprintf(fp,"%s\n\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, init_screen_choices[2]);
   strcat(line_out, ", ");
   strcat(line_out, init_screen_choices[1]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, init_screen_choices[3]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   if(strlen(init_screen_choices[4]))
    {
     concat(line_out, blank80, 0, margin, COPY);
     strcat(line_out, init_screen_choices[4]);
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
+    fprintf(fp,"%s\n",line_out);
    }
   concat(line_out, blank80, 0, margin, COPY);
   strcat(line_out, init_screen_choices[5]);
@@ -836,8 +733,7 @@
   strcat(line_out, init_screen_choices[6]);
   strcat(line_out, " ");
   strcat(line_out, init_screen_choices[7]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   fflush(fp);
   fsync(fileno(fp));
   fclose(fp);
@@ -852,7 +748,6 @@
   gchar station[14], mode_line[6], dupe_line[2];
   gchar title_line[74], header_line1[74], call_hold[14], call_fill[14];
   gint iqsos[2] = {0, 0}, max_lines=54;
-  gchar skip_line[3] = {'\r', '\n', '\0'};
   gchar form_feed[2] = {'\f', '\0'};
 
   fp = fopen(filnam, "w");
@@ -924,10 +819,7 @@
           int_to_char (npages, npages_char);
           left_blank_pad (npages_char, sizeof(npages_char));
           strcat(line_out, npages_char);
-          add_eol_chars (line_out);
-          fputs(line_out, fp);
-          fputs(skip_line, fp);
-          fputs(skip_line, fp);
+          fprintf(fp,"%s\n\n\n",line_out);
          }
         if(margin || new_mb)
          {
@@ -936,9 +828,7 @@
           strcat(line_out, header_line1);
           strcat(line_out, bandw[i]);
           strcat(line_out, mode_char[j]);
-          add_eol_chars (line_out);
-          fputs(line_out, fp);
-          fputs(skip_line, fp);
+	  fprintf(fp,"%s\n\n",line_out);
          }
         strcpy(call_hold, "");
         ic = 0;
@@ -973,8 +863,7 @@
              ic %= 4;
              if(!ic)
               {
-               add_eol_chars (line_out);
-               fputs(line_out, fp);
+	       fprintf(fp,"%s\n",line_out);
                idl++;
               }
             }
@@ -986,14 +875,13 @@
          }
         if(ic)
          {
-          add_eol_chars (line_out);
-          fputs(line_out, fp);
+	  fprintf(fp,"%s\n",line_out);
          }
         if(margin)
          fputs(form_feed, fp);
        }
       if(!margin)
-       fputs(skip_line, fp);
+	fprintf(fp,"\n");
      }
   fflush(fp);
   fsync(fileno(fp));
@@ -1014,7 +902,6 @@
   gchar hl2_zone[7], hl2_country[10];
   gint iqsos[2] = {0, 0}, nqsos[2] = {0, 0};
   gint nzones[2] = {0, 0}, nmults[2] = {0, 0}, npts[2] = {0, 0};
-  gchar skip_line[3] = {'\r', '\n', '\0'};
   gchar form_feed[2] = {'\f', '\0'};
 
   fp = fopen(filnam, "w");
@@ -1154,19 +1041,13 @@
       strcat(line_out, ipage_char);
       strcat(line_out, " of ");
       strcat(line_out, npages_char);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
-      fputs(skip_line, fp);
-      fputs(skip_line, fp);
+      fprintf(fp,"%s\n\n\n",line_out);
       concat(line_out, blank80, 0, margin, COPY);
       strcat(line_out, header_line1);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
+      fprintf(fp,"%s\n",line_out);
       concat(line_out, blank80, 0, margin, COPY);
       strcat(line_out, header_line2);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
-      fputs(skip_line, fp);
+      fprintf(fp,"%s\n\n",line_out);
      }
     for(i=(ipage-1)*50+1; i<=ipage*50; i++)
      {
@@ -1361,11 +1242,10 @@
         npts[0] += atoi(cr_array[i].points);
         npts[1] += atoi(cr_array[i].points);
         strcat(line_out, cr_array[i].points);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
       else if(margin)
-       fputs(skip_line, fp);
+	fprintf(fp,"\n");
      }
     if(margin)
      {
@@ -1385,7 +1265,7 @@
       left_blank_pad (footer2_vars[2], sizeof(footer2_vars[2]));
       int_to_char (npts[1], footer2_vars[3]);
       left_blank_pad (footer2_vars[3], sizeof(footer2_vars[3]));
-      fputs(skip_line, fp);
+      fprintf(fp,"\n");
       concat(line_out, blank80, 0, margin, COPY);
       strcat(line_out, footer_line1);
       concat(line_out, blank80, 0, 9, !COPY);
@@ -1402,8 +1282,7 @@
        strcat(line_out, footer1_vars[2]);
       concat(line_out, blank80, 0, 3, !COPY);
       strcat(line_out, footer1_vars[3]);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
+      fprintf(fp,"%s\n",line_out);
       concat(line_out, blank80, 0, margin, COPY);
       strcat(line_out, footer_line2);
       concat(line_out, blank80, 0, 9, !COPY);
@@ -1420,9 +1299,7 @@
        strcat(line_out, footer2_vars[2]);
       concat(line_out, blank80, 0, 3, !COPY);
       strcat(line_out, footer2_vars[3]);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
-      fputs(form_feed, fp);
+      fprintf(fp,"%s\f\n",line_out);
      }
    }
   fflush(fp);
@@ -1439,7 +1316,6 @@
   gchar title_line[74], header_line1[74];
   gint max_lines=54;
   gint iqsos[2] = {0, 0};
-  gchar skip_line[3] = {'\r', '\n', '\0'};
   gchar form_feed[2] = {'\f', '\0'};
 
   fp = fopen(filnam, "w");
@@ -1499,15 +1375,10 @@
       strcat(line_out, ipage_char);
       strcat(line_out, " of ");
       strcat(line_out, npages_char);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
-      fputs(skip_line, fp);
-      fputs(skip_line, fp);
+      fprintf(fp,"%s\n\n\n",line_out);
       concat(line_out, blank80, 0, margin, COPY);
       strcat(line_out, header_line1);
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
-      fputs(skip_line, fp);
+      fprintf(fp,"%s\n\n",line_out);
      }
     jfirst = (ipage-1)*max_lines*10+1;
     jlast = ipage*max_lines*10<px_tree.npx ?
@@ -1525,14 +1396,12 @@
       ic %= 10;
       if(!ic)
        {
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
      }
     if(ic)
      {
-      add_eol_chars (line_out);
-      fputs(line_out, fp);
+      fprintf(fp,"%s\n",line_out);
      }
     if(margin)
      fputs(form_feed, fp);
@@ -1662,8 +1531,7 @@
   strcat(category_cab, " ");
   strcat(category_cab, mode_cab);
   strcpy(line_out, "START-OF-LOG: 2.0");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   if(strlen(section)>0)
    {
    strcpy(line_out, "ARRL-SECTION: ");
@@ -1671,80 +1539,45 @@
    }
   else
    strcpy(line_out, "ARRL-SECTION:");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "CALLSIGN: ");
   strcat(line_out, init_screen_choices[0]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "CATEGORY: ");
   strcat(line_out, category_cab);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   if(isel_contest==WPX && !strcmp(init_screen_choices[11], "<SO-TRI/SE>"))
    {
     strcpy(line_out, "CATEGORY-OVERLAY: ");
     strcat(line_out, "TB-WIRES");
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
+    fprintf(fp,"%s\n",line_out);
    }
   strcpy(line_out, "CLAIMED-SCORE: ");
   strcat(line_out, score_cab);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "CLUB:");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "CONTEST: ");
   strcat(line_out, contest_cab);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "NAME: ");
   strcat(line_out, init_screen_choices[2]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
   strcpy(line_out, "ADDRESS: ");
   strcat(line_out, init_screen_choices[3]);
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  if(strlen(init_screen_choices[4]))
-   {
-    strcpy(line_out, "ADDRESS: ");
-    strcat(line_out, init_screen_choices[4]);
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
-    strcpy(line_out, "ADDRESS: ");
-    strcat(line_out, init_screen_choices[5]);
-    strcat(line_out, ", ");
-    strcat(line_out, init_screen_choices[6]);
-    strcat(line_out, " ");
-    strcat(line_out, init_screen_choices[7]);
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
-   }
-  else
-   {
-    strcpy(line_out, "ADDRESS: ");
-    strcat(line_out, init_screen_choices[5]);
-    strcat(line_out, ", ");
-    strcat(line_out, init_screen_choices[6]);
-    strcat(line_out, " ");
-    strcat(line_out, init_screen_choices[7]);
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
-    strcpy(line_out, "ADDRESS:");
-    add_eol_chars (line_out);
-    fputs(line_out, fp);
-   }
-  strcpy(line_out, "OPERATORS:");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  strcpy(line_out, "SOAPBOX:");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
-  fputs(line_out, fp);
-  fputs(line_out, fp);
-  fputs(line_out, fp);
+  fprintf(fp,"%s\n",line_out);
+  if(strlen(init_screen_choices[4])!=0)
+    fprintf(fp,"ADDRESS: %s\n",
+	    init_screen_choices[4]);
+  fprintf(fp,"ADDRESS: %s, %s %s\n",init_screen_choices[5],
+	  init_screen_choices[6],init_screen_choices[7]);
+
+  fprintf(fp,"OPERATORS:\n");
+  fprintf(fp,"SOAPBOX:\n");
+  fprintf(fp,"SOAPBOX:\n");
+  fprintf(fp,"SOAPBOX:\n");
+  fprintf(fp,"SOAPBOX:\n");
+  fprintf(fp,"SOAPBOX:\n");
   switch (isel_contest)
    {
     case WPX :
@@ -1790,8 +1623,7 @@
         strcat(line_out, exch_rcvd_cab);
         strcat(line_out, " ");
         strcat(line_out, cr_array[i].tx);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
      break;
     case FD :
@@ -1836,8 +1668,7 @@
         strcat(line_out, exch_rcvd_cab);
         strcat(line_out, " ");
         strcat(line_out, cr_array[i].tx);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
      break;
     case CQP :
@@ -1892,8 +1723,7 @@
         strcat(line_out, ck_rcvd_cab);
         strcat(line_out, " ");
         strcat(line_out, rst_rcvd_cab);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
      break;
     case A160 :
@@ -1947,8 +1777,7 @@
         strcat(line_out, exch_rcvd_cab);
         strcat(line_out, " ");
         strcat(line_out, cr_array[i].tx);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
      break;
     default :
@@ -1995,13 +1824,10 @@
         strcat(line_out, exch_rcvd_cab);
         strcat(line_out, " ");
         strcat(line_out, cr_array[i].tx);
-        add_eol_chars (line_out);
-        fputs(line_out, fp);
+	fprintf(fp,"%s\n",line_out);
        }
    }
-  strcpy(line_out, "END-OF-LOG:");
-  add_eol_chars (line_out);
-  fputs(line_out, fp);
+  fprintf(fp,"END-OF-LOG:\n");
   fflush(fp);
   fsync(fileno(fp));
   fclose(fp);
