--- jlint.cc.orig	2011-01-11 02:42:33 UTC
+++ jlint.cc
@@ -41,7 +41,7 @@ bool  source_path_redefined = false;
 int   reported_message_mask = cat_all;
 FILE* history;
 string_pool stringPool;
-field_desc* is_const;
+field_desc* jlint_is_const;
 
 message_descriptor msg_table[] = 
   {
@@ -401,8 +401,8 @@ bool parse_class_file(byte* fp)
   is_this->equals = is_this;
   is_this->cls = this_class;
 
-  // init. is_const
-  field_desc* is_const = new field_desc(utf_string("<const>"), NULL, NULL);
+  // init. jlint_is_const
+  field_desc* jlint_is_const = new field_desc(utf_string("<const>"), NULL, NULL);
 
   this_class->attr = access_flags;
   if (super_class_name == 0) { // Object class
@@ -627,7 +627,7 @@ bool parse_class_file(byte* fp)
   delete[] constant_pool;
   delete is_this->name_and_type;
   //delete is_this;
-  delete is_const;
+  delete jlint_is_const;
 
   monitor_stack::const_iterator it;
   for (it = this_class->usedLocks.begin();
@@ -1041,7 +1041,7 @@ int main(int argc, char* argv[])
         if (verbose) { 
           fprintf(stderr, 
                   "Jlint - program correctness verifier for Java, "
-                  "version %s ("__DATE__").\n", VERSION);
+                  "version %s\n", VERSION);
         }
         continue;
       }
