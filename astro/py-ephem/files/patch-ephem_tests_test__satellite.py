--- ephem/tests/test_satellite.py.orig	2021-06-12 19:13:26 UTC
+++ ephem/tests/test_satellite.py
@@ -21,7 +21,7 @@ class SatelliteTests(unittest.TestCase):
         lines = list(tle_lines)
         lines[1] = lines[1][:-1] + '1'
         expected = 'incorrect TLE checksum at end of line'
-        self.assertRaisesRegexp(ValueError, expected, ephem.readtle, *lines)
+        self.assertRaisesRegex(ValueError, expected, ephem.readtle, *lines)
 
     def test_normal_methods(self):
         for which in ['previous', 'next']:
