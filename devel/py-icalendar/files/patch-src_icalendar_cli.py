--- src/icalendar/cli.py.orig	2018-06-20 12:52:55 UTC
+++ src/icalendar/cli.py
@@ -86,6 +86,7 @@ def main():
     # This seems a bit of an overkill now, but we will probably add more
     # functionality later, e.g., iCalendar to JSON / YAML and vice versa.
     subparsers = parser.add_subparsers(dest='subcommand')
+    subparsers.required = True
 
     subparser = subparsers.add_parser(
         'view', description=view.__doc__.split('\n\n')[0])
