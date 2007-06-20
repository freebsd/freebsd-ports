--- include/Vector2D.h.orig	Wed Mar 30 02:37:13 2005
+++ include/Vector2D.h	Thu Jun 14 13:19:11 2007
@@ -24,6 +24,9 @@
 
 using namespace std;
 
+class Vector2D;
+Vector2D angle2vec(const double);
+
 class Vector2D
 {
 public:
