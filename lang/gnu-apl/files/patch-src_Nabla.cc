--- src/Nabla.cc.orig	2019-06-23 12:39:20 UTC
+++ src/Nabla.cc
@@ -219,7 +219,7 @@ Nabla::start()
    // ∇FUN[⎕]∇
    // etc.
    //
-UCS_string::iterator c(first_command.begin());
+UCS_string::iterator c(first_command);
 
    // skip leading spaces
    //
@@ -375,7 +375,7 @@ Nabla::parse_oper(UCS_string & oper, bool initial)
 
    if (oper.size() == 0 && do_close)   return 0;
 
-UCS_string::iterator c(oper.begin());
+UCS_string::iterator c(oper);
 Unicode cc = c.next();
 UCS_string text = oper;
    while (cc == ' ')   cc = c.next();   // skip leading whitespace
