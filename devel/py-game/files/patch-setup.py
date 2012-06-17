--- setup.py.orig	2009-08-06 10:28:54.000000000 +0200
+++ setup.py	2012-06-12 20:31:52.000000000 +0200
@@ -173,9 +173,9 @@
 data_files = [('pygame', pygame_data_files)]
 
 #add files in distribution directory
-pygame_data_files.append('LGPL')
-pygame_data_files.append('readme.html')
-pygame_data_files.append('install.html')
+#pygame_data_files.append('LGPL')
+#pygame_data_files.append('readme.html')
+#pygame_data_files.append('install.html')
 
 #add non .py files in lib directory
 for f in glob.glob(os.path.join('lib', '*')):
@@ -183,50 +183,50 @@
         pygame_data_files.append(f)
 
 #tests/fixtures
-add_datafiles(data_files, 'pygame/tests',
-              ['test',
-                  [['fixtures',
-                      [['xbm_cursors',
-                          ['*.xbm']]]]]])
+#add_datafiles(data_files, 'pygame/tests',
+#              ['test',
+#                  [['fixtures',
+#                      [['xbm_cursors',
+#                          ['*.xbm']]]]]])
 
 #examples
-add_datafiles(data_files, 'pygame/examples',
-              ['examples',
-                  ['readme.txt',
-                   ['data',
-                       ['*']],
-                   ['macosx',
-                       ['*.py',
-                        ['aliens_app_example',
-                            ['*.py',
-                             'README.txt',
-                             ['English.lproj',
-                                 ['aliens.icns',
-                                  ['MainMenu.nib',
-                                      ['*']]]]]]]]]])
+#add_datafiles(data_files, 'pygame/examples',
+#              ['examples',
+#                  ['readme.txt',
+#                   ['data',
+#                       ['*']],
+#                   ['macosx',
+#                       ['*.py',
+#                        ['aliens_app_example',
+#                            ['*.py',
+#                             'README.txt',
+#                             ['English.lproj',
+#                                 ['aliens.icns',
+#                                  ['MainMenu.nib',
+#                                      ['*']]]]]]]]]])
 
 #docs
-add_datafiles(data_files, 'pygame/docs',
-              ['docs',
-                  ['*.html',
-                   '*.gif',
-                   ['ref',
-                       ['*.html']],
-                   ['tut',
-                       ['*.html',
-                        ['chimp',
-                            ['*.html',
-                             '*.gif']],
-                        ['intro',
-                            ['*.html',
-                             '*.gif',
-                             '*.jpg']],
-                        ['surfarray',
-                            ['*.html',
-                             '*.jpg']],
-                        ['tom',
-                            ['*.html',
-                             '*.png']]]]]])
+#add_datafiles(data_files, 'pygame/docs',
+#              ['docs',
+#                  ['*.html',
+#                   '*.gif',
+#                   ['ref',
+#                       ['*.html']],
+#                   ['tut',
+#                       ['*.html',
+#                        ['chimp',
+#                            ['*.html',
+#                             '*.gif']],
+#                        ['intro',
+#                            ['*.html',
+#                             '*.gif',
+#                             '*.jpg']],
+#                        ['surfarray',
+#                            ['*.html',
+#                             '*.jpg']],
+#                        ['tom',
+#                            ['*.html',
+#                             '*.png']]]]]])
               
 #required. This will be filled if doing a Windows build.
 cmdclass = {}
@@ -461,27 +461,29 @@
 PACKAGEDATA = {
        "cmdclass":    cmdclass,
        "packages":    ['pygame', 'pygame.gp2x', 'pygame.threads',
-                       'pygame.tests',
-                       'pygame.tests.test_utils',
-                       'pygame.tests.run_tests__tests',
-                       'pygame.tests.run_tests__tests.all_ok',
-                       'pygame.tests.run_tests__tests.failures1',
-                       'pygame.tests.run_tests__tests.incomplete',
-                       'pygame.tests.run_tests__tests.infinite_loop',
-                       'pygame.tests.run_tests__tests.print_stderr',
-                       'pygame.tests.run_tests__tests.print_stdout',
-                       'pygame.tests.run_tests__tests.incomplete_todo',
-                       'pygame.tests.run_tests__tests.exclude',
-                       'pygame.tests.run_tests__tests.timeout',
-                       'pygame.tests.run_tests__tests.everything',
-                       'pygame.docs',
-                       'pygame.examples'],
+#                       'pygame.tests',
+#                       'pygame.tests.test_utils',
+#                       'pygame.tests.run_tests__tests',
+#                       'pygame.tests.run_tests__tests.all_ok',
+#                       'pygame.tests.run_tests__tests.failures1',
+#                       'pygame.tests.run_tests__tests.incomplete',
+#                       'pygame.tests.run_tests__tests.infinite_loop',
+#                       'pygame.tests.run_tests__tests.print_stderr',
+#                       'pygame.tests.run_tests__tests.print_stdout',
+#                       'pygame.tests.run_tests__tests.incomplete_todo',
+#                       'pygame.tests.run_tests__tests.exclude',
+#                       'pygame.tests.run_tests__tests.timeout',
+#                       'pygame.tests.run_tests__tests.everything',
+#                       'pygame.docs',
+#                       'pygame.examples'
+                       ],
        "package_dir": {'pygame': 'lib',
                        'pygame.threads': 'lib/threads',
                        'pygame.gp2x': 'lib/gp2x',
-                       'pygame.tests': 'test',
-                       'pygame.docs': 'docs',
-                       'pygame.examples': 'examples'},
+ #                      'pygame.tests': 'test',
+ #                      'pygame.docs': 'docs',
+ #                      'pygame.examples': 'examples'
+                       },
        "headers":     headers,
        "ext_modules": extensions,
        "data_files":  data_files,
