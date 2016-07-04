--- imagepool/poolinstance.h.orig	2014-01-19 07:38:17 UTC
+++ imagepool/poolinstance.h
@@ -50,9 +50,9 @@ protected:
 
 	Instance(const std::string& sopinstanceuid);
 
-	friend void ImagePool::remove_instance(const Glib::RefPtr<ImagePool::Instance>&);
+	friend void remove_instance(const Glib::RefPtr<ImagePool::Instance>&);
 
-	friend class ImagePool::Loader;
+	friend class Loader;
 
 public:
 
@@ -131,9 +131,9 @@ public:
 
 	int instancenumber();
 
-	const Glib::RefPtr<ImagePool::Series>& series();
+	const Glib::RefPtr<Series>& series();
 
-	const Glib::RefPtr<ImagePool::Study>& study();
+	const Glib::RefPtr<Study>& study();
 
 	const std::string& date();
 
@@ -176,7 +176,7 @@ public:
 
 	bool has_3d_information();
 
-	static Glib::RefPtr<ImagePool::Instance> create(DcmDataset* dset);
+	static Glib::RefPtr<Instance> create(DcmDataset* dset);
 
 	int studyrelatedinstances();
 
@@ -248,9 +248,9 @@ private:
 
 	std::string m_modality;
 
-	Glib::RefPtr<ImagePool::Series> m_series;
+	Glib::RefPtr<Series> m_series;
 
-	Glib::RefPtr<ImagePool::Study> m_study;
+	Glib::RefPtr<Study> m_study;
 
 	std::string m_date;
 
