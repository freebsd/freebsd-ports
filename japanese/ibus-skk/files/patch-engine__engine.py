--- ./engine/engine.py.orig	2009-12-31 12:20:19.000000000 +0900
+++ ./engine/engine.py	2010-01-04 16:40:51.000000000 +0900
@@ -126,7 +126,6 @@
                                   skk.CandidateSelector.PAGINATION_START)
         self.__lookup_table = ibus.LookupTable(page_size=page_size,
                                                round=False,
-                                               orientation=0,
                                                labels=labels)
         self.__candidate_selector = CandidateSelector(self.__lookup_table,
                                                       self.__select_keys,
