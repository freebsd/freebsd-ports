--- ext/ming/ming/swftextfield.c.orig	2003-09-28 12:01:42.000000000 +0900
+++ ext/ming/ming/swftextfield.c	2014-01-29 17:11:21.000000000 +0900
@@ -209,7 +209,7 @@
   struct RSWFTextField *t;
 
   Data_Get_Struct(self, struct RSWFTextField, t);
-  SWFTextField_addString(t->this, STR2CSTR(s));
+  SWFTextField_addString(t->this, StringValuePtr(s));
 
   return self;
 }
@@ -245,7 +245,7 @@
   struct RSWFTextField *t;
 
   Data_Get_Struct(self, struct RSWFTextField, t);
-  SWFTextField_setVariableName(t->this, STR2CSTR(n));
+  SWFTextField_setVariableName(t->this, StringValuePtr(n));
 
   return self;
 }
