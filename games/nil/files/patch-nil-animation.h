--- nil/animation.h.orig	Sat Nov 15 16:18:52 2003
+++ nil/animation.h	Sat Nov 15 16:26:19 2003
@@ -25,7 +25,7 @@
 class Animator;
 class Animation {
 public:
-	friend Animator;
+	friend class Animator;
 
 	Animation();
 	~Animation();
