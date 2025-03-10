- fix compilation:
- error: reference to 'lock' is ambiguous
- note: candidate found by name lookup is 'lock'
- note: candidate found by name lookup is 'std::lock'

--- src/xye_script.cpp.orig	2012-09-15 20:21:06 UTC
+++ src/xye_script.cpp
@@ -859,7 +859,7 @@ void Load_Lock(TiXmlElement* el)
         el->QueryIntAttribute("x",&LastX);
         el->QueryIntAttribute("y",&LastY);
         blockcolor c=GetElementBlockColor(el);
-    lock* bc=new lock(game::SquareN(LastX,LastY),c);
+    ::lock* bc=new ::lock(game::SquareN(LastX,LastY),c);
 }
 
 /* Load Key*/
