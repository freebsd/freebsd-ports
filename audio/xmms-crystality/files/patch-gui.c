--- gui.c.orig	Wed Oct 15 15:25:32 2003
+++ gui.c	Wed Oct 15 15:25:55 2003
@@ -25,28 +25,28 @@
 #include "crystality.h"
 
 static const char about_text[] =
-"Crystality Plugin v0.92
-
-Bandwidth Extender, Harmonic Booster and 3D Echo
-You will need a good stereo and a good ear to notice quality
-improvement, otherwise this is not for you.  This plugin tries
-to patch mp3 format flaws, not poor audio hardware!
-For more info see README file!\n
-Copyright (C) 2001 Rafal Bosak <gyver@fanthom.irc.pl>
-
-This program is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2 of the License, or
-(at your option) any later version.
-
-This program is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
-
-You should have received a copy of the GNU General Public License
-along with this program; if not, write to the Free Software
-Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+"Crystality Plugin v0.92\n\
+\n\
+Bandwidth Extender, Harmonic Booster and 3D Echo\n\
+You will need a good stereo and a good ear to notice quality\n\
+improvement, otherwise this is not for you.  This plugin tries\n\
+to patch mp3 format flaws, not poor audio hardware!\n\
+For more info see README file!\n\n\
+Copyright (C) 2001 Rafal Bosak <gyver@fanthom.irc.pl>\n\
+\n\
+This program is free software; you can redistribute it and/or modify\n\
+it under the terms of the GNU General Public License as published by\n\
+the Free Software Foundation; either version 2 of the License, or\n\
+(at your option) any later version.\n\
+\n\
+This program is distributed in the hope that it will be useful,\n\
+but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
+GNU General Public License for more details.\n\
+\n\
+You should have received a copy of the GNU General Public License\n\
+along with this program; if not, write to the Free Software\n\
+Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA\n\
 ";
 
 GtkWidget *conf_dialog = NULL, *about_dialog = NULL;
