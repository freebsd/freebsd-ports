--- src/tracks.c.orig	2015-05-21 11:26:32 UTC
+++ src/tracks.c
@@ -41,8 +41,10 @@ bbox_t		get_track_bbox(GSList *track);
 GSList *	load_log_file_into_list(char *file);
 GSList *	load_gpx_file_into_list(char *file);
 GSList * load_ols_XML_file_into_list(char *file);
+GSList * load_kml_XML_file_into_list(char *file);
 GSList * parse_gpx_nodes(xmlNode *node);
 GSList * parse_ols_XML_nodes(xmlNode *node);
+GSList * parse_kml_XML_nodes(xmlNode *node);
 
 void * fetch_track_thread(void *ptr);
 void * fetch_openrouteservice_track_thread(void *ptr);
@@ -662,6 +664,30 @@ load_ols_XML_string_into_list(char *ols_
 }
 
 GSList *
+load_kml_XML_string_into_list(char *kml_string)
+{
+	GSList *list = NULL;
+	xmlDoc *doc = NULL;
+	xmlNode *root_element = NULL;
+
+	if(!kml_string) return NULL;
+
+	LIBXML_TEST_VERSION
+
+	doc = xmlReadMemory(kml_string, strlen(kml_string), "noname.xml", NULL, 0);
+
+	if (doc == NULL) {
+		fprintf (stderr, _("Failed to parse document\n"));
+	} else {
+		root_element = xmlDocGetRootElement(doc);
+		list = parse_kml_XML_nodes(root_element);
+		xmlFreeDoc(doc);
+	}
+
+	return list;
+}
+
+GSList *
 parse_gpx_nodes(xmlNode *node)
 {
 	xmlNode *cur_node = NULL;
@@ -754,6 +780,60 @@ parse_ols_XML_nodes(xmlNode *node)
 	return list;
 }
 
+GSList *
+parse_kml_XML_nodes(xmlNode *node)
+{
+	xmlNode *cur_node = NULL;
+	GSList *list = NULL;
+
+	for (cur_node = node; cur_node; cur_node = cur_node->next)
+	{
+		if (xmlStrEqual(cur_node->name, BAD_CAST "Placemark"))
+		{
+			xmlNode *geometry_node = cur_node->children;
+			while (geometry_node != NULL)
+			{
+				if (xmlStrEqual(geometry_node->name, BAD_CAST "LineString"))
+				{
+					xmlNode *inner_cur_node = geometry_node->children;
+					while (inner_cur_node != NULL)
+					{
+						if (xmlStrEqual(inner_cur_node->name, BAD_CAST "coordinates")) {
+							char** lonlatlist;
+							lonlatlist = g_strsplit(xmlNodeGetContent(inner_cur_node), "\n", -1);
+							for(unsigned int i = 0; lonlatlist[i]; i++){
+								g_strchug(lonlatlist[i]);
+								g_strchomp(lonlatlist[i]);
+								char** lonlat = g_strsplit(lonlatlist[i], ",", 2);
+								if (lonlat[0])
+								{
+									double lat, lon;
+									lon = atof(lonlat[0]);
+									if (lonlat[1])
+									{
+										trackpoint_t *tp = g_new0(trackpoint_t,1);
+										lat = atof(lonlat[1]);
+										tp->lat = deg2rad(lat);
+										tp->lon = deg2rad(lon);
+										list = g_slist_append(list, tp);
+									}
+								}
+								g_strfreev (lonlat);
+							}
+							g_strfreev (lonlatlist);
+						}
+						inner_cur_node = inner_cur_node->next;
+					}
+				}
+				geometry_node = geometry_node->next;
+			}
+		}
+		list = g_slist_concat(list, parse_kml_XML_nodes(cur_node->children));
+	}
+
+	return list;
+}
+
 
 void
 fetch_track(GtkWidget *widget, char *service, char *start, char *end)
@@ -796,7 +876,7 @@ void fetch_yournavigation_track(GtkWidge
 	dialog10 = widget;
 	printf("%s(): %s, %s\n",__PRETTY_FUNCTION__, start, end);
 	
-	url = g_strdup_printf("http://www.yournavigation.org/api/dev/gosmore.php?format=gpx&flat=%s&flon=%s&tlat=%s&tlon=%s&v=motorcar&fast=1&layer=mapnik",startlatstr, startlonstr, endlatstr, endlonstr);
+	url = g_strdup_printf("http://www.yournavigation.org/api/1.0/gosmore.php?format=kml&flat=%s&flon=%s&tlat=%s&tlon=%s&v=motorcar&fast=1&layer=mapnik",startlatstr, startlonstr, endlatstr, endlonstr);
 	if (!g_thread_create(&fetch_track_thread, (void *)url, FALSE, NULL) != 0)
 		g_warning("### can't create route thread\n");
 }
@@ -1002,7 +1082,7 @@ fetch_track_thread(void *ptr)
 
 	printf("HTTP-GET: size: %d, statuscode %d \n", (int)reply->size, (int)reply->status_code);
 
-	loaded_track = load_gpx_string_into_list(reply->data);
+	loaded_track = load_kml_XML_string_into_list(reply->data);
 	process_fetched_track(reply, true);
 		
 	return NULL;
