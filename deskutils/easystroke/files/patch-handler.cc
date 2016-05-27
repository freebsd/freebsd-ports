--- handler.cc.orig	2013-03-27 15:52:38 UTC
+++ handler.cc
@@ -533,8 +533,6 @@ public:
 	virtual Grabber::State grab_mode() { return parent->grab_mode(); }
 };
 
-static inline float abs(float x) { return x > 0 ? x : -x; }
-
 class AbstractScrollHandler : public Handler {
 	bool have_x, have_y;
 	float last_x, last_y;
