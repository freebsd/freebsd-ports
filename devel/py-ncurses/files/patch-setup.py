--- setup.py.orig	Tue Jun 18 08:26:48 2002
+++ setup.py	Tue Jun 18 08:27:09 2002
@@ -44,15 +44,15 @@
              }),
             ('ncurses._panel',
              { 'sources': ['ncurses/_panel_wrap.c'],
-               'libraries': ['panel']
+               'libraries': ['panel', 'ncurses']
              }),
             ('ncurses._menu',
              { 'sources': ['ncurses/_menu_wrap.c'],
-               'libraries': ['menu']
+               'libraries': ['menu', 'ncurses']
              }),
             ('ncurses._form',
              { 'sources': ['ncurses/_form_wrap.c'],
-               'libraries': ['form']
+               'libraries': ['form', 'ncurses']
              }),
             ]
       )
