Description: Fix pg_dotconf -f/--file: it referenced the undefined names
  comment and unquote (NameError) instead of configfile.comment and
  configfile.unquote, and tested the first character of the key rather than
  the text before it, so commented-out settings in the file were not
  skipped.
Issue ID: https://github.com/python-postgres/fe/pull/130
Changeset: none

--- postgresql/bin/pg_dotconf.py.orig	2012-07-28 21:28:08 UTC
+++ postgresql/bin/pg_dotconf.py
@@ -39,8 +39,8 @@ def command(args):
 			for line in sf:
 				pl = configfile.parse_line(line)
 				if pl is not None:
-					if comment not in line[pl[0].start]:
-						settings[line[pl[0]]] = unquote(line[pl[1]])
+					if configfile.comment not in line[:pl[0].start]:
+						settings[line[pl[0]]] = configfile.unquote(line[pl[1]])
 
 	prev = None
 	for p in ca[1:]:
