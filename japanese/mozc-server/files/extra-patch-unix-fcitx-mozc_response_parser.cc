--- unix/fcitx/mozc_response_parser.cc.orig	2014-08-31 07:00:01.000000000 +0900
+++ unix/fcitx/mozc_response_parser.cc	2014-08-31 07:00:45.000000000 +0900
@@ -235,11 +235,13 @@
     }
 }
 
+#if 0
 static boolean FcitxMozcPaging(void* arg, boolean prev)
 {
     FcitxMozc* mozc = static_cast<FcitxMozc*>(arg);
     return mozc->paging(prev);
 }
+#endif
 
 void MozcResponseParser::ParseCandidates(
     const mozc::commands::Candidates &candidates, FcitxMozc *fcitx_mozc) const {
@@ -286,12 +288,14 @@
     FcitxCandidateWordList* candList = FcitxInputStateGetCandidateList(fcitx_mozc->GetInputState());
     FcitxCandidateWordReset(candList);
     FcitxCandidateWordSetPageSize(candList, 9);
+#if 0
     if (candidates.has_direction() &&
         candidates.direction() == commands::Candidates::HORIZONTAL) {
         FcitxCandidateWordSetLayoutHint(candList, CLH_Horizontal);
     } else {
         FcitxCandidateWordSetLayoutHint(candList, CLH_Vertical);
     }
+#endif
 
     map<int32, pair<string, string> > usage_map;
     if (candidates.has_usages()) {
@@ -395,7 +399,9 @@
     else
         FcitxCandidateWordSetChoose(candList, EMPTY_STR_CHOOSE);
     FcitxCandidateWordSetFocus(candList, local_index);
+#if 0
     FcitxCandidateWordSetOverridePaging(candList, hasPrev, hasNext, FcitxMozcPaging, fcitx_mozc, NULL);
+#endif
 }
 
 static int GetRawCursorPos(const char * str, int upos)
