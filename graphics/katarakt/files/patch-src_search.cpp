--- src/search.cpp.orig	2020-08-08 07:25:17 UTC
+++ src/search.cpp
@@ -68,26 +68,11 @@ void SearchWorker::run() {
 
 			// collect all occurrences
 			QList<QRectF> *hits = new QList<QRectF>;
-#if POPPLER_VERSION < POPPLER_VERSION_CHECK(0, 22, 0)
-			// old search interface, slow for many hits per page
-			double x = 0, y = 0, x2 = 0, y2 = 0;
-			while (!stop && !die &&
-					p->search(search_term, x, y, x2, y2, Poppler::Page::NextResult,
-						has_upper_case ? Poppler::Page::CaseSensitive : Poppler::Page::CaseInsensitive)) {
-				hits->push_back(QRectF(x, y, x2 - x, y2 - y));
-			}
-#elif POPPLER_VERSION < POPPLER_VERSION_CHECK(0, 31, 0)
-			// new search interface
-			QList<QRectF> tmp = p->search(search_term,
-					has_upper_case ? Poppler::Page::CaseSensitive : Poppler::Page::CaseInsensitive);
-			hits->swap(tmp);
-#else
 			// even newer interface
 			QList<QRectF> tmp = p->search(search_term,
 					has_upper_case ? (Poppler::Page::SearchFlags) 0 : Poppler::Page::IgnoreCase);
 			// TODO support Poppler::Page::WholeWords
 			hits->swap(tmp);
-#endif
 #ifdef DEBUG
 			if (hits->size() > 0) {
 				cerr << hits->size() << " hits on page " << page << endl;
