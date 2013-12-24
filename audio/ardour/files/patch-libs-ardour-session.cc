--- libs/ardour/session.cc.orig
+++ libs/ardour/session.cc
@@ -79,7 +79,6 @@
 using namespace std;
 using namespace ARDOUR;
 using namespace PBD;
-using boost::shared_ptr;
 
 #ifdef __x86_64__
 static const int CPU_CACHE_ALIGN = 64;
@@ -399,14 +398,14 @@ Session::Session (AudioEngine &eng,
 		int control_id = 1;
 		
 		if (control_out_channels) {
-			shared_ptr<Route> r (new Route (*this, _("monitor"), -1, control_out_channels, -1, control_out_channels, Route::ControlOut));
+			boost::shared_ptr<Route> r (new Route (*this, _("monitor"), -1, control_out_channels, -1, control_out_channels, Route::ControlOut));
 			r->set_remote_control_id (control_id++);
 			
 			rl.push_back (r);
 		}
 		
 		if (master_out_channels) {
-			shared_ptr<Route> r (new Route (*this, _("master"), -1, master_out_channels, -1, master_out_channels, Route::MasterOut));
+			boost::shared_ptr<Route> r (new Route (*this, _("master"), -1, master_out_channels, -1, master_out_channels, Route::MasterOut));
 			r->set_remote_control_id (control_id);
 			 
 			rl.push_back (r);
@@ -984,8 +983,8 @@ Session::hookup_io ()
 boost::shared_ptr<Session::RouteList>
 Session::get_routes_with_regions_at (nframes64_t const p) const
 {
-	shared_ptr<RouteList> r = routes.reader ();
-	shared_ptr<RouteList> rl (new RouteList);
+	boost::shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> rl (new RouteList);
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		boost::shared_ptr<Track> tr = boost::dynamic_pointer_cast<Track> (*i);
@@ -1590,9 +1589,9 @@ struct RouteSorter {
 };
 
 static void
-trace_terminal (shared_ptr<Route> r1, shared_ptr<Route> rbase)
+trace_terminal (boost::shared_ptr<Route> r1, boost::shared_ptr<Route> rbase)
 {
-	shared_ptr<Route> r2;
+	boost::shared_ptr<Route> r2;
 
 	if ((r1->fed_by.find (rbase) != r1->fed_by.end()) && (rbase->fed_by.find (r1) != rbase->fed_by.end())) {
 		info << string_compose(_("feedback loop setup between %1 and %2"), r1->name(), rbase->name()) << endmsg;
@@ -1601,13 +1600,13 @@ trace_terminal (shared_ptr<Route> r1, sh
 
 	/* make a copy of the existing list of routes that feed r1 */
 
-	set<shared_ptr<Route> > existing = r1->fed_by;
+	set<boost::shared_ptr<Route> > existing = r1->fed_by;
 
 	/* for each route that feeds r1, recurse, marking it as feeding
 	   rbase as well.
 	*/
 
-	for (set<shared_ptr<Route> >::iterator i = existing.begin(); i != existing.end(); ++i) {
+	for (set<boost::shared_ptr<Route> >::iterator i = existing.begin(); i != existing.end(); ++i) {
 		r2 =* i;
 
 		/* r2 is a route that feeds r1 which somehow feeds base. mark
@@ -1651,14 +1650,14 @@ Session::resort_routes ()
 	{
 
 		RCUWriter<RouteList> writer (routes);
-		shared_ptr<RouteList> r = writer.get_copy ();
+		boost::shared_ptr<RouteList> r = writer.get_copy ();
 		resort_routes_using (r);
 		/* writer goes out of scope and forces update */
 	}
 }
 
 void
-Session::resort_routes_using (shared_ptr<RouteList> r)
+Session::resort_routes_using (boost::shared_ptr<RouteList> r)
 {
 	RouteList::iterator i, j;
 	
@@ -1723,7 +1722,7 @@ Session::new_audio_track (int input_chan
 	/* count existing audio tracks */
 
 	{
-		shared_ptr<RouteList> r = routes.reader ();
+		boost::shared_ptr<RouteList> r = routes.reader ();
 
 		for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 			if (dynamic_cast<AudioTrack*>((*i).get()) != 0) {
@@ -1776,7 +1775,7 @@ Session::new_audio_track (int input_chan
 			nphysical_out = 0;
 		}
 
-		shared_ptr<AudioTrack> track;
+		boost::shared_ptr<AudioTrack> track;
 		
 		try {
 			track = boost::shared_ptr<AudioTrack>((new AudioTrack (*this, track_name, Route::Flag (0), mode)));
@@ -1884,7 +1883,7 @@ Session::set_remote_control_ids ()
 {
 	RemoteModel m = Config->get_remote_model();
 
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ( MixerOrdered == m) {			
@@ -1913,7 +1912,7 @@ Session::new_audio_route (int input_chan
 	/* count existing audio busses */
 
 	{
-		shared_ptr<RouteList> r = routes.reader ();
+		boost::shared_ptr<RouteList> r = routes.reader ();
 
 		for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 			if (dynamic_cast<AudioTrack*>((*i).get()) == 0) {
@@ -1945,7 +1944,7 @@ Session::new_audio_route (int input_chan
 		} while (bus_id < (UINT_MAX-1));
 
 		try {
-			shared_ptr<Route> bus (new Route (*this, bus_name, -1, -1, -1, -1, Route::Flag(0), DataType::AUDIO));
+			boost::shared_ptr<Route> bus (new Route (*this, bus_name, -1, -1, -1, -1, Route::Flag(0), DataType::AUDIO));
 			
 			if (bus->ensure_io (input_channels, output_channels, false, this)) {
 				error << string_compose (_("cannot configure %1 in/%2 out configuration for new audio track"),
@@ -2060,7 +2059,7 @@ Session::new_route_from_template (uint32
 		Track::zero_diskstream_id_in_xml (node_copy);
 		
 		try {
-			shared_ptr<Route> route (XMLRouteFactory (node_copy));
+			boost::shared_ptr<Route> route (XMLRouteFactory (node_copy));
 	    
 			if (route == 0) {
 				error << _("Session: cannot create track/bus from template description") << endmsg;
@@ -2107,7 +2106,7 @@ boost::shared_ptr<Route>
 Session::new_video_track (string name)
 {
 	uint32_t control_id = ntracks() + nbusses() + 1;
-	shared_ptr<Route> new_route (
+	boost::shared_ptr<Route> new_route (
 		new Route ( *this, name, -1, -1, -1, -1, Route::Flag(0), ARDOUR::DataType::NIL));
 	new_route->set_remote_control_id (control_id);
 
@@ -2115,7 +2114,7 @@ Session::new_video_track (string name)
 	rl.push_back (new_route);
         {
 		RCUWriter<RouteList> writer (routes);
-		shared_ptr<RouteList> r = writer.get_copy ();
+		boost::shared_ptr<RouteList> r = writer.get_copy ();
                 r->insert (r->end(), rl.begin(), rl.end());
 		resort_routes_using (r);
         }
@@ -2127,7 +2126,7 @@ Session::add_routes (RouteList& new_rout
 {
 	{ 
 		RCUWriter<RouteList> writer (routes);
-		shared_ptr<RouteList> r = writer.get_copy ();
+		boost::shared_ptr<RouteList> r = writer.get_copy ();
 		r->insert (r->end(), new_routes.begin(), new_routes.end());
 		resort_routes_using (r);
 	}
@@ -2150,7 +2149,7 @@ Session::add_routes (RouteList& new_rout
 		} 
 	}
 
-	if (_control_out && IO::connecting_legal) {
+	if (_control_out && IO::connecting_is_legal()) {
 
 		vector<string> cports;
 		uint32_t ni = _control_out->n_inputs();
@@ -2198,14 +2197,14 @@ Session::add_diskstream (boost::shared_p
 }
 
 void
-Session::remove_route (shared_ptr<Route> route)
+Session::remove_route (boost::shared_ptr<Route> route)
 {
 	//clear solos before removing the route
 	route->set_solo ( false, this);
 	
 	{ 	
 		RCUWriter<RouteList> writer (routes);
-		shared_ptr<RouteList> rs = writer.get_copy ();
+		boost::shared_ptr<RouteList> rs = writer.get_copy ();
 		
 		rs->remove (route);
 
@@ -2215,11 +2214,11 @@ Session::remove_route (shared_ptr<Route>
 		*/
 
 		if (route == _master_out) {
-			_master_out = shared_ptr<Route> ();
+			_master_out = boost::shared_ptr<Route> ();
 		}
 
 		if (route == _control_out) {
-			_control_out = shared_ptr<Route> ();
+			_control_out = boost::shared_ptr<Route> ();
 
 			/* cancel control outs for all routes */
 
@@ -2308,7 +2307,7 @@ Session::route_solo_changed (void* src, 
 
 	is_track = (boost::dynamic_pointer_cast<AudioTrack>(route) != 0);
 	
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		
@@ -2404,7 +2403,7 @@ Session::update_route_solo_state ()
 	   the solo mute setting of each track.
 	*/
 	
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
         for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->soloed()) {
@@ -2446,7 +2445,7 @@ Session::update_route_solo_state ()
 void
 Session::modify_solo_mute (bool is_track, bool mute)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
         for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		
@@ -2511,7 +2510,7 @@ Session::catch_up_on_solo_mute_override 
 	/* this is called whenever the param solo-mute-override is
 	   changed.
 	*/
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		(*i)->catch_up_on_solo_mute_override ();
@@ -2521,7 +2520,7 @@ Session::catch_up_on_solo_mute_override 
 bool
 Session::io_name_is_legal (const std::string& name)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->name() == name) {
@@ -2536,10 +2535,10 @@ Session::io_name_is_legal (const std::st
 	return true;
 }
 
-shared_ptr<Route>
+boost::shared_ptr<Route>
 Session::route_by_name (const std::string& name)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->name() == name) {
@@ -2547,13 +2546,13 @@ Session::route_by_name (const std::strin
 		}
 	}
 
-	return shared_ptr<Route> ((Route*) 0);
+	return boost::shared_ptr<Route> ((Route*) 0);
 }
 
-shared_ptr<Route>
+boost::shared_ptr<Route>
 Session::route_by_id (PBD::ID id)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->id() == id) {
@@ -2561,13 +2560,13 @@ Session::route_by_id (PBD::ID id)
 		}
 	}
 
-	return shared_ptr<Route> ((Route*) 0);
+	return boost::shared_ptr<Route> ((Route*) 0);
 }
 
-shared_ptr<Route>
+boost::shared_ptr<Route>
 Session::route_by_remote_id (uint32_t id)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->remote_control_id() == id) {
@@ -2575,7 +2574,7 @@ Session::route_by_remote_id (uint32_t id
 		}
 	}
 
-	return shared_ptr<Route> ((Route*) 0);
+	return boost::shared_ptr<Route> ((Route*) 0);
 }
 
 void
@@ -3595,7 +3594,7 @@ Session::is_auditioning () const
 void
 Session::set_all_solo (bool yn)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if (!(*i)->hidden()) {
@@ -3609,7 +3608,7 @@ Session::set_all_solo (bool yn)
 void
 Session::set_all_mute (bool yn)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 	
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		if (!(*i)->hidden()) {
@@ -3680,7 +3679,7 @@ Session::record_enable_all ()
 void
 Session::record_enable_change_all (bool yn)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 	
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 		AudioTrack* at;
@@ -4071,7 +4070,7 @@ Session::reset_native_file_format ()
 bool
 Session::route_name_unique (string n) const
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 	
 	for (RouteList::const_iterator i = r->begin(); i != r->end(); ++i) {
 		if ((*i)->name() == n) {
@@ -4117,7 +4116,7 @@ Session::allocate_pan_automation_buffers
 int
 Session::freeze (InterThreadInfo& itt)
 {
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::iterator i = r->begin(); i != r->end(); ++i) {
 
@@ -4355,7 +4354,7 @@ uint32_t 
 Session::ntracks () const
 {
 	uint32_t n = 0;
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::const_iterator i = r->begin(); i != r->end(); ++i) {
 		if (dynamic_cast<AudioTrack*> ((*i).get())) {
@@ -4370,7 +4369,7 @@ uint32_t 
 Session::nbusses () const
 {
 	uint32_t n = 0;
-	shared_ptr<RouteList> r = routes.reader ();
+	boost::shared_ptr<RouteList> r = routes.reader ();
 
 	for (RouteList::const_iterator i = r->begin(); i != r->end(); ++i) {
 		if (dynamic_cast<AudioTrack*> ((*i).get()) == 0) {
