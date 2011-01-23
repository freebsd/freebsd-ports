--- ../server/db/ap_schema.cpp.orig	2009-06-16 19:06:20.000000000 +0200
+++ ../server/db/ap_schema.cpp	2009-09-25 22:26:58.000000000 +0200
@@ -174,7 +174,7 @@
 	      }
 
 	void coordinate_t::parse(const std::string &s) {
-	      SQL_ROW row(&s,3);
+	      SQL_ROW row(s.c_str(),3);
 	      parse(row);
 	      }
 
@@ -313,7 +313,7 @@
 	      }
 
 	void threshold_t::parse(const std::string &s) {
-	      SQL_ROW row(&s,2);
+	      SQL_ROW row(s.c_str(),2);
 	      parse(row);
 	      }
 
@@ -460,10 +460,10 @@
 
 	void data_description_t::parse(const SQL_ROW &s) {
 	  {  
-	  start.parse(SQL_ROW(s[0],0));
+	  start.parse(SQL_ROW(s[0]->c_str(),0));
 	    }
 	  {  
-	  end.parse(SQL_ROW(s[1],0));
+	  end.parse(SQL_ROW(s[1]->c_str(),0));
 	    }
 	  {  
 	        std::istringstream row(*(s[2]));
@@ -476,7 +476,7 @@
 	      }
 
 	void data_description_t::parse(const std::string &s) {
-	      SQL_ROW row(&s,4);
+	      SQL_ROW row(s.c_str(),4);
 	      parse(row);
 	      }
 
@@ -714,7 +714,7 @@
 	      }
 
 	void tape::parse(const std::string &s) {
-	      SQL_ROW row(&s,8);
+	      SQL_ROW row(s.c_str(),8);
 	      parse(row);
 	      }
 
@@ -1034,15 +1034,15 @@
 	  std::string::size_type p,q;
 	  int i;
 	    thresholds.clear();
-	      SQL_ROW tmp(s[11]); 
+	      SQL_ROW tmp((*s[11]).c_str()); 
 	      for (i=0;i<tmp.argc();i++) {
-	 thresholds.push_back(threshold_t(SQL_ROW(tmp[i])));
+	 thresholds.push_back(threshold_t(SQL_ROW((*tmp[i]).c_str())));
 	      }
 	    }
 	      }
 
 	void analysis_config::parse(const std::string &s) {
-	      SQL_ROW row(&s,12);
+	      SQL_ROW row(s.c_str(),12);
 	      parse(row);
 	      }
 
@@ -1248,7 +1248,7 @@
 	      }
 
 	void recorder_config::parse(const std::string &s) {
-	      SQL_ROW row(&s,6);
+	      SQL_ROW row(s.c_str(),6);
 	      parse(row);
 	      }
 
@@ -1643,7 +1643,7 @@
 	  std::string::size_type p,q;
 	  int i;
 	    az_corr_coeff.clear();
-	      SQL_ROW tmp(s[10]); 
+	      SQL_ROW tmp((*s[10]).c_str()); 
 	        for (i=0;i<tmp.argc();i++) {
 	          std::istringstream in(*(tmp[i]));
 	          float tmp0;
@@ -1655,7 +1655,7 @@
 	  std::string::size_type p,q;
 	  int i;
 	    zen_corr_coeff.clear();
-	      SQL_ROW tmp(s[11]); 
+	      SQL_ROW tmp((*s[11]).c_str()); 
 	        for (i=0;i<tmp.argc();i++) {
 	          std::istringstream in(*(tmp[i]));
 	          float tmp0;
@@ -1678,7 +1678,7 @@
 	      }
 
 	void receiver_config::parse(const std::string &s) {
-	      SQL_ROW row(&s,15);
+	      SQL_ROW row(s.c_str(),15);
 	      parse(row);
 	      }
 
@@ -1828,7 +1828,7 @@
 	      }
 
 	void splitter_config::parse(const std::string &s) {
-	      SQL_ROW row(&s,3);
+	      SQL_ROW row(s.c_str(),3);
 	      parse(row);
 	      }
 
