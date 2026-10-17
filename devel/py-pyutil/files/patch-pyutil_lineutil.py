Description: lineify_file() opened its input with the 'rU' mode, which
  Python 3.11 removed, and wrote str to a binary file. Read and write text
  as latin-1, which passes every byte through unchanged as the Python 2
  code did; universal newlines still normalize the line endings.
Issue ID: to be filed upstream
Changeset: none (upstream master has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- pyutil/lineutil.py.orig	2022-12-26 22:48:41 UTC
+++ pyutil/lineutil.py
@@ -13,10 +13,11 @@ def lineify_fileobjs(ifo, ofo, strip=Fal
 			ofo.write(pop_trailing_newlines(sl) + '\n')
 
 def lineify_file(fname, strip=False, nobak=True):
-	f = open(fname, "rU")
+	# latin-1 passes any byte through unchanged, as the Python 2 code did
+	f = open(fname, "r", encoding="latin-1")
 	from pyutil.fileutil import ReopenableNamedTemporaryFile
 	rntf = ReopenableNamedTemporaryFile()
-	fo = open(rntf.name, "wb")
+	fo = open(rntf.name, "w", encoding="latin-1", newline="\n")
 	for l in f:
 		if strip:
 			l = l.strip() + '\n'
