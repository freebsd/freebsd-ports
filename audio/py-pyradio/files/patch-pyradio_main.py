--- pyradio/main.py.orig	2025-09-02 14:51:30 UTC
+++ pyradio/main.py
@@ -667,7 +667,8 @@ If nothing else works, try the following command:
         if args.version:
             pyradio_config.get_pyradio_version()
             print(f'PyRadio version: [green]{pyradio_config.current_pyradio_version}[/green]')
-            print(f"Python version: [green]{sys.version.replace('\\n', ' ').replace('\\r', ' ')}[/green]")
+            ver = sys.version.replace('\\n', ' ').replace('\\r', ' ')
+            print(f"Python version: [green]{ver}[/green]")
             if pyradio_config.distro != 'None':
                 print(f'Distribution: [green]{pyradio_config.distro}[/green]')
             return
