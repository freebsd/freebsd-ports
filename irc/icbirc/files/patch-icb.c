--- icb.c.orig	2015-08-21 19:01:12 UTC
+++ icb.c
@@ -30,7 +30,6 @@
  *
  */
 
-static const char rcsid[] = "$Id: icb.c,v 1.3 2015/08/21 19:01:12 dhartmei Exp $";
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -40,8 +39,8 @@ static const char rcsid[] = "$Id: icb.c,
 
 extern int	 sync_write(int, const char *, int);
 
-static unsigned char	 icb_args(const char *, unsigned char, char [255][255]);
-static void		 icb_cmd(const char *, unsigned char, int, int);
+static unsigned char	 icb_args(const unsigned char *, unsigned char, char [255][255]);
+static void		 icb_cmd(const unsigned char *, unsigned char, int, int);
 static void		 icb_ico(int, const char *);
 static void		 icb_iwl(int, const char *, const char *, long,
 			    long, const char *, const char *);
@@ -109,7 +108,7 @@ static unsigned off;
  */
 
 void
-scan(const char **s, char *d, size_t siz, const char *skip, const char *term)
+scan(const unsigned char **s, char *d, size_t siz, const char *skip, const char *term)
 {
 	while (**s && strchr(skip, **s) != NULL)
 		(*s)++;
@@ -164,7 +163,7 @@ icb_recv(const char *buf, unsigned len, 
 }
 
 static unsigned char
-icb_args(const char *data, unsigned char len, char args[255][255])
+icb_args(const unsigned char *data, unsigned char len, char args[255][255])
 {
 	unsigned char i = 0, j = 0, k = 0;
 
@@ -190,10 +189,10 @@ icb_args(const char *data, unsigned char
 }
 
 static void
-icb_cmd(const char *cmd, unsigned char len, int fd, int server_fd)
+icb_cmd(const unsigned char *cmd, unsigned char len, int fd, int server_fd)
 {
 	char args[255][255];
-	const char *a = args[1];
+	const unsigned char *a = (unsigned char *)args[1];
 	unsigned char i, j;
 	char s[8192];
 
@@ -269,7 +268,7 @@ icb_cmd(const char *cmd, unsigned char l
 			char old_nick[256], new_nick[256];
 
 			scan(&a, old_nick, sizeof(old_nick), " ", " ");
-			if (strncmp(a, " changed nickname to ", 21))
+			if (strncmp((const char *)a, " changed nickname to ", 21))
 				return;
 			a += 21;
 			scan(&a, new_nick, sizeof(new_nick), " ", " ");
@@ -283,7 +282,7 @@ icb_cmd(const char *cmd, unsigned char l
 			char nick[256], topic[256];
 
 			scan(&a, nick, sizeof(nick), " ", " ");
-			if (strncmp(a, " changed the topic to \"", 23))
+			if (strncmp((const char *)a, " changed the topic to \"", 23))
 				return;
 			a += 23;
 			scan(&a, topic, sizeof(topic), "", "\"");
@@ -294,13 +293,13 @@ icb_cmd(const char *cmd, unsigned char l
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
@@ -312,7 +311,7 @@ icb_cmd(const char *cmd, unsigned char l
 			char nick[256];
 
 			scan(&a, nick, sizeof(nick), " ", " ");
-			if (strcmp(a, " was booted."))
+			if (strcmp((const char *)a, " was booted."))
 				return;
 			snprintf(s, sizeof(s), ":%s KICK %s %s :booted\r\n",
 			    icb_moderator, irc_channel, nick);
@@ -523,7 +522,7 @@ icb_send_openmsg(int fd, const char *msg
 		cmd[off++] = 0;
 		cmd[0] = off - 1;
 		/* cmd[0] <= MAX_MSG_SIZE */
-		sync_write(fd, cmd, off);
+		sync_write(fd, (const char *)cmd, off);
 	}
 }
 
@@ -548,7 +547,7 @@ icb_send_privmsg(int fd, const char *nic
 		cmd[off++] = 0;
 		cmd[0] = off - 1;
 		/* cmd[0] <= MAX_MSG_SIZE */
-		sync_write(fd, cmd, off);
+		sync_write(fd, (const char *)cmd, off);
 	}
 }
 
