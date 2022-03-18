--- testing/test_parseopt.py.orig	2020-06-05 12:09:03 UTC
+++ testing/test_parseopt.py
@@ -305,7 +305,7 @@ def test_argcomplete(testdir, monkeypatch):
         # redirect output from argcomplete to stdin and stderr is not trivial
         # http://stackoverflow.com/q/12589419/1307905
         # so we use bash
-        fp.write('COMP_WORDBREAKS="$COMP_WORDBREAKS" python -m pytest 8>&1 9>&2')
+        fp.write('COMP_WORDBREAKS="$COMP_WORDBREAKS" %%PYTHON_CMD%% -m pytest 8>&1 9>&2')
     # alternative would be exteneded Testdir.{run(),_run(),popen()} to be able
     # to handle a keyword argument env that replaces os.environ in popen or
     # extends the copy, advantage: could not forget to restore
