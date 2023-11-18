--- src/calibre/db/notes/exim.py.orig	2023-11-17 06:02:05 UTC
+++ src/calibre/db/notes/exim.py
@@ -41,7 +41,7 @@ def export_note(note_doc: str, get_resource) -> str:
     return html.tostring(root, encoding='unicode')
 
 
-def import_note(shtml: str | bytes, basedir: str, add_resource) -> tuple[str, str, set[str]]:
+def import_note(shtml: "str | bytes", basedir: str, add_resource) -> tuple[str, str, set[str]]:
     shtml = xml_to_unicode(shtml, strip_encoding_pats=True, assume_utf8=True)[0]
     basedir = os.path.normcase(get_long_path_name(os.path.abspath(basedir)) + os.sep)
     root = parse_html(shtml)
