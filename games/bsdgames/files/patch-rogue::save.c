$FreeBSD$

--- rogue/save.c	30 Nov 1999 03:49:27 -0000	1.6
+++ rogue/save.c	21 Aug 2003 20:03:37 -0000
@@ -63,8 +63,6 @@
 
 extern boolean detect_monster;
 extern short cur_level, max_level;
-extern char hunger_str[];
-extern char login_name[];
 extern short party_room;
 extern short foods;
 extern boolean is_wood[];
@@ -102,15 +100,23 @@
 {
 	FILE *fp;
 	int file_id;
-	char name_buffer[80];
+	char *name_buffer;
+	size_t len;
 	char *hptr;
 	struct rogue_time rt_buf;
 
 	if (sfile[0] == '~') {
 		if (hptr = md_getenv("HOME")) {
-			(void) strcpy(name_buffer, hptr);
-			(void) strcat(name_buffer, sfile+1);
-			sfile = name_buffer;
+			len = strlen(hptr) + strlen(sfile);
+			name_buffer = md_malloc(len);
+			if (name_buffer == NULL) {
+				message("out of memory for save file name", 0);
+				sfile = error_file;
+			} else {
+				(void) strcpy(name_buffer, hptr);
+				(void) strcat(name_buffer, sfile+1);
+				sfile = name_buffer;
+			}
 		}
 	}
 	/* revoke */
@@ -199,10 +205,10 @@
 	r_read(fp, (char *) &detect_monster, sizeof(detect_monster));
 	r_read(fp, (char *) &cur_level, sizeof(cur_level));
 	r_read(fp, (char *) &max_level, sizeof(max_level));
-	read_string(hunger_str, fp);
+	read_string(hunger_str, fp, sizeof hunger_str);
 
-	(void) strcpy(tbuf, login_name);
-	read_string(login_name, fp);
+	(void) strlcpy(tbuf, login_name, sizeof tbuf);
+	read_string(login_name, fp, sizeof login_name);
 	if (strcmp(tbuf, login_name)) {
 		clean_up("you're not the original player");
 	}
@@ -345,7 +351,7 @@
 			r_read(fp, (char *) &(id_table[i].value), sizeof(short));
 			r_read(fp, (char *) &(id_table[i].id_status),
 				sizeof(unsigned short));
-			read_string(id_table[i].title, fp);
+			read_string(id_table[i].title, fp, MAX_ID_TITLE_LEN);
 		}
 	}
 }
@@ -362,13 +368,16 @@
 	r_write(fp, s, n);
 }
 
-read_string(s, fp)
+read_string(s, fp, len)
 char *s;
 FILE *fp;
+size_t len;
 {
 	short n;
 
 	r_read(fp, (char *) &n, sizeof(short));
+	if (n > len)
+		clean_up("read_string: corrupt game file");
 	r_read(fp, s, n);
 	xxxx(s, n);
 }
