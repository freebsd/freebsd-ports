--- docs/guesswork.rst.orig	2019-01-27 13:48:05 UTC
+++ docs/guesswork.rst
@@ -54,6 +54,34 @@ filename as described above.
 
 .. _dateparser: https://github.com/scrapinghub/dateparser/blob/v0.7.0/docs/usage.rst#settings
 
+Transforming filenames for parsing
+----------------------------------
+Some devices can't produce filenames that can be parsed by the default
+parser. By configuring the option ``PAPERLESS_FILENAME_PARSE_TRANSFORMS`` in
+``paperless.conf`` one can add transformations that are applied to the filename
+before it's parsed.
+
+The option contains a list of dictionaries of regular expressions (key:
+``pattern``) and replacements (key: ``repl``) in JSON format, which are
+applied in order by passing them to ``re.subn``. Transformation stops
+after the first match, so at most one transformation is applied. The general
+syntax is
+
+.. code:: python
+
+   [{"pattern":"pattern1", "repl":"repl1"}, {"pattern":"pattern2", "repl":"repl2"}, ..., {"pattern":"patternN", "repl":"replN"}]
+
+The example below is for a Brother ADS-2400N, a scanner that allows
+different names to different hardware buttons (useful for handling
+multiple entities in one instance), but insists on adding ``_<count>``
+to the filename.
+
+.. code:: python
+
+   # Brother profile configuration, support "Name_Date_Count" (the default
+   # setting) and "Name_Count" (use "Name" as tag and "Count" as title).
+   PAPERLESS_FILENAME_PARSE_TRANSFORMS=[{"pattern":"^([a-z]+)_(\\d{8})_(\\d{6})_([0-9]+)\\.", "repl":"\\2\\3Z - \\4 - \\1."}, {"pattern":"^([a-z]+)_([0-9]+)\\.", "repl":" - \\2 - \\1."}]
+
 .. _guesswork-content:
 
 Reading the Document Contents
