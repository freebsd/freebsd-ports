--- src/filters.cc.orig	2023-03-30 07:40:48 UTC
+++ src/filters.cc
@@ -237,8 +237,6 @@ void anonymize_posts::operator()(post_t& post)
 
 void anonymize_posts::operator()(post_t& post)
 {
-	boost::uuids::detail::sha1  sha;
-  unsigned int message_digest[5];
   bool         copy_xact_details = false;
 
   if (last_xact != post.xact) {
@@ -255,12 +253,7 @@ void anonymize_posts::operator()(post_t& post)
     std::ostringstream buf;
     buf << reinterpret_cast<boost::uintmax_t>(post.xact->payee.c_str())
         << integer_gen() << post.xact->payee.c_str();
-
-		sha.reset();
-    sha.process_bytes(buf.str().c_str(), buf.str().length());
-    sha.get_digest(message_digest);
-
-    xact.payee = to_hex(message_digest);
+    xact.payee = sha1sum(buf.str(), 8);
     xact.note  = none;
   } else {
     xact.journal = post.xact->journal;
@@ -273,12 +266,7 @@ void anonymize_posts::operator()(post_t& post)
        acct = acct->parent) {
     std::ostringstream buf;
     buf << integer_gen() << acct << acct->fullname();
-
-    sha.reset();
-    sha.process_bytes(buf.str().c_str(), buf.str().length());
-    sha.get_digest(message_digest);
-
-    account_names.push_front(to_hex(message_digest));
+    account_names.push_front(sha1sum(buf.str(), 8));
   }
 
   account_t * new_account =
@@ -1268,7 +1256,7 @@ void budget_posts::report_budget_items(const date_t& d
     foreach (pending_posts_list::iterator& i, posts_to_erase)
       pending_posts.erase(i);
   }
-  
+
   if (pending_posts.size() == 0)
     return;
 
