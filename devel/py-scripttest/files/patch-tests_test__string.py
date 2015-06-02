--- tests/test_string.py.orig	2015-06-02 05:43:40 UTC
+++ tests/test_string.py
@@ -22,8 +22,8 @@ else:
     utf8_str = 'Björk Guðmundsdóttir [ˈpjœr̥k ˈkvʏðmʏntsˌtoʊhtɪr]'
 
 
-py2only = pytest.mark.skipif("sys.version_info >= (3, 0)")
-py3only = pytest.mark.skipif("sys.version_info < (3, 0)")
+py2only = pytest.mark.skipif("sys.version_info >= (3, 0)",reason="Python 2.x Only")
+py3only = pytest.mark.skipif("sys.version_info < (3, 0)",reason="Python 3.x Only")
 
 
 #-----------------------------------------
