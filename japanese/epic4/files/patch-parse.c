--- source/parse.c.orig	Wed Aug 16 02:25:44 2000
+++ source/parse.c	Mon Dec  4 03:44:17 2000
@@ -30,6 +30,7 @@
 #include "notify.h"
 #include "notice.h"
 #include "timer.h"
+#include "kanji.h"
 
 #define STRING_CHANNEL 	'+'
 #define MULTI_CHANNEL 	'#'
@@ -1131,7 +1132,7 @@
  * parse_server: parses messages from the server, doing what should be done
  * with them 
  */
-void 	parse_server (char *orig_line)
+void 	parse_server (char *raw_line)
 {
 	char	*from,
 		*comm;
@@ -1143,6 +1144,9 @@
 	int	cnt;
 	char	*line = NULL;
 	size_t	size;
+	char    orig_line[BIG_BUFFER_SIZE];
+	
+	Jis2Euc(raw_line, orig_line);
 
 	if (num_protocol_cmds == -1)
 		num_protocol_cmds = NUMBER_OF_COMMANDS;
