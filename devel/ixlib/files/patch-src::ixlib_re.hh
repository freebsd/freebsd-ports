--- src/ixlib_re.hh.orig	Fri Nov 28 11:46:14 2003
+++ src/ixlib_re.hh	Fri Nov 28 11:53:24 2003
@@ -163,7 +163,7 @@
     
         struct backtrack_stack_entry {
           TIndex                          Index;
-          backref_stack::rewind_info      RewindInfo;
+          typename backref_stack::rewind_info      RewindInfo;
           };
   
         public:
