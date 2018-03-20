--- src/libical/icaltz-util.h.orig	2018-03-09 22:29:13 UTC
+++ src/libical/icaltz-util.h
@@ -4,19 +4,16 @@
  *
  * Copyright 2007, Novell, Inc.
  *
- * This program is free software; you can redistribute it and/or
- * modify it under the terms of version 2 of the GNU Lesser General Public
- * License as published by the Free Software Foundation.
+ * This library is free software; you can redistribute it and/or modify
+ * it under the terms of either:
  *
- * This program is distributed in the hope that it will be useful,
- * but WITHOUT ANY WARRANTY; without even the implied warranty of
- * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- * GNU Lesser General Public License for more details.
+ *   The LGPL as published by the Free Software Foundation, version
+ *   2.1, available at: http://www.gnu.org/licenses/lgpl-2.1.html
  *
- * You should have received a copy of the GNU Lesser General Public
- * License along with this library; if not, write to the
- * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
- * Boston, MA 02110-1301, USA.
+ * Or:
+ *
+ *   The Mozilla Public License Version 2.0. You may obtain a copy of
+ *   the License at http://www.mozilla.org/MPL/
  */
 
 #ifndef ICALTZUTIL_H
@@ -35,10 +32,4 @@ LIBICAL_ICAL_EXPORT const char *icaltzut
 
 LIBICAL_ICAL_EXPORT icalcomponent *icaltzutil_fetch_timezone(const char *location);
 
-/* set @p on to 0 if inter-operable vtimezones are desired; else exact timezones are in-effect */
-LIBICAL_ICAL_EXPORT void icaltzutil_set_exact_vtimezones_support(int on);
-
-/* return 1 if exact vtimezones are in-effect; else inter-operable vtimezones are in-effect */
-LIBICAL_ICAL_EXPORT int icaltzutil_get_exact_vtimezones_support(void);
-
 #endif
