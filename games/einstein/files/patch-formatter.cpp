--- formatter.cpp.orig	2005-08-14 02:40:58 UTC
+++ formatter.cpp
@@ -58,7 +58,7 @@ Formatter::Formatter(unsigned char *data
             if ((c.type == INT_ARG) || (c.type == STRING_ARG) ||
                     (c.type == FLOAT_ARG) || (c.type == DOUBLE_ARG))
             {
-                int no = (int)c.data;
+                long int no = (long int)c.data;
                 args[no - 1] = c.type;
             }
         }
@@ -123,7 +123,7 @@ class StrArgValue: public ArgValue
 std::wstring Formatter::format(std::vector<ArgValue*> &argValues) const
 {
     std::wstring s;
-    int no;
+    long int no;
 
     for (int i = 0; i < commandsCnt; i++) {
         Command *cmd = &commands[i];
@@ -135,8 +135,8 @@ std::wstring Formatter::format(std::vect
                 
             case STRING_ARG:
             case INT_ARG:
-                no = (int)cmd->data - 1;
-                if (no < (int)argValues.size())
+                no = (long int)cmd->data - 1;
+                if (no < (long int)argValues.size())
                     s += argValues[no]->format(cmd);
                 break;
 
