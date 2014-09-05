--- unix/fcitx/eim.cc.orig	2014-08-31 06:48:00.000000000 +0900
+++ unix/fcitx/eim.cc	2014-08-31 06:48:11.000000000 +0900
@@ -176,7 +176,9 @@
             // clear candidate table
             FcitxCandidateWordReset(candList);
             FcitxCandidateWordSetPageSize(candList, 9);
+#if 0
             FcitxCandidateWordSetLayoutHint(candList, CLH_Vertical);
+#endif
             FcitxCandidateWordSetChoose(candList, "\0\0\0\0\0\0\0\0\0\0");
             FcitxMessagesAddMessageAtLast(preedit, MSG_TIPS, "%s [%s]", usage.first.c_str(), _("Press Escape to go back"));
 
