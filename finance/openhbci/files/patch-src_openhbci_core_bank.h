--- src/openhbci/core/bank.h.orig	2003-06-13 21:50:00 UTC
+++ src/openhbci/core/bank.h
@@ -97,7 +97,7 @@ public:
     instituteMessage();
     ~instituteMessage();
 
-	const bool operator==(const instituteMessage &msg);
+    bool operator==(const instituteMessage &msg) const;
 
     /** Returns the Date of arrival. */
     const Date &date() const { return _date;};
