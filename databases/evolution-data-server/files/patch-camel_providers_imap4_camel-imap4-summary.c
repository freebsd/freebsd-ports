--- camel/providers/imap4/camel-imap4-summary.c.orig	Mon May  7 01:01:31 2007
+++ camel/providers/imap4/camel-imap4-summary.c	Mon May  7 01:05:32 2007
@@ -1148,6 +1148,7 @@ static CamelIMAP4Command *
 imap4_summary_fetch_flags (CamelFolderSummary *summary)
 {
 	CamelFolder *folder = summary->folder;
+	CamelIMAP4Summary *imap4_summary = (CamelIMAP4Summary *) summary;
 	struct imap4_fetch_all_t *fetch;
 	CamelMessageInfo *info[2];
 	CamelIMAP4Engine *engine;
@@ -1479,7 +1480,7 @@ camel_imap4_summary_flush_updates (Camel
 		}
 	} else {
 		/* need to fetch new envelopes */
-		first = scount + 1;
+		seqid = scount + 1;
 	}
 	
 	if (seqid != 0 && seqid <= imap4_summary->exists) {
