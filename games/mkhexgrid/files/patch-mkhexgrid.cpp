--- mkhexgrid.cpp.orig	2007-01-10 16:37:42.000000000 +0300
+++ mkhexgrid.cpp	2009-02-28 05:14:36.000000000 +0300
@@ -148,7 +148,7 @@
       Grid g(opt);
       g.draw();
    }
-   catch (exception &e) {
+   catch (std::exception &e) {
       cerr << argv[0] << ": " << e.what() << endl;
       exit(1);
    }
