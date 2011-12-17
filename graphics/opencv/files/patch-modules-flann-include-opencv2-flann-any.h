Index: modules/flann/include/opencv2/flann/any.h
===================================================================
--- modules/flann/include/opencv2/flann/any.h	(revision 6880)
+++ modules/flann/include/opencv2/flann/any.h	(revision 6881)
@@ -30,6 +30,12 @@
 {
 };
 
+inline std::ostream& operator <<(std::ostream& out, const empty_any&)
+{
+    out << "[empty_any]";
+    return out;
+}
+
 struct base_any_policy
 {
     virtual void static_delete(void** x) = 0;
