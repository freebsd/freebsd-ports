commit f94bde59d740d65e67c5cd13af4d7ea51453aeaa
Author: Fabio Pesari <posta@parallelo.eu>
Date:   Sun Sep 15 11:04:30 2024 +0200

    Fix for Boost 1.8.5
    
    Recent boost prevents calls to `get_child` with temporary
    default values.

diff --git libs/surfaces/websockets/message.cc libs/surfaces/websockets/message.cc
index eff8e48ac3..0aee14d0df 100644
--- libs/surfaces/websockets/message.cc
+++ libs/surfaces/websockets/message.cc
@@ -58,14 +58,16 @@ NodeStateMessage::NodeStateMessage (void* buf, size_t len)
 
 		_state = NodeState (root.get<std::string> ("node"));
 
-		pt::ptree addr = root.get_child ("addr", pt::ptree ());
+		pt::ptree addr = pt::ptree ();
+		addr = root.get_child ("addr", addr);
 
 		for (pt::ptree::iterator it = addr.begin (); it != addr.end (); ++it) {
 			// throws if datatype not uint32_t
 			_state.add_addr (boost::lexical_cast<uint32_t> (it->second.data ()));
 		}
 
-		pt::ptree val = root.get_child ("val", pt::ptree ());
+		pt::ptree val = pt::ptree ();
+		val = root.get_child ("val", val);
 
 		for (pt::ptree::iterator it = val.begin (); it != val.end (); ++it) {
 			std::string val = it->second.data ();
