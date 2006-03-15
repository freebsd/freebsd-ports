--- libkcal/libical/src/libicalss/icalclassify.c.orig	Mon Oct 10 17:02:27 2005
+++ libkcal/libical/src/libicalss/icalclassify.c	Tue Mar 14 14:58:48 2006
@@ -221,7 +221,10 @@
 
     p = icalcomponent_get_first_property(inner,ICAL_ORGANIZER_PROPERTY);
     if(p!=0){
-	parts->organizer = strdup(icalproperty_get_organizer(p));
+      const char *p_organizer = icalproperty_get_organizer(p);
+      if (p_organizer!=0) {
+        parts->organizer = strdup(p_organizer);
+      }
     }
 
     p = icalcomponent_get_first_property(inner,ICAL_SEQUENCE_PROPERTY);    
@@ -231,7 +234,10 @@
 
     p = icalcomponent_get_first_property(inner,ICAL_UID_PROPERTY);
     if(p!=0){
-	parts->uid = strdup(icalproperty_get_uid(p));
+      const char *p_uid = icalproperty_get_uid(p);
+      if (p_uid!=0) {
+        parts->uid = strdup(p_uid);
+      }
     }
 
     p = icalcomponent_get_first_property(inner,ICAL_RECURRENCEID_PROPERTY);
