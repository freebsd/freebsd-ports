--- src/unix/uim/mozc.cc.orig
+++ src/unix/uim/mozc.cc
@@ -61,20 +61,23 @@
 
 #define USE_CASCADING_CANDIDATES	0
 
-#include <map>
-#include <ext/hash_map>
-using __gnu_cxx::hash_map;
+#include <cstdint>
+#include <ctime>
+#include <string>
+#include <unordered_map>
+#include <utility>
+#include <vector>
 static char **argv;
 
 // for every 5 minutes, call SyncData
-const uint64 kSyncDataInterval = 5 * 60;
+const std::uint64_t kSyncDataInterval = 5 * 60;
 #if USE_CASCADING_CANDIDATES
 // An ID for a candidate which is not associated with a text.
-const int32 kBadCandidateId = -1;
+const std::int32_t kBadCandidateId = -1;
 #endif
 
-uint64 GetTime() {
-  return static_cast<uint64>(time(NULL));
+std::uint64_t GetTime() {
+  return static_cast<std::uint64_t>(time(NULL));
 }
 
 namespace mozc {
@@ -93,9 +96,9 @@
   bool need_cand_reactivate;
   int prev_page;
   int cand_nr_before;
-  uint64 last_sync_time;
+  std::uint64_t last_sync_time;
 #if USE_CASCADING_CANDIDATES
-  vector<int32> *unique_candidate_ids;
+  std::vector<std::int32_t> *unique_candidate_ids;
 #endif
   config::Config::PreeditMethod preedit_method;
 } *context_slot;
@@ -126,7 +129,7 @@
   if (context_slot[id].session == NULL)
     return;
 
-  const uint64 current_time = GetTime();
+  const std::uint64_t current_time = GetTime();
   if (force ||
       (current_time >= context_slot[id].last_sync_time &&
        current_time - context_slot[id].last_sync_time >= kSyncDataInterval)) {
@@ -173,8 +176,8 @@
 {
   size_t len = segment.value_length();
 
-  auto former = string(Util::Utf8SubString(segment.value(), 0, pos));
-  auto latter = string(Util::Utf8SubString(segment.value(), pos, len));
+  auto former = std::string(Util::Utf8SubString(segment.value(), 0, pos));
+  auto latter = std::string(Util::Utf8SubString(segment.value(), pos, len));
 
   uim_lisp seg_f, seg_c, seg_l;
   if (pos == 0) {
@@ -280,14 +283,14 @@
 {
   commands::Output *output = context_slot[id].output;
 
-  if (!output->has_candidates()) {
+  if (!output->has_candidate_window()) {
     uim_scm_callf("im-deactivate-candidate-selector", "o", mc_);
     context_slot[id].cand_nr_before = 0;
 
     return;
   }
 
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   bool first_time = false;
   bool has_focused_index = candidates.has_focused_index();
   int current_page = has_focused_index ? candidates.focused_index() / 9 : 0;
@@ -316,7 +319,7 @@
     context_slot[id].unique_candidate_ids->clear();
     for (int i = 0; i < candidates.candidate_size(); ++i) {
       if (candidates.candidate(i).has_id()) {
-        const int32 cand_id = candidates.candidate(i).id();
+        const std::int32_t cand_id = candidates.candidate(i).id();
         context_slot[id].unique_candidate_ids->push_back(cand_id);
       } else {
         // The parent node of the cascading window does not have an id since the
@@ -380,7 +383,7 @@
 	  !NULLP(latter = uim_scm_callf("ustr-latter-seq", "o", ustr))) {
 	  uim_lisp str = CAR(latter);
 
-          string text = REFER_C_STR(str);
+          std::string text = REFER_C_STR(str);
           session_command.set_text(text);
       } else {
 #if 0
@@ -389,7 +392,7 @@
         ustr = uim_scm_callf("im-acquire-text", "oyyyi", mc_, "primary", "cursor", "line", 0);
 	if (TRUEP(ustr) && !NULLP(former = uim_scm_callf("ustr-former-seq", "o", ustr))) {
 	  uim_lisp str = CAR(former);
-	  string text = REFER_C_STR(str);
+	  std::string text = REFER_C_STR(str);
 	  session_command.set_text(text);
 	  use_primary_text = 1;
 	} else
@@ -449,7 +452,7 @@
   context_slot[id].cand_nr_before = 0;
   context_slot[id].prev_page = 0;
 #if USE_CASCADING_CANDIDATES
-  context_slot[id].unique_candidate_ids = new vector<int32>;
+  context_slot[id].unique_candidate_ids = new std::vector<std::int32_t>;
 #endif
 
   // Launch mozc_server
@@ -568,7 +571,7 @@
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
 
-  return MAKE_INT(output->candidates().size());
+  return MAKE_INT(output->candidate_window().size());
 }
 
 static uim_lisp
@@ -576,7 +579,7 @@
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *cand, *prefix, *suffix;
   char *s;
 
@@ -612,7 +615,7 @@
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *label;
 
   int nth;
@@ -641,7 +644,7 @@
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *annotation;
 
   int nth;
@@ -889,15 +892,7 @@
   {0, 0}
 };
 
-struct eqstr
-{
-  bool operator()(const char* s1, const char* s2) const
-  {
-    return strcmp(s1, s2) == 0;
-  }
-};
-
-typedef hash_map<const char *, int, __gnu_cxx::hash<const char *>, eqstr> KeyMap;
+using KeyMap = std::unordered_map<std::string, int>;
 static KeyMap key_map;
 
 static void install_keymap(void)
@@ -992,7 +987,7 @@
     update_all(mc_, id);
     uim_scm_callf("mozc-context-set-on!", "oo", mc_, uim_scm_f());
   } else {
-    command.set_type(commands::SessionCommand::SWITCH_INPUT_MODE);
+    command.set_type(commands::SessionCommand::SWITCH_COMPOSITION_MODE);
     command.set_composition_mode(mode);
     context_slot[id].session->SendCommand(command, context_slot[id].output);
     context_slot[id].currentMode = mode; /* don't set this with DIRECT mode */
@@ -1008,7 +1003,7 @@
   int id = C_INT(id_);
   commands::SessionCommand command;
 
-  command.set_type(commands::SessionCommand::SWITCH_INPUT_MODE);
+  command.set_type(commands::SessionCommand::SWITCH_COMPOSITION_MODE);
   command.set_composition_mode(context_slot[id].currentMode);
   context_slot[id].session->SendCommand(command, context_slot[id].output);
 
@@ -1032,16 +1027,16 @@
 #if USE_CASCADING_CANDIDATES
   if (idx >= context_slot[id].unique_candidate_ids->size())
 #else
-  if (idx >= context_slot[id].output->candidates().candidate_size())
+  if (idx >= context_slot[id].output->candidate_window().candidate_size())
 #endif
     return uim_scm_f();
 
 #if USE_CASCADING_CANDIDATES
-  const int32 cand_id = (*context_slot[id].unique_candidate_ids)[idx];
+  const std::int32_t cand_id = (*context_slot[id].unique_candidate_ids)[idx];
   if (cand_id == kBadCandidateId)
     return uim_scm_f();
 #else
-  const int32 cand_id = context_slot[id].output->candidates().candidate(idx).id();
+  const std::int32_t cand_id = context_slot[id].output->candidate_window().candidate(idx).id();
 #endif
 
   commands::SessionCommand command;
@@ -1126,14 +1121,14 @@
       !NULLP(latter = uim_scm_callf("ustr-latter-seq", "o", ustr))) {
     uim_lisp str = CAR(latter);
 
-    string text = REFER_C_STR(str);
+    std::string text = REFER_C_STR(str);
     session_command.set_text(text);
   } else {
     ustr = uim_scm_callf("im-acquire-text", "oyyyi", mc_, "primary", "cursor", "line", 0);
     if (TRUEP(ustr) &&
 	!NULLP(former = uim_scm_callf("ustr-former-seq", "o", ustr))) {
       uim_lisp str = CAR(former);
-      string text = REFER_C_STR(str);
+      std::string text = REFER_C_STR(str);
       session_command.set_text(text);
       use_primary_text = 1;
     } else
