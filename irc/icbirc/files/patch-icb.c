--- icb.c.orig	Fri Feb 27 10:17:09 2004
+++ icb.c	Wed Jan  3 06:06:20 2007
@@ -40,8 +40,8 @@
 
 extern int	 sync_write(int, const char *, int);
 
-static unsigned char	 icb_args(const char *, unsigned char, char [255][255]);
-static void		 icb_cmd(const char *, unsigned char, int);
+static unsigned char	 icb_args(const unsigned char *, unsigned char, char [255][255]);
+static void		 icb_cmd(const unsigned char *, unsigned char, int);
 static void		 icb_ico(int, const char *);
 static void		 icb_iwl(int, const char *, const char *, long,
 			    long, const char *, const char *);
@@ -108,7 +108,7 @@
  */
 
 void
-scan(const char **s, char *d, size_t siz, const char *skip, const char *term)
+scan(const unsigned char **s, char *d, size_t siz, const char *skip, const char *term)
 {
 	while (**s && strchr(skip, **s) != NULL)
 		(*s)++;
@@ -149,7 +149,7 @@
 }
 
 static unsigned char
-icb_args(const char *data, unsigned char len, char args[255][255])
+icb_args(const unsigned char *data, unsigned char len, char args[255][255])
 {
 	unsigned char i = 0, j = 0, k = 0;
 
@@ -175,10 +175,10 @@
 }
 
 static void
-icb_cmd(const char *cmd, unsigned char len, int fd)
+icb_cmd(const unsigned char *cmd, unsigned char len, int fd)
 {
 	char args[255][255];
-	const char *a = args[1];
+	const unsigned char *a = (unsigned char *)args[1];
 	unsigned char i, j;
 	char s[8192];
 
@@ -244,7 +244,7 @@
 			char old_nick[256], new_nick[256];
 
 			scan(&a, old_nick, sizeof(old_nick), " ", " ");
-			if (strncmp(a, " changed nickname to ", 21))
+			if (strncmp((const char *)a, " changed nickname to ", 21))
 				return;
 			a += 21;
 			scan(&a, new_nick, sizeof(new_nick), " ", " ");
@@ -258,7 +258,7 @@
 			char nick[256], topic[256];
 
 			scan(&a, nick, sizeof(nick), " ", " ");
-			if (strncmp(a, " changed the topic to \"", 23))
+			if (strncmp((const char *)a, " changed the topic to \"", 23))
 				return;
 			a += 23;
 			scan(&a, topic, sizeof(topic), "", "\"");
@@ -269,13 +269,13 @@
 			char old_mod[256], new_mod[256];
 
 			scan(&a, old_mod, sizeof(old_mod), " ", " ");
-			if (!strncmp(a, " has passed moderation to ", 26)) {
+			if (!strncmp((const char *)a, " has passed moderation to ", 26)) {
 				a += 26;
 				scan(&a, new_mod, sizeof(new_mod), " ", " ");
 				snprintf(s, sizeof(s),
 				    ":%s MODE %s -o+o %s %s\r\n",
 				    old_mod, irc_channel, old_mod, new_mod);
-			} else if (!strcmp(a, " is now mod.")) {
+			} else if (!strcmp((const char *)a, " is now mod.")) {
 				snprintf(s, sizeof(s),
 				    ":%s MODE %s +o %s\r\n",
 				    icb_hostid, irc_channel, old_mod);
@@ -287,7 +287,7 @@
 			char nick[256];
 
 			scan(&a, nick, sizeof(nick), " ", " ");
-			if (strcmp(a, " was booted."))
+			if (strcmp((const char *)a, " was booted."))
 				return;
 			snprintf(s, sizeof(s), ":%s KICK %s %s :booted\r\n",
 			    icb_moderator, irc_channel, nick);
@@ -498,7 +498,7 @@
 		cmd[off++] = 0;
 		cmd[0] = off - 1;
 		/* cmd[0] <= MAX_MSG_SIZE */
-		sync_write(fd, cmd, off);
+		sync_write(fd, (const char *)cmd, off);
 	}
 }
 
@@ -523,7 +523,7 @@
 		cmd[off++] = 0;
 		cmd[0] = off - 1;
 		/* cmd[0] <= MAX_MSG_SIZE */
-		sync_write(fd, cmd, off);
+		sync_write(fd, (const char *)cmd, off);
 	}
 }
 
