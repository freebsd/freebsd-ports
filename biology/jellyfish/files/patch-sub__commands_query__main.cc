--- sub_commands/query_main.cc.orig	2019-05-13 07:47:53 UTC
+++ sub_commands/query_main.cc
@@ -60,7 +60,7 @@ void query_from_cmdline(std::vector<const char*> mers,
       if(canonical)
         m.canonicalize();
       out << m << " " << db.check(m) << "\n";
-    } catch(std::length_error e) {
+    } catch(std::length_error &e) {
       std::cerr << "Invalid mer '" << *it << "'\n";
     }
   }
@@ -77,7 +77,7 @@ void query_from_stdin(const Database& db, std::ostream
       if(canonical)
         m.canonicalize();
       out << db.check(m) << std::endl;  // a flush is need for interactive use
-    } catch(std::length_error e) {
+    } catch(std::length_error &e) {
       std::cerr << "Invalid mer '" << buffer << "'" << std::endl;
     }
   }
