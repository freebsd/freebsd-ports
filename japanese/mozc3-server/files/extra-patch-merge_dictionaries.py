--- merge_dictionaries.py.orig	2026-04-08 01:20:27.000000000 +0900
+++ merge_dictionaries.py	2026-04-13 09:21:07.954381000 +0900
@@ -11,12 +11,11 @@
 import json
 import re
 import sys
-import urllib.request
+import os
 import xml.etree.ElementTree as ET
 from datetime import datetime
 from pathlib import Path
 from unicodedata import normalize
-from zipfile import ZipFile
 
 
 def main():
@@ -35,7 +35,7 @@
     with open(file_ut, 'w', encoding='utf-8') as file:
         for entry in ut_entry:
             entry[1] = entry[2] = id_mozc
-            file.write(f'{'\t'.join(entry)}\n')
+            file.write('\t'.join(entry) + '\n')
 
 
 def get_ut_entry(file_ut):
@@ -64,64 +63,44 @@
 
 
 def get_mozc_entry():
-    # Mozc の最終コミット日を取得
-    url = 'https://api.github.com/repos/google/mozc/commits/master'
 
-    with urllib.request.urlopen(url) as response:
-        data = json.loads(response.read().decode())
-        date_str = data['commit']['committer']['date']
+    # 一般名詞の ID を取得
+    with open("id.def", "r") as file:
+        for line in file:
+            if ' 名詞,一般,' in line:
+                id_mozc = line.split(' 名詞,一般,')[0]
+                break
 
-    date_str = datetime.fromisoformat(date_str)
-    date_str = date_str.strftime('%Y%m%d')
+    # Mozc 辞書のファイルリストを取得
+    all_files = os.listdir('%%WRKSRC%%/src/data/dictionary_oss/')
+    dict_path = '%%WRKSRC%%/src/data/dictionary_oss/dictionary0'
+    dict_files = [f for f in all_files if f.startswith(dict_path)]
 
-    # Mozc のアーカイブを取得
-    url = 'https://github.com/google/mozc/archive/refs/heads/master.zip'
+    # Mozc 辞書のエントリを取得
+    mozc_entry = []
 
-    if not Path(f'mozc-{date_str}.zip').exists():
-        urllib.request.urlretrieve(
-                url, f'mozc-{date_str}.zip')
+    for dict_file in dict_files:
+        with open(dict_file, "r") as file:
+            # バイナリストリームをテキストストリームに変換
+            file_text = io.TextIOWrapper(file, encoding='utf-8')
+            reader = csv.reader(file_text, delimiter='\t')
+            mozc_entry.extend(list(reader))
 
-    with ZipFile(f'mozc-{date_str}.zip') as zip_ref:
-        # 一般名詞の ID を取得
-        with zip_ref.open(
-                'mozc-master/src/data/dictionary_oss/id.def') as file:
-            for line in file:
-                line = line.decode()
+    mozc_entry_mod = []
 
-                if ' 名詞,一般,' in line:
-                    id_mozc = line.split(' 名詞,一般,')[0]
-                    break
+    for entry in mozc_entry:
+        yomi, id1, id2, cost, hyouki = entry[:5]
 
-        # Mozc 辞書のファイルリストを取得
-        all_files = zip_ref.namelist()
-        dict_path = 'mozc-master/src/data/dictionary_oss/dictionary0'
-        dict_files = [f for f in all_files if f.startswith(dict_path)]
+        # 不要な表記をスキップ
+        hyouki = remove_short_or_long_hyouki(hyouki)
+        if not hyouki:
+            continue
 
-        # Mozc 辞書のエントリを取得
-        mozc_entry = []
+        # 表記を正規化
+        hyouki = normalize_entry(hyouki)
 
-        for dict_file in dict_files:
-            with zip_ref.open(dict_file) as file:
-                # バイナリストリームをテキストストリームに変換
-                file_text = io.TextIOWrapper(file, encoding='utf-8')
-                reader = csv.reader(file_text, delimiter='\t')
-                mozc_entry.extend(list(reader))
+        mozc_entry_mod.append([yomi, id1, id2, cost, hyouki])
 
-        mozc_entry_mod = []
-
-        for entry in mozc_entry:
-            yomi, id1, id2, cost, hyouki = entry[:5]
-
-            # 不要な表記をスキップ
-            hyouki = remove_short_or_long_hyouki(hyouki)
-            if not hyouki:
-                continue
-
-            # 表記を正規化
-            hyouki = normalize_entry(hyouki)
-
-            mozc_entry_mod.append([yomi, id1, id2, cost, hyouki])
-
     return mozc_entry_mod, id_mozc
 
 
@@ -148,43 +127,9 @@
 
 
 def generate_jawiki_hit_dict():
-    # jawiki-*-multistream-index.txt.bz2 を取得
-    url = 'https://dumps.wikimedia.org/jawiki/latest/' + \
-        'jawiki-latest-pages-articles-multistream-index.txt.bz2-rss.xml'
-
-    headers = {
-        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
-        Chrome/91.0.4472.124"}
-
-    try:
-        req = urllib.request.Request(url, headers=headers)
-        with urllib.request.urlopen(req) as response:
-            root = ET.fromstring(response.read().decode())
-    except urllib.error.HTTPError as e:
-        print(f'Error: {e.code}')
-
-    description_text = root.find('.//item/description').text
-    url = re.search(r'href="([^"]+)"', description_text).group(1)
-
-    jawiki_index_file = url.rsplit('/', 1)[1]
-
-    if not Path(jawiki_index_file).exists():
-        try:
-            req = urllib.request.Request(url, headers=headers)
-            with urllib.request.urlopen(req) as response, \
-                    open(jawiki_index_file, "wb") as out_file:
-                # 1MB ずつ書き込む
-                while True:
-                    chunk = response.read(1024 * 1024)
-                    if not chunk:
-                        break
-                    out_file.write(chunk)
-        except urllib.error.HTTPError as e:
-            print(f'Error: {e.code}')
-
     jawiki_index = []
 
-    with bz2.open(jawiki_index_file, 'rt', encoding='utf-8') as file:
+    with bz2.open('jawiki-latest-pages-articles-multistream-index.txt.bz2', 'rt', encoding='utf-8') as file:
         entry_to_skip = (
             'ファイル:', 'Wikipedia:', 'Template:', 'Portal:',
             'Help:', 'Category:', 'プロジェクト:', '曖昧さ回避')
