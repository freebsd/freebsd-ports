--- src/audio.c.orig	Wed Apr  5 03:16:50 2006
+++ src/audio.c	Mon May  8 14:31:45 2006
@@ -30,6 +30,8 @@
 #include "onechar.h"
 
 extern char sc_device[];
+char soundlog_dir[FILENAME_MAX];
+char *home;
 
 int afd;
 
@@ -668,10 +670,8 @@
 				mvprintw(15,20, "recording %s", ph_message[0]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");			// (W9WI)
- 				strcat(commands, ph_message[0]);
+				snprintf(commands,sizeof(commands), "rec -w -w 8000 -d %s %s",
+					sc_device, ph_message[0]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -680,21 +680,16 @@
 				mvprintw(16,20, "");
 				refresh();
 
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
-				strcat(commands, " ");			// (W9WI)
-				strcat(commands, ph_message[1]);
-				system (commands);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[1]);
 				runnit = 0;
 				break;
 			case 131 :
 				mvprintw(15,20, "recording %s", ph_message[2]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");			// (W9WI)
-				strcat(commands, ph_message[2]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[2]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -702,10 +697,8 @@
 				mvprintw(15,20, "recording %s", ph_message[3]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
-				strcat(commands, " ");			// (W9WI)
-				strcat(commands, ph_message[3]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[3]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -713,10 +706,8 @@
 				mvprintw(15,20, "recording %s", ph_message[4]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[4]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[4]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -724,10 +715,8 @@
 				mvprintw(15,20, "recording %s", ph_message[5]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[5]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[5]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -735,10 +724,8 @@
 				mvprintw(15,20, "recording %s", ph_message[6]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[6]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[6]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -746,10 +733,8 @@
 				mvprintw(15,20, "recording %s", ph_message[7]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[7]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[7]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -757,10 +742,8 @@
 				mvprintw(15,20, "recording %s", ph_message[8]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[8]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[8]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -768,10 +751,8 @@
 				mvprintw(15,20, "recording %s", ph_message[9]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[9]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[9]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -779,10 +760,8 @@
 				mvprintw(15,20, "recording %s", ph_message[10]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[10]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[10]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -790,10 +769,8 @@
 				mvprintw(15,20, "recording %s", ph_message[11]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[11]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[11]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -802,10 +779,8 @@
 				mvprintw(15,20, "recording %s", ph_message[12]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[12]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[12]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -814,10 +789,8 @@
 				mvprintw(15,20, "recording %s", ph_message[13]);
 				mvprintw(16,20, "");
 				refresh();
-				strcpy(commands,"rec -w -r 8000 -d ");
-				strcat(commands, sc_device);
- 				strcat(commands, " ");				// (W9WI)
-				strcat(commands, ph_message[13]);
+				snprintf(commands,sizeof(commands),"rec -w -r 8000 -d %s %s",
+					sc_device, ph_message[13]);
 				system (commands);
 				runnit = 0;
 				break;
@@ -840,7 +813,13 @@
 				runnit = 0;
 				break;
 			case '3' :
- 				sounddir = opendir("$HOME/tlf/soundlogs/");		// (W9WI)
+				if ((home = getenv("HOME")) != NULL) {
+				 	snprintf(soundlog_dir,sizeof(soundlog_dir),
+						"%s/tlf/soundlogs/", home);
+	 				sounddir = opendir(soundlog_dir);
+				} else
+					sounddir = NULL;
+
 
 				if (sounddir == NULL) break;
 
