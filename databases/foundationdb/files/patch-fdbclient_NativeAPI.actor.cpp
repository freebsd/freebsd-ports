--- fdbclient/NativeAPI.actor.cpp.orig	2018-04-28 15:48:35 UTC
+++ fdbclient/NativeAPI.actor.cpp
@@ -93,7 +93,7 @@ LocationInfo::~LocationInfo() {
 		for( auto const& alternative : getAlternatives() )
 			handles.push_back( alternative.v.getVersion.getEndpoint().token ); // must match above choice of UID
 		std::sort( handles.begin(), handles.end() );
-		ASSERT( handles.size() );
+		ASSERT_ABORT( handles.size() );
 
 		auto it = cx->ssid_locationInfo.find( handles );
 		if( it != cx->ssid_locationInfo.end() )
@@ -540,7 +540,7 @@ DatabaseContext::~DatabaseContext() {
 	monitorMasterProxiesInfoChange.cancel();
 	for(auto it = ssid_locationInfo.begin(); it != ssid_locationInfo.end(); it = ssid_locationInfo.erase(it))
 		it->second->notifyContextDestroyed();
-	ASSERT( ssid_locationInfo.empty() );
+	ASSERT_ABORT( ssid_locationInfo.empty() );
 	locationCache.insert( allKeys, Reference<LocationInfo>() );
 }
 