@@ -2044,21 +2044,21 @@
 	        row >> active;
 	    }
 	  {  
-	  receiver_cfg.parse(SQL_ROW(s[2],0));
+	  receiver_cfg.parse(SQL_ROW(s[2]->c_str(),0));
 	    }
 	  {  
-	  recorder_cfg.parse(SQL_ROW(s[3],0));
+	  recorder_cfg.parse(SQL_ROW(s[3]->c_str(),0));
 	    }
 	  {  
-	  splitter_cfg.parse(SQL_ROW(s[4],0));
+	  splitter_cfg.parse(SQL_ROW(s[4]->c_str(),0));
 	    }
 	  {  
-	  analysis_cfg.parse(SQL_ROW(s[5],0));
+	  analysis_cfg.parse(SQL_ROW(s[5]->c_str(),0));
 	    }
 	      }
 
 	void settings::parse(const std::string &s) {
-	      SQL_ROW row(&s,6);
+	      SQL_ROW row(s.c_str(),6);
 	      parse(row);
 	      }
 
@@ -2312,27 +2312,27 @@
 	        name[127]=0;
 	    }
 	  {  
-	  tape_info.parse(SQL_ROW(s[2],0));
+	  tape_info.parse(SQL_ROW(s[2]->c_str(),0));
 	    }
 	  {  
-	  receiver_cfg.parse(SQL_ROW(s[3],0));
+	  receiver_cfg.parse(SQL_ROW(s[3]->c_str(),0));
 	    }
 	  {  
-	  recorder_cfg.parse(SQL_ROW(s[4],0));
+	  recorder_cfg.parse(SQL_ROW(s[4]->c_str(),0));
 	    }
 	  {  
-	  splitter_cfg.parse(SQL_ROW(s[5],0));
+	  splitter_cfg.parse(SQL_ROW(s[5]->c_str(),0));
 	    }
 	  {  
-	  analysis_cfg.parse(SQL_ROW(s[6],0));
+	  analysis_cfg.parse(SQL_ROW(s[6]->c_str(),0));
 	    }
 	  {  
-	  data_desc.parse(SQL_ROW(s[7],0));
+	  data_desc.parse(SQL_ROW(s[7]->c_str(),0));
 	    }
 	      }
 
 	void workunit_header::parse(const std::string &s) {
-	      SQL_ROW row(&s,8);
+	      SQL_ROW row(s.c_str(),8);
 	      parse(row);
 	      }
 
@@ -2569,7 +2569,7 @@
 	        row >> boinc_result;
 	    }
 	  {  
-	  wuid.parse(SQL_ROW(s[2],0));
+	  wuid.parse(SQL_ROW(s[2]->c_str(),0));
 	    }
 	  {  
 	        std::istringstream row(*(s[3]));
@@ -2602,7 +2602,7 @@
 	      }
 
 	void result::parse(const std::string &s) {
-	      SQL_ROW row(&s,10);
+	      SQL_ROW row(s.c_str(),10);
 	      parse(row);
 	      }
 
@@ -2959,7 +2959,7 @@
 	        row >> id;
 	    }
 	  {  
-	  resultid.parse(SQL_ROW(s[1],0));
+	  resultid.parse(SQL_ROW(s[1]->c_str(),0));
 	    }
 	  {  
 	        std::istringstream row(*(s[2]));
@@ -3034,7 +3034,7 @@
 	      }
 
 	void ap_signal::parse(const std::string &s) {
-	      SQL_ROW row(&s,20);
+	      SQL_ROW row(s.c_str(),20);
 	      parse(row);
 	      }
 
@@ -3315,7 +3315,7 @@
 	        row >> id;
 	    }
 	  {  
-	  ap_signalid.parse(SQL_ROW(s[1],0));
+	  ap_signalid.parse(SQL_ROW(s[1]->c_str(),0));
 	    }
 	  {  
 	        std::istringstream row(*(s[2]));
@@ -3368,7 +3368,7 @@
 	      }
 
 	void rfi::parse(const std::string &s) {
-	      SQL_ROW row(&s,14);
+	      SQL_ROW row(s.c_str(),14);
 	      parse(row);
 	      }
 
