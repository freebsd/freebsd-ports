--- Namazu.xs.orig	Tue Feb 19 14:01:26 2002
+++ Namazu.xs	Tue Jun 18 17:56:53 2002
@@ -68,7 +68,7 @@
 		int i;
 		AV *retar;
 		NmzResult hlist;
-		char result[BUFSIZE];
+		char result[4][BUFSIZE];
 
 		qstr = SvPV(query, PL_na);
 		strcpy(cqstr, qstr);
@@ -77,15 +77,21 @@
 		for (i = 0; i < hlist.num; i ++) {
 			SV *ohlist = perl_eval_pv("new Search::Namazu::Result", TRUE);
 			dSP;
-			nmz_get_field_data(hlist.data[i].idxid, hlist.data[i].docid, "uri", result);
+			nmz_get_field_data(hlist.data[i].idxid, hlist.data[i].docid, "uri", result[0]);
+			nmz_get_field_data(hlist.data[i].idxid, hlist.data[i].docid, "summary", result[1]);
+			nmz_get_field_data(hlist.data[i].idxid, hlist.data[i].docid, "title", result[2]);
+			nmz_get_field_data(hlist.data[i].idxid, hlist.data[i].docid, "author", result[3]);
 			ENTER;
 			SAVETMPS;
 			PUSHMARK(SP);
 			PUSHs(ohlist);
 			PUSHs(sv_2mortal(newSViv(hlist.data[i].score)));
-			PUSHs(sv_2mortal(newSVpv(result, strlen(result))));
+			PUSHs(sv_2mortal(newSVpv(result[0], strlen(result[0]))));
 			PUSHs(sv_2mortal(newSViv(hlist.data[i].date)));
 			PUSHs(sv_2mortal(newSViv(hlist.data[i].rank)));
+			PUSHs(sv_2mortal(newSVpv(result[1], strlen(result[1]))));
+			PUSHs(sv_2mortal(newSVpv(result[2], strlen(result[2]))));
+			PUSHs(sv_2mortal(newSVpv(result[3], strlen(result[3]))));
 			PUTBACK;
 			perl_call_method("set", G_DISCARD);
 			av_push(retar, ohlist);
