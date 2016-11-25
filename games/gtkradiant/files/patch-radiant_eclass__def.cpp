--- radiant/eclass_def.cpp.orig	2006-02-10 22:01:20 UTC
+++ radiant/eclass_def.cpp
@@ -168,8 +168,8 @@ void setSpecialLoad(EntityClass *e, cons
   // Hydra: removed some amazingly bad cstring usage, whoever wrote that
   // needs to be taken out and shot.
 
-  char *pText = 0;
-  char *where = 0;
+  const char *pText = 0;
+  const char *where = 0;
 
   where = strstr(e->comments(),pWhat);
   if (!where)
