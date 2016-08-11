--- rainbow/rdf-resource.cc.orig	2004-10-17 04:06:10 UTC
+++ rainbow/rdf-resource.cc
@@ -35,7 +35,7 @@ void Rainbow::RdfResource::get_and_do (c
 		resource = ref_ptr<RdfResource>(p->second);
 		if (resource->downloaded) { // already downloaded
 			map<Glib::ustring,xmlpp::Element*>::iterator el = resource->id_map.find(id);
-			signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
+			sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
 			sig.connect(slot);
 			sig(el != resource->id_map.end() ? el->second : 0, resource);
 			return;
@@ -47,7 +47,7 @@ void Rainbow::RdfResource::get_and_do (c
 		Glib::ustring host, file;
 		unsigned short port;
 		if (!HttpClient::parse_url(uri, host, port, file)) {
-			signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
+			sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > sig;
 			sig.connect(slot);
 			sig(0, resource);
 			return;
@@ -55,14 +55,14 @@ void Rainbow::RdfResource::get_and_do (c
 	}
 
 	// connect mem_fun to appropriate signal
-	map<Glib::ustring,signal<void,xmlpp::Element*, ref_ptr<RdfResource> >*>::iterator sig;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*, ref_ptr<RdfResource> >*>::iterator sig;
 	sig = resource->signal_map.find(id);
 	if (sig != resource->signal_map.end()) {
 		// found existing signal for id
 		sig->second->connect(slot);
 	} else {
 		// need to create new signal to handle id
-		signal<void,xmlpp::Element*,ref_ptr<RdfResource> > *signal_ = new signal<void,xmlpp::Element*,ref_ptr<RdfResource> >;
+		sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> > *signal_ = new sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >;
 		signal_->connect(slot);
 		resource->signal_map.insert(make_pair(id, signal_));
 	}
@@ -190,7 +190,7 @@ void Rainbow::RdfResource::on_downloaded
 
  error:
 	// call all signals
-	map<Glib::ustring,signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
 	for (signal = signal_map.begin(); signal != signal_map.end(); ++signal) {
 		map<Glib::ustring,xmlpp::Element*>::iterator el = id_map.find(signal->first);
 		signal->second->emit(el != id_map.end() ? el->second : 0, ref_ptr<RdfResource>(this));
@@ -204,7 +204,7 @@ void Rainbow::RdfResource::on_downloaded
 
 void Rainbow::RdfResource::clear_signal_map ()
 {
-	map<Glib::ustring,signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
+	map<Glib::ustring,sigc::signal<void,xmlpp::Element*,ref_ptr<RdfResource> >*>::iterator signal;
 	for (signal = signal_map.begin(); signal != signal_map.end(); ++signal)
 		delete signal->second;
 	signal_map.clear();
