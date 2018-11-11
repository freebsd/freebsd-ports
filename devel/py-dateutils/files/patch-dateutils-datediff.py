--- dateutils/datediff.py.orig	2013-05-02 02:45:52 UTC
+++ dateutils/datediff.py
@@ -37,4 +37,4 @@ def main():
         if args.holiday_file:
             holidays.extend(parse(l) for l in open(args.holiday_file))
         kwargs['holidays'] = holidays
-    print __import__(args.unit)(end_dt, start_dt, **kwargs)
+    print(__import__(args.unit)(end_dt, start_dt, **kwargs))
