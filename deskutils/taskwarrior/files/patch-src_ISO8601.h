--- src/ISO8601.h.orig	2015-10-21 20:50:42 UTC
+++ src/ISO8601.h
@@ -96,11 +96,10 @@ public:
   bool sameWeek   (const ISO8601d&) const;
   bool sameMonth  (const ISO8601d&) const;
   bool sameYear   (const ISO8601d&) const;
-  ISO8601d operator+  (time_t);
-  ISO8601d operator+  (const int);
-  ISO8601d operator-  (const int);
-  ISO8601d& operator+= (const int);
-  ISO8601d& operator-= (const int);
+  ISO8601d operator+  (const time_t);
+  ISO8601d operator-  (const time_t);
+  ISO8601d& operator+= (const time_t);
+  ISO8601d& operator-= (const time_t);
   time_t operator- (const ISO8601d&);
   void operator-- ();    // Prefix
   void operator-- (int); // Postfix
