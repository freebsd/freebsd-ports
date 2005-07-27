--- xmlparser/Module.mk.orig	Tue Feb 22 17:32:18 2005
+++ xmlparser/Module.mk	Tue Feb 22 17:32:42 2005
@@ -67,4 +67,4 @@
 
 ##### extra rules ######
 $(XMLO): %.o: %.cxx
-	$(CXX) $(OPT) $(CXXFLAGS) -I$(XMLINCDIR) -o $@ -c $<
+	$(CXX) $(OPT) $(CXXFLAGS) -I$(XMLINCDIR) -I/usr/local/include -o $@ -c $<
