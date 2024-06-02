--- breezy/_rio_py.py.orig	2021-12-07 02:24:26 UTC
+++ breezy/_rio_py.py
@@ -17,6 +17,7 @@ import re
 """Python implementation of _read_stanza_*."""
 
 import re
+from typing import Iterator, Optional
 
 from .rio import (
     Stanza,
@@ -25,13 +26,13 @@ _tag_re = re.compile(r'^[-a-zA-Z0-9_]+$')
 _tag_re = re.compile(r'^[-a-zA-Z0-9_]+$')
 
 
-def _valid_tag(tag):
+def _valid_tag(tag: str) -> bool:
     if not isinstance(tag, str):
         raise TypeError(tag)
     return bool(_tag_re.match(tag))
 
 
-def _read_stanza_utf8(line_iter):
+def _read_stanza_utf8(line_iter: Iterator[bytes]) -> Optional[Stanza]:
     stanza = Stanza()
     tag = None
     accum_value = None
@@ -67,7 +68,7 @@ def _read_stanza_utf8(line_iter):
             accum_value = [line[colon_index + 2:-1]]
 
     if tag is not None:  # add last tag-value
-        stanza.add(tag, u''.join(accum_value))
+        stanza.add(tag, u''.join(accum_value))  # type: ignore
         return stanza
     else:     # didn't see any content
         return None
