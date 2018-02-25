--- Mailman/htmlformat.py.orig	2011-12-11 07:56:23 UTC
+++ Mailman/htmlformat.py
@@ -621,13 +621,13 @@ class DefinitionList(Container):
 #
 from mm_cfg import MAILMAN_URL
 PYTHON_URL  = 'http://www.python.org/'
-GNU_URL     = 'http://www.gnu.org/'
+FREEBSD_URL = 'http://www.freebsd.org/'
 
 # The names of the image logo files.  These are concatentated onto
 # mm_cfg.IMAGE_LOGOS (not urljoined).
 DELIVERED_BY = mm_cfg.DELIVERED_BY         # 'mailman.jpg'
 PYTHON_POWERED = mm_cfg.PYTHON_POWERED     # 'PythonPowered.png'
-GNU_HEAD = mm_cfg.GNU_HEAD                 # 'gnu-head-tiny.jpg'
+FREEBSD_POWERED = mm_cfg.FREEBSD_POWERED   # 'powerlogo.gif'
 
 
 def MailmanLogo():
@@ -641,18 +641,18 @@ def MailmanLogo():
         pylink = '<img src="%s" alt="Python Powered" ' \
                  'title="Python Powered" border=0>' % \
                  logo(PYTHON_POWERED)
-        gnulink = '<img src="%s" alt="GNU\'s Not Unix" ' \
-                  'title="GNU\'s Not Unix" border=0>' % \
-                  logo(GNU_HEAD)
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = '<img src="%s" alt="Powered by FreeBSD" ' \
+                 'title="Powered by FreeBSD" border=0>' % \
+                 logo(FREEBSD_POWERED)
+        t.AddRow([mmlink, pylink, freebsdlink])
     else:
         # use only textual links
         version = mm_cfg.VERSION
         mmlink = Link(MAILMAN_URL,
                       _('Delivered by Mailman<br>version %(version)s'))
         pylink = Link(PYTHON_URL, _('Python Powered'))
-        gnulink = Link(GNU_URL, _("Gnu's Not Unix"))
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = Link(FREEBSD_URL, _("Powered by FreeBSD"))
+        t.AddRow([mmlink, pylink, freebsdlink])
     return t
 
 
