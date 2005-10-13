
$FreeBSD$

--- amarok/src/smartplaylisteditor.cpp.orig
+++ amarok/src/smartplaylisteditor.cpp
@@ -387,9 +387,9 @@
             joins += " INNER JOIN statistics ON statistics.url=tags.url";
         }
         if ( !criteriaListStr.isEmpty() )
-            whereStr = QString(" WHERE (%1) AND %2 = \"(*ExpandString*)\"").arg(criteriaListStr).arg(field);
+            whereStr = QString(" WHERE (%1) AND %2 = '(*ExpandString*)'").arg(criteriaListStr).arg(field);
         else
-            whereStr = QString("WHERE %1 = \"(*ExpandString*)\"").arg(field);
+            whereStr = QString("WHERE %1 = '(*ExpandString*)'").arg(field);
         m_expandQuery = "SELECT album.name, artist.name, genre.name, tags.title, year.name, "
                             "tags.comment, tags.track, tags.bitrate, tags.length, tags.samplerate, tags.url"
                             " FROM " + joins + whereStr + orderStr + limitStr + ";";
@@ -614,16 +614,16 @@
 
 
     if( criteria == i18n("contains") )
-        searchCriteria += " LIKE \"%" + value + "%\"";
+        searchCriteria += " LIKE '%" + value + "%'";
     else if( criteria == i18n("does not contain") )
-        searchCriteria += " NOT LIKE \"%" + value + "%\"";
+        searchCriteria += " NOT LIKE '%" + value + "%'";
     else if( criteria == i18n("is") ) {
         if( m_currentValueType == Date )
             searchCriteria += " BETWEEN ";
         else
             searchCriteria += " = ";
         if( m_currentValueType == String || m_currentValueType == AutoCompletionString )
-            value.prepend("\"").append("\"");
+            value.prepend("'").append("'");
         searchCriteria += value;
         if (field=="statistics.playcounter" && value=="0") {
             searchCriteria += " OR statistics.playcounter IS NULL";
@@ -635,13 +635,13 @@
         else
             searchCriteria += " <> ";
         if( m_currentValueType == String || m_currentValueType == AutoCompletionString )
-            value.prepend("\"").append("\"");
+            value.prepend("'").append("'");
         searchCriteria += value;
     }
     else if( criteria == i18n("starts with") )
-        searchCriteria += " LIKE \"" + value + "%\"";
+        searchCriteria += " LIKE '" + value + "%'";
     else if( criteria == i18n("ends with") )
-        searchCriteria += " LIKE \"%" + value + "\"";
+        searchCriteria += " LIKE '%" + value + "'";
     else if( criteria == i18n("is greater than") || criteria == i18n("is after") )
         searchCriteria += " > " + value;
     else if( criteria == i18n("is smaller than") || criteria == i18n("is before" ) )
