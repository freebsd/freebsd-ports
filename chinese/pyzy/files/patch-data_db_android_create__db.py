--- data/db/android/create_db.py.orig	2020-10-11 20:12:08 UTC
+++ data/db/android/create_db.py
@@ -3,27 +3,27 @@ from pydict import *
 from id import *
 from valid_hanzi import *
 import sys
+from functools import cmp_to_key
 
 def get_sheng_yun(pinyin):
     if pinyin == None:
         return None, None
     if pinyin == "ng":
         return "", "en"
-    for i in xrange(2, 0, -1):
+    for i in range(2, 0, -1):
         t = pinyin[:i]
         if t in SHENGMU_DICT:
             return t, pinyin[len(t):]
     return "", pinyin
 
 def read_phrases(filename):
-    buf = file(filename).read()
-    buf = unicode(buf, "utf16")
+    buf = open(filename, encoding='utf-16').read()
     buf = buf.strip()
-    for l in buf.split(u'\n'):
-        hanzi, freq, flag, pinyin = l.split(u' ', 3)
+    for l in buf.split('\n'):
+        hanzi, freq, flag, pinyin = l.split(' ', 3)
         freq = float(freq)
         pinyin = pinyin.split()
-        if any(map(lambda c: c not in valid_hanzi, hanzi)):
+        if any([c not in valid_hanzi for c in hanzi]):
             continue
         yield hanzi, freq, pinyin
 
@@ -33,9 +33,9 @@ def create_db(filename):
     # con.execute ("PRAGMA synchronous = NORMAL;")
     # con.execute ("PRAGMA temp_store = MEMORY;")
     # con.execute ("PRAGMA default_cache_size = 5000;")
-    print "PRAGMA synchronous = NORMAL;"
-    print "PRAGMA temp_store = MEMORY;"
-    print "PRAGMA default_cache_size = 5000;"
+    print("PRAGMA synchronous = NORMAL;")
+    print("PRAGMA temp_store = MEMORY;")
+    print("PRAGMA default_cache_size = 5000;")
 
 
     sql = "CREATE TABLE py_phrase_%d (phrase TEXT, freq INTEGER, %s);"
@@ -44,12 +44,12 @@ def create_db(filename):
         for j in range(0, i + 1):
             column.append ("s%d INTEGER" % j)
             column.append ("y%d INTEGER" % j)
-        print sql % (i, ",".join(column))
+        print(sql % (i, ",".join(column)))
         # con.execute(sql % (i, column))
         # con.commit()
 
     records = list(read_phrases(filename))
-    records.sort(lambda a, b: 1 if a[1] > b[1] else -1)
+    records.sort(key=cmp_to_key(lambda a, b: 1 if a[1] > b[1] else -1))
     records_new = []
     i = 0
     max_freq = 0.0
@@ -60,7 +60,7 @@ def create_db(filename):
         records_new.append((hanzi, i, pinyin))
     records_new.reverse()
     
-    print "BEGIN;"
+    print("BEGIN;")
     insert_sql = "INSERT INTO py_phrase_%d VALUES (%s);"
     for hanzi, freq, pinyin in records_new:
         columns = []
@@ -69,12 +69,12 @@ def create_db(filename):
             s, y = pinyin_id[s], pinyin_id[y]
             columns.append(s)
             columns.append(y)
-        values = "'%s', %d, %s" % (hanzi.encode("utf8"), freq, ",".join(map(str,columns)))
+        values = "'%s', %d, %s" % (hanzi, freq, ",".join(map(str,columns)))
             
         sql = insert_sql % (len(hanzi) - 1, values)
-        print sql
-    print "COMMIT;"
-    print "VACUUM;"
+        print(sql)
+    print("COMMIT;")
+    print("VACUUM;")
 
 def main():
     create_db(sys.argv[1])
