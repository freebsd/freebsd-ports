# Fix pytest test collection conflict with helper function
#
# The function 'test_slicing(sequence, slicer)' starts with 'test_' so pytest
# automatically collects it as a test function. However, it's actually a helper
# function that takes parameters, which pytest interprets as fixtures.
# Since these fixtures don't exist, pytest fails with "fixture not found".
#
# This helper function is meant to be called from test_sequence() with specific
# arguments, not discovered and run independently by pytest.
#
# Solution: Rename to '_test_slicing()' (underscore prefix) so pytest ignores it
# during auto-discovery, then update all calls to use the new name.
#
--- memory_graph/test_sequence.py.orig	2025-10-04 13:43:50.616552000 -0700
+++ memory_graph/test_sequence.py	2025-10-04 13:44:02.505010000 -0700
@@ -10,7 +10,7 @@
         return index[0]
     return index
 
-def test_slicing(sequence, slicer):
+def _test_slicing(sequence, slicer):
     print(sequence)
     print(slicer)
     for i in sequence.indices_all():
@@ -25,13 +25,13 @@
 def test_sequence():
     sequence = Sequence1D([i for i in range(8)])
     slicer = Slicer(2,3)
-    test_slicing(sequence, slicer)
+    _test_slicing(sequence, slicer)
 
     width = 5
     height = 6
     sequence = Sequence2D([[x+y*width for x in range(width)] for y in range(height)])
     slicer = (Slicer(1,2), Slicer(2,1))
-    test_slicing(sequence, slicer)
+    _test_slicing(sequence, slicer)
 
 if __name__ == '__main__':
     test_sequence()
