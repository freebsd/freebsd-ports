--- lib/viewcvs.py.orig	Tue Jan 15 09:35:55 2002
+++ lib/viewcvs.py	Sun Jan  9 13:35:45 2005
@@ -174,6 +174,10 @@
     # parse the query params into a dictionary (and use defaults)
     query_dict = default_settings.copy()
     for name, values in cgi.parse().items():
+      # validate the parameter
+      _validate_param(name, values[0])
+
+      # if we're here, then the parameter is okay
       query_dict[name] = values[0]
 
     # set up query strings, prefixed by question marks and ampersands
@@ -229,6 +233,77 @@
     self.taginfo = taginfo
 
 
+def _validate_param(name, value):
+  """Validate whether the given value is acceptable for the param name.
+
+  If the value is not allowed, then an error response is generated, and
+  this function throws an exception. Otherwise, it simply returns None.
+  """
+
+  try:
+    validator = _legal_params[name]
+  except KeyError:
+    error('An illegal parameter name ("%s") was passed.' % cgi.escape(name))
+
+  # is the validator a regex?
+  if hasattr(validator, 'match'):
+    if not validator.match(value):
+      error('An illegal value ("%s") was passed as a parameter.' %
+            cgi.escape(value))
+    return
+
+  # the validator must be a function
+  validator(value)
+
+def _validate_cvsroot(value):
+  if not cfg.general.cvs_roots.has_key(value):
+    error('The CVS root "%s" is unknown.' % cgi.escape(value))
+
+def _validate_regex(value):
+  # hmm. there isn't anything that we can do here.
+
+  ### we need to watch the flow of these parameters through the system
+  ### to ensure they don't hit the page unescaped. otherwise, these
+  ### parameters could constitute a CSS attack.
+  pass
+
+# obvious things here. note that we don't need uppercase for alpha.
+_re_validate_alpha = re.compile('^[a-z]+$')
+_re_validate_number = re.compile('^[0-9]+$')
+
+# when comparing two revs, we sometimes construct REV:SYMBOL, so ':' is needed
+_re_validate_revnum = re.compile('^[-_.a-zA-Z0-9:]+$')
+
+# it appears that RFC 2045 also says these chars are legal: !#$%&'*+^{|}~`
+# but woah... I'll just leave them out for now
+_re_validate_mimetype = re.compile('^[-_.a-zA-Z0-9/]+$')
+
+# the legal query parameters and their validation functions
+_legal_params = {
+  'cvsroot'       : _validate_cvsroot,
+  'search'        : _validate_regex,
+
+  'hideattic'     : _re_validate_number,
+  'sortby'        : _re_validate_alpha,
+  'sortdir'       : _re_validate_alpha,
+  'logsort'       : _re_validate_alpha,
+  'diff_format'   : _re_validate_alpha,
+  'only_with_tag' : _re_validate_revnum,
+  'dir_pagestart' : _re_validate_number,
+  'log_pagestart' : _re_validate_number,
+  'hidecvsroot'   : _re_validate_number,
+  'annotate'      : _re_validate_revnum,
+  'graph'         : _re_validate_revnum,
+  'makeimage'     : _re_validate_number,
+  'tarball'       : _re_validate_number,
+  'r1'            : _re_validate_revnum,
+  'tr1'           : _re_validate_revnum,
+  'r2'            : _re_validate_revnum,
+  'tr2'           : _re_validate_revnum,
+  'rev'           : _re_validate_revnum,
+  'content-type'  : _re_validate_mimetype,
+  }
+
 class LogEntry:
   "Hold state for each revision entry in an 'rlog' output."
   def __init__(self, rev, date, author, state, changed, log):
@@ -478,7 +553,7 @@
 def markup_stream_enscript(lang, fp):
   sys.stdout.flush()
   enscript = popen.pipe_cmds([(os.path.normpath(os.path.join(cfg.options.enscript_path,'enscript')),
-                               '--color', '-W', 'html', '-E' + lang, '-o',
+                               '--color', '--language=html', '-E' + lang, '-o',
                                '-', '-'),
                               ('sed', '-n', '/^<PRE>$/,/<\\/PRE>$/p')])
 
@@ -494,7 +569,7 @@
   except IOError, v:
     print "<h3>Failure during use of an external program:</h3>"
     print "<pre>"
-    print os.path.normpath(os.path.join(cfg.options.enscript_path,'enscript')) + " --color -W html -E"+lang+" -o - -"
+    print os.path.normpath(os.path.join(cfg.options.enscript_path,'enscript')) + " --color --language=html -E"+lang+" -o - -"
     print "</pre>"
     raise
 
