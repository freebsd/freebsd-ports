--- src/nss_gethostname_select.h.orig	2008-10-07 22:27:59.000000000 +0100
+++ src/nss_gethostname_select.h	2008-10-07 22:22:10.000000000 +0100
@@ -0,0 +1,52 @@
+/* $Id$ */
+
+/***
+	This file is part of nss-mdns.
+
+	nss-mdns is free software; you can redistribute it and/or modify
+	it under the terms of the GNU Lesser General Public License as published
+	by the Free Software Foundation; either version 2 of the License,
+	or (at your option) any later version.
+
+	nss-mdns is distributed in the hope that it will be useful, but1
+	WITHOUT ANY WARRANTY; without even the implied warranty of
+	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
+	General Public License for more details.
+
+	You should have received a copy of the GNU Lesser General Public License
+	along with nss-mdns; if not, write to the Free Software
+	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
+	USA.
+***/
+
+#ifndef NSS_GETHOSTNAME_SELECT_H
+#define NSS_GETHOSTNAME_SELECT_H
+
+#if defined(NSS_IPV4_ONLY) && ! defined(MDNS_MINIMAL)
+#define _nss_mdns_gethostbyname2_r _nss_mdns4_gethostbyname2_r
+#define _nss_mdns_gethostbyname_r  _nss_mdns4_gethostbyname_r
+#define _nss_mdns_gethostbyaddr_r  _nss_mdns4_gethostbyaddr_r
+#elif defined(NSS_IPV4_ONLY) && defined(MDNS_MINIMAL)
+#define _nss_mdns_gethostbyname2_r _nss_mdns4_minimal_gethostbyname2_r
+#define _nss_mdns_gethostbyname_r  _nss_mdns4_minimal_gethostbyname_r
+#define _nss_mdns_gethostbyaddr_r  _nss_mdns4_minimal_gethostbyaddr_r
+#elif defined(NSS_IPV6_ONLY) && ! defined(MDNS_MINIMAL)
+#define _nss_mdns_gethostbyname2_r _nss_mdns6_gethostbyname2_r
+#define _nss_mdns_gethostbyname_r  _nss_mdns6_gethostbyname_r
+#define _nss_mdns_gethostbyaddr_r  _nss_mdns6_gethostbyaddr_r
+#elif defined(NSS_IPV6_ONLY) && defined(MDNS_MINIMAL)
+#define _nss_mdns_gethostbyname2_r _nss_mdns6_minimal_gethostbyname2_r
+#define _nss_mdns_gethostbyname_r  _nss_mdns6_minimal_gethostbyname_r
+#define _nss_mdns_gethostbyaddr_r  _nss_mdns6_minimal_gethostbyaddr_r
+#elif defined(MDNS_MINIMAL)
+#define _nss_mdns_gethostbyname2_r _nss_mdns_minimal_gethostbyname2_r
+#define _nss_mdns_gethostbyname_r  _nss_mdns_minimal_gethostbyname_r
+#define _nss_mdns_gethostbyaddr_r  _nss_mdns_minimal_gethostbyaddr_r
+#endif
+
+/* prototypes of things in nss.c */
+enum nss_status _nss_mdns_gethostbyaddr_r(const void* addr, int len, int af, struct hostent *result, char *buffer, size_t buflen, int *errnop, int *h_errnop);
+enum nss_status _nss_mdns_gethostbyname_r(const char *name, struct hostent *result, char *buffer, size_t buflen, int *errnop, int *h_errnop);
+enum nss_status _nss_mdns_gethostbyname2_r(const char *name, int af, struct hostent *result, char *buffer, size_t buflen, int *errnop, int *h_errnop);
+
+#endif
