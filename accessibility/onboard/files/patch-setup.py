--- setup.py.orig	2026-04-11 20:15:35 UTC
+++ setup.py
@@ -160,7 +160,7 @@ def clean_before_build(command):
     if command in ["build", "build_ext", "clean", "sdist"]:
         print("removing __pycache__ directories recursively")
         subprocess.check_call(
-         ['/bin/bash', '-c', "find . -name '__pycache__*' -prune | xargs rm -rf"])
+         ['/bin/sh', '-c', "find . -name '__pycache__*' -prune | xargs rm -rf"])
 
     # Symlinked extension libraries trip up "setup.py sdist". Delete them.
     if command in ["clean", "sdist"]:
@@ -313,8 +313,7 @@ class Extension_lm(Extension):
                            libraries = [],
                            define_macros=[('NDEBUG', '1')],
                            extra_compile_args=[
-                               "-Wsign-compare",
-                               "-Wlogical-op"],
+                               "-Wsign-compare"],
                           )
 
 extension_lm = Extension_lm("Onboard", "Onboard")
@@ -401,7 +400,7 @@ class build_i18n_custom(DistUtilsExtra.auto.build_i18n
             # Get the autostart directory
             autostart_destination = os.path.join(config_path, "autostart") 
         else:
-            autostart_destination = '/etc/xdg/autostart'
+            autostart_destination = 'etc/xdg/autostart'
   
 
         for i, file_set in enumerate(self.distribution.data_files):
@@ -439,33 +438,6 @@ class CustomInstallCommand(install):
         # Run the default installation
         install.run(self)
 
-        # Only run this if NOT inside a fakeroot environment
-        if not os.getenv("FAKEROOTKEY"):
-            print("Running tools/gen_gschema.py...")
-            
-
-
-            # Correct install base from setuptools
-            install_base = Path(self.install_data)
-            schema_dir = install_base / "share" / "glib-2.0" / "schemas"
-                
-
-            # Ensure the schema directory exists
-            schema_dir.mkdir(parents=True, exist_ok=True)
-            
-            print("Running glib-compile-schemas...")
-
-            try:
-                if os.path.exists(schema_dir):
-                    subprocess.check_call(["glib-compile-schemas", schema_dir])
-                else:
-                    print(f"Warning: Schema directory not found: {schema_dir}")
-            except subprocess.CalledProcessError as e:
-                print(f"Error running glib-compile-schemas: {e}")
-                sys.exit(1)
-        else:
-            print("Skipping tools/gen_gschema.py and glib-compile-schemas since this is a fakeroot environment.")
-
 class UninstallCommand(Command):
     """Custom uninstall command to remove all installed files"""
 
@@ -621,16 +593,8 @@ DistUtilsExtra.auto.setup(
     description = 'Simple On-screen Keyboard',
 
     packages = ['Onboard', 'Onboard.pypredict'],
-    data_files = [('share/glib-2.0/schemas', glob.glob('data/*.gschema.xml')),
+    data_files = [('share/glib-2.0/schemas', glob.glob('data/org.onboard.gschema.xml')),
                   ('share/dbus-1/services', glob.glob('data/org.onboard.Onboard.service')),
-                  ('share/doc/onboard', glob.glob('AUTHORS')),
-                  ('share/doc/onboard', glob.glob('CHANGELOG')),
-                  ('share/doc/onboard', glob.glob('COPYING*')),
-                  ('share/doc/onboard', glob.glob('HACKING')),
-                  ('share/doc/onboard', glob.glob('DBUS.md')),
-                  ('share/doc/onboard', glob.glob('README.md')),
-                  ('share/doc/onboard', glob.glob('onboard-defaults.conf.example')),
-                  ('share/doc/onboard', glob.glob('onboard-default-settings.gschema.override.example')),
                   ('share/icons/hicolor/16x16/apps', glob.glob('icons/hicolor/16/*')),
                   ('share/icons/hicolor/22x22/apps', glob.glob('icons/hicolor/22/*')),
                   ('share/icons/hicolor/24x24/apps', glob.glob('icons/hicolor/24/*')),
@@ -650,17 +614,13 @@ DistUtilsExtra.auto.setup(
                   ('share/onboard/models', glob.glob('models/*.lm')),
                   ('share/onboard/tools', glob.glob('Onboard/pypredict/tools/checkmodels')),
                   ('share/onboard/emojione/svg', glob.glob('emojione/svg/*.svg')),
-                  ('share/gnome-shell/extensions/Onboard_Indicator@onboard.org',
-                      glob_files('gnome/{}/Onboard_Indicator@onboard.org/*'.format(gnome_shell_version))),
-                  ('share/gnome-shell/extensions/Onboard_Indicator@onboard.org/schemas',
-                      glob_files('gnome/{}/Onboard_Indicator@onboard.org/schemas/*'.format(gnome_shell_version))),
                  ],
 
     scripts = ['onboard', 'onboard-settings'],
 
     options={
         'build_scripts': {
-            'executable': '/usr/bin/python3'
+            'executable': '%%PYTHON_CMD%%'
         }
     },
     
