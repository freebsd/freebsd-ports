--- pdns_recursor.cc.orig	2008-06-24 22:23:33.000000000 +0400
+++ pdns_recursor.cc	2009-03-19 23:27:01.000000000 +0300
@@ -666,7 +666,7 @@
   catch(MOADNSException& e) {
     L<<Logger::Error<<"DNS parser error: "<<dc->d_mdp.d_qname<<", "<<e.what()<<endl;
   }
-  catch(exception& e) {
+  catch(std::exception& e) {
     L<<Logger::Error<<"STL error: "<<e.what()<<endl;
   }
   catch(...) {
@@ -1183,7 +1183,7 @@
     s_rcc.send(answer, &remote);
     command();
   }
-  catch(exception& e) {
+  catch(std::exception& e) {
     L<<Logger::Error<<"Error dealing with control socket request: "<<e.what()<<endl;
   }
   catch(AhuException& ae) {
@@ -1486,7 +1486,7 @@
     SyncRes::s_negcache.clear(); 
     return "ok\n";
   }
-  catch(exception& e) {
+  catch(std::exception& e) {
     L<<Logger::Error<<"Had error reloading zones, keeping original data: "<<e.what()<<endl;
   }
   catch(AhuException& ae) {
@@ -1525,7 +1525,7 @@
 	    string tmp=DNSRR2String(rr);
 	    rr=String2DNSRR(rr.qname, rr.qtype, tmp, rr.ttl);
 	  }
-	  catch(exception &e) {
+	  catch(std::exception &e) {
 	    throw AhuException("Error parsing record '"+rr.qname+"' of type "+rr.qtype.getName()+" in zone '"+headers.first+"' from file '"+headers.second+"': "+e.what());
 	  }
 	  catch(...) {
@@ -1647,7 +1647,7 @@
       }
     }
   }
-  catch(exception& e) {
+  catch(std::exception& e) {
     L<<Logger::Error<<"Retaining current script, error from '"<<fname<<"': "<< e.what() <<endl;
     return string("Retaining current script, error from '"+fname+"': "+string(e.what())+"\n");
   }
@@ -1771,7 +1771,7 @@
     }
     
   }
-  catch(exception &e) {
+  catch(std::exception &e) {
     L<<Logger::Error<<"Failed to load 'lua' script from '"<<::arg()["lua-dns-script"]<<"': "<<e.what()<<endl;
     exit(99);
   }
@@ -2060,7 +2060,7 @@
     L<<Logger::Error<<"Exception: "<<ae.reason<<endl;
     ret=EXIT_FAILURE;
   }
-  catch(exception &e) {
+  catch(std::exception &e) {
     L<<Logger::Error<<"STL Exception: "<<e.what()<<endl;
     ret=EXIT_FAILURE;
   }
