--- src/ixlib_re.hh.orig	Tue Jun 19 16:16:29 2001
+++ src/ixlib_re.hh	Fri Dec  1 18:36:04 2006
@@ -163,7 +163,7 @@
     
         struct backtrack_stack_entry {
           TIndex                          Index;
-          backref_stack::rewind_info      RewindInfo;
+          typename backref_stack::rewind_info      RewindInfo;
           };
   
         public:
@@ -210,7 +210,7 @@
       class any_matcher : public matcher {
         public:
           any_matcher() { 
-            MatchLength = 1; 
+            this->MatchLength = 1; 
             }
 
 	  matcher *duplicate() const;
@@ -229,7 +229,7 @@
       class start_matcher : public matcher {
         public:
           start_matcher() { 
-            MatchLength = 0; 
+            this->MatchLength = 0; 
             }
 
 	  matcher *duplicate() const;
@@ -246,7 +246,7 @@
       class end_matcher : public matcher {
         public:
           end_matcher() { 
-            MatchLength = 0;
+            this->MatchLength = 0;
             }
 
 	  matcher *duplicate() const;
@@ -263,7 +263,7 @@
       class backref_open_matcher : public matcher {
         public:
           backref_open_matcher() { 
-            MatchLength = 0; 
+            this->MatchLength = 0; 
             }
 
 	  matcher *duplicate() const;
@@ -280,7 +280,7 @@
       class backref_close_matcher : public matcher {
         public:
           backref_close_matcher() { 
-            MatchLength = 0; 
+            this->MatchLength = 0; 
             }
 
 	  matcher *duplicate() const;
