--- utils/datetime.cpp.orig
+++ utils/datetime.cpp
@@ -590,11 +590,12 @@
 datetime::delta
 datetime::timestamp::operator-(const datetime::timestamp& other) const
 {
-    if ((*this) < other) {
-        throw std::runtime_error(
-            F("Cannot subtract %s from %s as it would result in a negative "
-              "datetime::delta, which are not supported") % other % (*this));
-    }
+    /*
+     * XXX-BD: gettimeofday isn't necessicarily monotonic so return the
+     * smallest non-zero delta if time went backwards.
+     */
+    if ((*this) < other)
+        return datetime::delta::from_microseconds(1);
     return datetime::delta::from_microseconds(to_microseconds() -
                                               other.to_microseconds());
 }
