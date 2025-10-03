PORTNAME=	evolution-data-server
DISTVERSION=	3.56.2
PORTREVISION=	3
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Centralized access to appointments and contacts
WWW=		https://gnome.pages.gitlab.gnome.org/evolution-data-server/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libuuid.so:misc/libuuid

USES=		cmake cpe desktop-file-utils gettext-tools gnome gperf \
		iconv:wchar_t localbase pkgconfig sqlite tar:xz xorg
USE_CXXSTD=	gnu++17
USE_GNOME=	cairo glib20 introspection:build libxml2 pango
USE_XORG=	x11
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

LDFLAGS=	-L${LOCALBASE}/lib

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ARGS=	-DENABLE_INTROSPECTION=ON \
		-DENABLE_EXAMPLES=OFF \
		-DENABLED_INSTALLED_TESTS=OFF \
		-DWITH_SYSTEMDUSERUNITDIR=no

GLIB_SCHEMAS=	org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution-data-server.gschema.xml \
		org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	EVO_VERSION="1.2" CAL_API_VERSION="2.0"

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		BDB CANBERRA GTK4 LDAP OAUTH2 VAPI WEATHER
OPTIONS_DEFAULT=	BDB CANBERRA GTK4 LDAP OAUTH2 VAPI WEATHER GSSAPI_BASE
OPTIONS_SINGLE=			KERBEROS
OPTIONS_SINGLE_KERBEROS=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT \
				GSSAPI_NONE
BDB_DESC=		Use Berkeley DB
BDB_USES=		bdb
BDB_CMAKE_ON=		-DWITH_LIBDB_CFLAGS=-I${BDB_INCLUDE_DIR} \
			-DWITH_LIBDB_LIBS="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}"
BDB_CMAKE_OFF=		-DWITH_LIBDB=OFF

CANBERRA_DESC=		Canberra-GTK for sound in evolution-alarm-notify
CANBERRA_CMAKE_BOOL=	ENABLE_CANBERRA
CANBERRA_LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
			libcanberra.so:audio/libcanberra

GTK4_DESC=		GTK4 vs. GTK3
GTK4_VARS=		use_gnome+=gtk40 use_gnome+=gtk30
GTK4_VARS_OFF=		use_gnome+=gtk30
GTK4_LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
			libgtk-4.so:x11-toolkits/gtk40 \
			libvulkan.so:graphics/vulkan-loader
GTK4_CMAKE_BOOL=	ENABLE_GTK4
GTK4_CMAKE_BOOL_OFF=	ENBALE_GTK

GSSAPI_BASE_USES=	gssapi:base ssl
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CMAKE_ON=	-DWITH_KRB5=OFF
GSSAPI_NONE_CMAKE_OFF=	-DWITH_KRB5=${GSSAPIBASEDIR}
GSSAPI_NONE_CFLAGS_OFF=	${GSSAPICPPFLAGS}

LDAP_DESC=		LDAP Authentication
LDAP_CMAKE_ON=		-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=		-DWITH_OPENLDAP=OFF
LDAP_USES=		ldap

OAUTH2_DESC=		Oauth2 Authentication using webkit

VAPI_USES=		vala:build
VAPI_CMAKE_BOOL=	ENABLE_VALA_BINDINGS

WEATHER_DESC=		Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-4.so:net/libgweather4
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOAUTH2}
.  if ${PORT_OPTIONS:MGTK4}
LIB_DEPENDS+=	libwebkitgtk-6.0.so:www/webkit2-gtk@60
CMAKE_ARGS+=	-DENABLE_OAUTH2_WEBKITGTK=OFF
.  else
LIB_DEPENDS+=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41
CMAKE_ARGS+=	-DENABLE_OAUTH2_WEBKITGTK4=OFF
.  endif
.else
CMAKE_ARGS+=	-DENABLE_OAUTH2_WEBKITGTK=OFF -DENABLE_OAUTH2_WEBKITGTK4=OFF
.endif

.include <bsd.port.mk>
