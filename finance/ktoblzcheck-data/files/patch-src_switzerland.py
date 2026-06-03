- Adapt to SIX Group converting their bankdata to CSV (semicolon separated).
- Don't use codecs.open(); deprecated in Python 3.14.

--- src/switzerland.py.orig	2025-05-15 11:18:20 UTC
+++ src/switzerland.py
@@ -24,12 +24,11 @@ KMyMoney
 @author: Christian David
 """
 
-import sqlite3
-import codecs
 import argparse
-import os
+import csv
+import sqlite3
 
-def createTable():
+def create_table():
     """ Create table structure
     """
     cursor = db.cursor()
@@ -45,59 +44,65 @@ def createTable():
     )
     db.commit()
 
-
-def processFile(fileName):
+def process_file(filename):
     """ Fills the database with institutions saved in fileName
     """
+    with open(filename, 'r', newline='') as institutes_file:
+        reader = list(csv.reader(institutes_file, delimiter=';'))
+        rows = reader[1:]
 
-    rowsInserted = 0
-    cursor = db.cursor()
-    cursor.execute("BEGIN")
+    bank_map = {row[0]: {"bic": row[14], "name": f"{row[8]} ({row[12]})"} for row in rows}
 
-    def existCode(bankCode, bic):
-        cursor.execute("SELECT bankcode,bic FROM institutions WHERE bankcode = ? and bic = ?",(bankCode,bic,))
-        row_exist = cursor.fetchone()
-        if row_exist is None:
-            return False
+    to_insert = []
+    for row in rows:
+        bankcode = row[0].zfill(5)
 
-        return True
+        # Non-concatenated "parent" entries
+        if row[2] == 'N':
+            bic = row[14]
+            name = f"{row[8]} ({row[12]})"
+        # Some bankcodes are concatenated onto other bankcodes without the BIC or other
+        # institution info on their line, so we must get these from the parent entry
+        else:
+            parent_bankcode = row[3]
+            parent_info = bank_map.get(parent_bankcode)
+            if parent_info:
+                bic = parent_info["bic"]
+                name = parent_info["name"]
+            else:
+                continue
 
-    def submitInstitute(bankCode, bankName, bic):
-        if(not existCode(bankCode, bic)):
-            try:
-                cursor.execute("INSERT INTO institutions (bankcode, bic, name) VALUES(?,?,?)", (bankCode, bic, bankName))
-            except sqlite3.Error as e:
-                print("Error: {0} while inserting {1} ({2})".format(e.args[0], bankCode, bic))
+        to_insert.append((bankcode, bic, name))
 
-    institutesFile = codecs.open(fileName, "r", encoding=args.encoding)
-    for institute in institutesFile:
-        bic = institute[284:295].strip()
-        if len(bic) > 0:
-            bcNumber = "{:0>5}".format(institute[2:7].strip() if institute[11:16] == "     " else institute[11:16].strip())
-            name = "%s (%s)" % (institute[54:114].strip(), institute[194:229].strip())
-            submitInstitute(bcNumber, name, bic)
-            rowsInserted += 1
+    cursor = db.cursor()
+    cursor.execute("BEGIN")
+    try:
+        cursor.executemany(
+            "INSERT OR IGNORE INTO institutions (bankcode, bic, name) VALUES (?, ?, ?)",
+            to_insert
+        )
+        db.commit()
+        return cursor.rowcount
+    except sqlite3.Error as e:
+        db.rollback()
+        print(f"Database error: {e}")
+        return 0
 
-    db.commit()
-    return rowsInserted
-
-
 if __name__ == '__main__':
     parser = argparse.ArgumentParser(description="Creates a SQLite database for KMyMoney with information about IBAN and BICs based on a swiss BC-Bankenstamm file."
-        " You can get the BC-Bankenstamm file from https://www.six-group.com/interbank-clearing/de/home/bank-master-data/download-bc-bank-master.html"
+        " You can get the BC-Bankenstamm file from https://api.six-group.com/api/epcd/bankmaster/v2/public/downloads/bcbankenstamm"
     )
 
     parser.add_argument(dest='file', help='File to load')
     parser.add_argument('-o', '--output', default="bankdata.ch.db", help='SQLite database to open/generate')
-    parser.add_argument('-e', '--encoding', default="iso 8859-15", help='Charset of file')
     args = parser.parse_args()
 
-    print("Read data from \"{0}\" with \"{1}\" encoding".format(args.file, args.encoding))
+    print(f'Read data from "{args.file}"')
     db = sqlite3.connect(args.output)
 
-    createTable()
-    institutions = processFile(args.file)
-    print("Inserted {0} institutions into database \"{1}\"".format(institutions, args.output))
+    create_table()
+    institutions = process_file(args.file)
+    print(f'Inserted {institutions} institutions into database "{args.output}"')
 
     cursor = db.cursor()
     cursor.execute("ANALYZE institutions")
