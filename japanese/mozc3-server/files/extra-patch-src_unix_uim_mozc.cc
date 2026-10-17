--- src/unix/uim/mozc.cc.orig	2021-05-12 03:17:52 UTC
+++ src/unix/uim/mozc.cc
@@ -280,14 +280,14 @@ update_candidates(uim_lisp mc_, int id)
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
@@ -568,7 +568,7 @@ get_nr_candidates(uim_lisp id_)
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
 
-  return MAKE_INT(output->candidates().size());
+  return MAKE_INT(output->candidate_window().size());
 }
 
 static uim_lisp
@@ -576,7 +576,7 @@ get_nth_candidate(uim_lisp id_, uim_lisp nth_)
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *cand, *prefix, *suffix;
   char *s;
 
@@ -612,7 +612,7 @@ get_nth_label(uim_lisp id_, uim_lisp nth_)
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *label;
 
   int nth;
@@ -641,7 +641,7 @@ get_nth_annotation(uim_lisp id_, uim_lisp nth_)
 {
   int id = C_INT(id_);
   commands::Output *output = context_slot[id].output;
-  const commands::Candidates &candidates = output->candidates();
+  const commands::CandidateWindow &candidates = output->candidate_window();
   const char *annotation;
 
   int nth;
@@ -1032,7 +1032,7 @@ select_candidate(uim_lisp mc_, uim_lisp id_, uim_lisp 
 #if USE_CASCADING_CANDIDATES
   if (idx >= context_slot[id].unique_candidate_ids->size())
 #else
-  if (idx >= context_slot[id].output->candidates().candidate_size())
+  if (idx >= context_slot[id].output->candidate_window().candidate_size())
 #endif
     return uim_scm_f();
 
@@ -1041,7 +1041,7 @@ select_candidate(uim_lisp mc_, uim_lisp id_, uim_lisp 
   if (cand_id == kBadCandidateId)
     return uim_scm_f();
 #else
-  const int32 cand_id = context_slot[id].output->candidates().candidate(idx).id();
+  const int32 cand_id = context_slot[id].output->candidate_window().candidate(idx).id();
 #endif
 
   commands::SessionCommand command;
