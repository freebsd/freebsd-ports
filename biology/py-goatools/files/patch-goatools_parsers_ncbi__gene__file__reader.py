Description: Wrap dict.items() in list() before indexing; dict views are
  not subscriptable on Python 3, so convert_ints_floats() raised TypeError
  whenever a 'chromosome' or 'Chr' column was read.
Issue ID: none (not yet reported)
Changeset: none (still present on upstream main 4cd1c71)
TODO: Report upstream (upstream is alive); drop once a release fixes it.

--- goatools/parsers/ncbi_gene_file_reader.py.orig	2024-05-05 14:48:29 UTC
+++ goatools/parsers/ncbi_gene_file_reader.py
@@ -227,7 +227,7 @@ class NCBIgeneFileReader:
             #print 'idx={} ({}) {}'.format(idx, flds[idx], flds) # DVK
             flds[idx] = int(flds[idx]) if dig.isdigit() else dig
         for idx in self.idxs_strpat:
-            hdr = self.hdr2idx.items()[idx][0]
+            hdr = list(self.hdr2idx.items())[idx][0]
             pat = self.strpat_hdrs[hdr]
             flds[idx] = pat.format(flds[idx])
 
