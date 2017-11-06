--- code/botlib/be_aas_route.c.orig	2011-12-24 12:29:34 UTC
+++ code/botlib/be_aas_route.c
@@ -106,7 +106,7 @@ void AAS_RoutingInfo(void)
 // Returns:				-
 // Changes Globals:		-
 //===========================================================================
-ID_INLINE int AAS_ClusterAreaNum(int cluster, int areanum)
+static ID_INLINE int AAS_ClusterAreaNum(int cluster, int areanum)
 {
 	int side, areacluster;
 
@@ -166,7 +166,7 @@ void AAS_InitTravelFlagFromType(void)
 // Returns:				-
 // Changes Globals:		-
 //===========================================================================
-ID_INLINE int AAS_TravelFlagForType_inline(int traveltype)
+static ID_INLINE int AAS_TravelFlagForType_inline(int traveltype)
 {
 	int tfl;
 
@@ -339,7 +339,7 @@ int AAS_EnableRoutingArea(int areanum, i
 // Returns:				-
 // Changes Globals:		-
 //===========================================================================
-ID_INLINE float AAS_RoutingTime(void)
+static ID_INLINE float AAS_RoutingTime(void)
 {
 	return AAS_Time();
 } //end of the function AAS_RoutingTime
@@ -379,7 +379,7 @@ int AAS_GetAreaContentsTravelFlags(int a
 // Returns:				-
 // Changes Globals:		-
 //===========================================================================
-ID_INLINE int AAS_AreaContentsTravelFlags_inline(int areanum)
+static ID_INLINE int AAS_AreaContentsTravelFlags_inline(int areanum)
 {
 	return aasworld.areacontentstravelflags[areanum];
 } //end of the function AAS_AreaContentsTravelFlags
