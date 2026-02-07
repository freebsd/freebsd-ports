--- src/regexx.hh.orig	Tue Mar 13 23:42:21 2001
+++ src/regexx.hh	Sun Dec 22 03:08:47 2002
@@ -94,7 +94,7 @@
 
   };
 
-  inline ostream& operator<<(ostream& _o, RegexxMatchAtom& _rxxma)
+  inline std::ostream& operator<<(std::ostream& _o, RegexxMatchAtom& _rxxma)
   {
     return _o << _rxxma.str();
   }
@@ -161,7 +161,7 @@
 
   };
 
-  inline ostream& operator<<(ostream& _o, RegexxMatch& _rxxm)
+  inline std::ostream& operator<<(std::ostream& _o, RegexxMatch& _rxxm)
   {
     return (_o << _rxxm.str());
   }
@@ -566,7 +566,7 @@
   }
 
   inline const std::string&
-  Regexx::replacef(std::string (*_func)(const RegexxMatch&), int _flags = 0)
+  Regexx::replacef(std::string (*_func)(const RegexxMatch&), int _flags)
     throw(CompileException)
   {
     exec(_flags&~nomatch);
@@ -580,7 +580,7 @@
   inline const std::string&
   Regexx::replacef(const std::string& _expr,
 		   std::string (*_func)(const RegexxMatch&),
-		   int _flags = 0)
+		   int _flags)
     throw(CompileException)
   {
     expr(_expr);
@@ -590,7 +590,7 @@
   inline const std::string&
   Regexx::replacef(const std::string& _str, const std::string& _expr,
 		   std::string (*_func)(const RegexxMatch&),
-		   int _flags = 0)
+		   int _flags)
     throw(CompileException)
   {
     str(_str);
