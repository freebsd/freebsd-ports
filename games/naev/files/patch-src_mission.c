# Origin: https://github.com/naev/naev/commit/74b9a086a20f80f21ce2f3866b31318e651a6235
# Subject: Turn player_missions in an array of pointers

--- src/mission.c.orig	2015-02-16 17:49:03 UTC
+++ src/mission.c
@@ -50,7 +50,7 @@
  * current player missions
  */
 static unsigned int mission_id = 0; /**< Mission ID generator. */
-Mission player_missions[MISSION_MAX]; /**< Player's active missions. */
+Mission *player_missions[MISSION_MAX]; /**< Player's active missions. */
 
 
 /*
@@ -95,7 +95,7 @@ static unsigned int mission_genID (void)
 
    /* we save mission ids, so check for collisions with player's missions */
    for (i=0; i<MISSION_MAX; i++)
-      if (id == player_missions[i].id) /* mission id was loaded from save */
+      if (id == player_missions[i]->id) /* mission id was loaded from save */
          return mission_genID(); /* recursively try again */
    return id;
 }
@@ -240,7 +240,7 @@ int mission_alreadyRunning( MissionData*
 {
    int i;
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].data==misn)
+      if (player_missions[i]->data == misn)
          return 1;
    return 0;
 }
@@ -416,15 +416,15 @@ void mission_sysMark (void)
 
    for (i=0; i<MISSION_MAX; i++) {
       /* Must be a valid player mission. */
-      if (player_missions[i].id == 0)
+      if (player_missions[i]->id == 0)
          continue;
       /* Must have markers. */
-      if (player_missions[i].markers == NULL)
+      if (player_missions[i]->markers == NULL)
          continue;
 
-      n = array_size( player_missions[i].markers );
+      n = array_size( player_missions[i]->markers );
       for (j=0; j<n; j++) {
-         m = &player_missions[i].markers[j];
+         m = &player_missions[i]->markers[j];
 
          /* Add the individual markers. */
          space_addMarker( m->sys, m->type );
@@ -562,6 +562,30 @@ void mission_cleanup( Mission* misn )
 
 
 /**
+ * @brief Puts the specified mission at the end of the player_missions array.
+ *
+ *    @param pos Mission's position within player_missions
+ */
+void mission_shift( int pos )
+{
+   Mission *misn;
+
+   if (pos >= (MISSION_MAX-1))
+      return;
+
+   /* Store specified mission. */
+   misn = player_missions[pos];
+
+   /* Move other missions down. */
+   memmove( &player_missions[pos], &player_missions[pos+1],
+      sizeof(Mission*) * (MISSION_MAX - pos - 1) );
+
+   /* Put the specified mission at the end of the array. */
+   player_missions[MISSION_MAX - 1] = misn;
+}
+
+
+/**
  * @brief Frees MissionData.
  *
  *    @param mission MissionData to free.
@@ -622,8 +646,8 @@ void missions_activateClaims (void)
    int i;
 
    for (i=0; i<MISSION_MAX; i++)
-      if (player_missions[i].claims != NULL)
-         claim_activate( player_missions[i].claims );
+      if (player_missions[i]->claims != NULL)
+         claim_activate( player_missions[i]->claims );
 }
 
 
@@ -869,9 +893,14 @@ static int mission_parse( MissionData* t
  */
 int missions_load (void)
 {
-   int m;
+   int i, m;
    uint32_t bufsize;
-   char *buf = ndata_read( MISSION_DATA_PATH, &bufsize );
+   char *buf;
+
+   for (i=0; i<MISSION_MAX; i++)
+      player_missions[i] = calloc(1, sizeof(Mission));
+
+   buf = ndata_read( MISSION_DATA_PATH, &bufsize );
 
    xmlNodePtr node;
    xmlDocPtr doc = xmlParseMemory( buf, bufsize );
@@ -933,6 +962,10 @@ void missions_free (void)
    free( mission_stack );
    mission_stack = NULL;
    mission_nstack = 0;
+
+   /* Free the player mission stack. */
+   for (i=0; i<MISSION_MAX; i++)
+      free(player_missions[i]);
 }
 
 
@@ -944,7 +977,7 @@ void missions_cleanup (void)
    int i;
 
    for (i=0; i<MISSION_MAX; i++)
-      mission_cleanup( &player_missions[i] );
+      mission_cleanup( player_missions[i] );
 }
 
 
@@ -963,26 +996,26 @@ int missions_saveActive( xmlTextWriterPt
    xmlw_startElem(writer,"missions");
 
    for (i=0; i<MISSION_MAX; i++) {
-      if (player_missions[i].id != 0) {
+      if (player_missions[i]->id != 0) {
          xmlw_startElem(writer,"mission");
 
          /* data and id are attributes because they must be loaded first */
-         xmlw_attr(writer,"data","%s",player_missions[i].data->name);
-         xmlw_attr(writer,"id","%u",player_missions[i].id);
+         xmlw_attr(writer,"data","%s",player_missions[i]->data->name);
+         xmlw_attr(writer,"id","%u",player_missions[i]->id);
 
-         xmlw_elem(writer,"title","%s",player_missions[i].title);
-         xmlw_elem(writer,"desc","%s",player_missions[i].desc);
-         xmlw_elem(writer,"reward","%s",player_missions[i].reward);
+         xmlw_elem(writer,"title","%s",player_missions[i]->title);
+         xmlw_elem(writer,"desc","%s",player_missions[i]->desc);
+         xmlw_elem(writer,"reward","%s",player_missions[i]->reward);
 
          /* Markers. */
          xmlw_startElem( writer, "markers" );
-         if (player_missions[i].markers != NULL) {
-            n = array_size( player_missions[i].markers );
+         if (player_missions[i]->markers != NULL) {
+            n = array_size( player_missions[i]->markers );
             for (j=0; j<n; j++) {
                xmlw_startElem(writer,"marker");
-               xmlw_attr(writer,"id","%d",player_missions[i].markers[j].id);
-               xmlw_attr(writer,"type","%d",player_missions[i].markers[j].type);
-               xmlw_str(writer,"%s", system_getIndex(player_missions[i].markers[j].sys)->name);
+               xmlw_attr(writer,"id","%d",player_missions[i]->markers[j].id);
+               xmlw_attr(writer,"type","%d",player_missions[i]->markers[j].type);
+               xmlw_str(writer,"%s", system_getIndex(player_missions[i]->markers[j].sys)->name);
                xmlw_endElem(writer); /* "marker" */
             }
          }
@@ -990,19 +1023,19 @@ int missions_saveActive( xmlTextWriterPt
 
          /* Cargo */
          xmlw_startElem(writer,"cargos");
-         for (j=0; j<player_missions[i].ncargo; j++)
-            xmlw_elem(writer,"cargo","%u", player_missions[i].cargo[j]);
+         for (j=0; j<player_missions[i]->ncargo; j++)
+            xmlw_elem(writer,"cargo","%u", player_missions[i]->cargo[j]);
          xmlw_endElem(writer); /* "cargos" */
 
          /* OSD. */
-         if (player_missions[i].osd > 0) {
+         if (player_missions[i]->osd > 0) {
             xmlw_startElem(writer,"osd");
 
             /* Save attributes. */
-            items = osd_getItems(player_missions[i].osd, &nitems);
-            xmlw_attr(writer,"title","%s",osd_getTitle(player_missions[i].osd));
+            items = osd_getItems(player_missions[i]->osd, &nitems);
+            xmlw_attr(writer,"title","%s",osd_getTitle(player_missions[i]->osd));
             xmlw_attr(writer,"nitems","%d",nitems);
-            xmlw_attr(writer,"active","%d",osd_getActive(player_missions[i].osd));
+            xmlw_attr(writer,"active","%d",osd_getActive(player_missions[i]->osd));
 
             /* Save messages. */
             for (j=0; j<nitems; j++)
@@ -1013,12 +1046,12 @@ int missions_saveActive( xmlTextWriterPt
 
          /* Claims. */
          xmlw_startElem(writer,"claims");
-         claim_xmlSave( writer, player_missions[i].claims );
+         claim_xmlSave( writer, player_missions[i]->claims );
          xmlw_endElem(writer); /* "claims" */
 
          /* Write Lua magic */
          xmlw_startElem(writer,"lua");
-         nxml_persistLua( player_missions[i].L, writer );
+         nxml_persistLua( player_missions[i]->L, writer );
          xmlw_endElem(writer); /* "lua" */
 
          xmlw_endElem(writer); /* "mission" */
@@ -1078,7 +1111,7 @@ static int missions_parseActive( xmlNode
    node = parent->xmlChildrenNode;
    do {
       if (xml_isNode(node,"mission")) {
-         misn = &player_missions[m];
+         misn = player_missions[m];
 
          /* process the attributes to create the mission */
          xmlr_attr(node,"data",buf);
