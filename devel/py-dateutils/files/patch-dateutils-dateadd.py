--- dateutils/dateadd.py.orig	2013-05-02 02:45:52 UTC
+++ dateutils/dateadd.py
@@ -53,4 +53,4 @@ def main():
         if any(bool(v) for v in kwargs.values()):
             dates = [increment(dt, **kwargs) for dt in dates]
     for dt in dates:
-        print dt.strftime(args.format)
+        print(dt.strftime(args.format))
