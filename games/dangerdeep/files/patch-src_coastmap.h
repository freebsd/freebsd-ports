--- src/coastmap.h.orig	2020-03-29 09:04:12 UTC
+++ src/coastmap.h
@@ -151,7 +151,7 @@ class coastmap
 	void process_coastline(int x, int y);
 	void process_segment(int x, int y);
 
-	class worker : public thread
+	class worker : public ::thread
 	{
 		coastmap& cm;
 	public:
@@ -163,7 +163,7 @@ class coastmap
 		}
 	};
 
-	thread::auto_ptr<worker> myworker;
+	::thread::auto_ptr<worker> myworker;
 	void construction_threaded();
 
 public:	
