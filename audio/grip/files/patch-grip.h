--- grip.h.orig	Mon Jul 16 12:15:32 2001
+++ grip.h	Mon Jan 21 22:51:22 2002
@@ -239,13 +239,10 @@
 char *CDDBGenre(int genre);
 int CDDBGenreValue(char *genre);
 gboolean CDDBDoQuery(int cd_desc,CDDBServer *server,
-		     CDDBHello *hello,CDDBQuery *query);
+		     CDDBHello *hello,CDDBQuery *query, int ns);
 gboolean CDDBRead(int cd_desc,CDDBServer *server,
 		  CDDBHello *hello,CDDBEntry *entry,
-		  DiscData *data);
-gboolean CDDBRead(int cd_desc,CDDBServer *server,
-		  CDDBHello *hello,CDDBEntry *entry,
-		  DiscData *data);
+		  DiscData *data, int ns);
 gboolean CDDBStatDiscData(int cd_desc);
 int CDDBReadDiscData(int cd_desc, DiscData *outdata);
 int CDDBWriteDiscData(int cd_desc,DiscData *ddata,FILE *outfile,
