--- osprofiler/cmd/shell.py.orig	2018-03-14 17:31:26 UTC
+++ osprofiler/cmd/shell.py
@@ -54,7 +54,9 @@ class OSProfilerShell(object):
         return parser
 
     def _append_subcommands(self, parent_parser):
-        subcommands = parent_parser.add_subparsers(help="<subcommands>")
+	# Fix CLI for Python 3.x
+        subcommands = parent_parser.add_subparsers(help="<subcommands>", dest="too few arguments")
+        subcommands.required = True
         for group_cls in commands.BaseCommand.__subclasses__():
             group_parser = subcommands.add_parser(group_cls.group_name)
             subcommand_parser = group_parser.add_subparsers()
