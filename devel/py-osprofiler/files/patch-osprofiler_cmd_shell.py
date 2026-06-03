--- osprofiler/cmd/shell.py.orig	2026-05-05 14:09:04 UTC
+++ osprofiler/cmd/shell.py
@@ -54,7 +54,9 @@ class OSProfilerShell:
     def _append_subcommands(
         self, parent_parser: argparse.ArgumentParser
     ) -> None:
-        subcommands = parent_parser.add_subparsers(help="<subcommands>")
+        # Fix CLI for Python 3.x
+        subcommands = parent_parser.add_subparsers(help="<subcommands>", dest="too few arguments")
+        subcommands.required = True
         for group_cls in commands.BaseCommand.__subclasses__():
             if group_cls.group_name is None:
                 continue
