--- libs/surfaces/mackie/mackie_control_protocol.cc.orig
+++ libs/surfaces/mackie/mackie_control_protocol.cc
@@ -64,8 +64,6 @@ using namespace sigc;
 using namespace Mackie;
 using namespace PBD;
 
-using boost::shared_ptr;
-
 #include "i18n.h"
 
 MackieMidiBuilder builder;
@@ -200,7 +198,7 @@ MackieControlProtocol::port_for_id( uint
 // predicate for sort call in get_sorted_routes
 struct RouteByRemoteId
 {
-	bool operator () ( const shared_ptr<Route> & a, const shared_ptr<Route> & b ) const {
+	bool operator () ( const boost::shared_ptr<Route> & a, const boost::shared_ptr<Route> & b ) const {
 		return a->remote_control_id() < b->remote_control_id();
 	}
 
@@ -680,7 +678,7 @@ MackieControlProtocol::create_ports()
 	}
 }
 
-shared_ptr<Route>
+boost::shared_ptr<Route>
 MackieControlProtocol::master_route()
 {
 	boost::shared_ptr<IO> mo = session->master_out ();
