--- src/basic/hssp.cpp.orig	2026-08-04 03:42:17 UTC
+++ src/basic/hssp.cpp
@@ -356,6 +356,7 @@ Hsp::Hsp(const ApproxHsp& h, Loc qlen, Loc tlen) :
 
 Hsp::Hsp(const ApproxHsp& h, Loc qlen, Loc tlen) :
 	backtraced(true),
+	seed_only(false),
 	score(h.score),
 	frame(0),
 	length(h.query_range.length()),
