--- src/libslic3r/SupportSpotsGenerator.cpp.orig	2023-07-25 08:36:31 UTC
+++ src/libslic3r/SupportSpotsGenerator.cpp
@@ -849,7 +849,7 @@ std::tuple<SupportPoints, PartialObjects> check_stabil
                         }
                     }
                 }
-                auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) {
+                auto estimate_conn_strength = [bottom_z](const SliceConnection &conn) -> float {
                     if (conn.area < EPSILON) { // connection is empty, does not exists. Return max strength so that it is not picked as the
                                                // weakest connection.
                         return INFINITY;
