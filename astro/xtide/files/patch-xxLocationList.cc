Regressed by https://gitlab.freedesktop.org/xorg/lib/libxaw/-/commit/197e9d055f3c

xxLocationList.cc:90:3: error: no matching function for call to 'XawListChange'
  XawListChange (list->widget(), stringList, 0, 0, 1);
  ^~~~~~~~~~~~~
/usr/local/include/X11/Xaw/List.h:167:6: note: candidate function not viable: no known conversion from 'char **' to 'const char **' for 2nd argument
void XawListChange
     ^

--- xxLocationList.cc.orig	2014-10-11 19:42:10 UTC
+++ xxLocationList.cc
@@ -87,7 +87,7 @@ void xxLocationList::pickStation (const XawListReturnS
 
 
 void xxLocationList::listChanged() {
-  XawListChange (list->widget(), stringList, 0, 0, 1);
+  XawListChange (list->widget(), (_Xconst char**)stringList, 0, 0, 1);
 }
 
 
