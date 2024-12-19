PORTNAME=	evolution-data-server
DISTVERSION=	3.56.2
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Centralized access to appointments and contacts
WWW=		https://gnome.pages.gitlab.gnome.org/evolution-data-server/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libnss3.so:security/nss \
		libicudata.so:devel/icu \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41 \
		libwebkitgtk-6.0.so:www/webkit2-gtk@60 \
		libjson-glib-1.0.so:devel/json-glib \
		libnspr4.so:devel/nspr \
		libsecret-1.so:security/libsecret \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libuuid.so:misc/libuuid \
		libvulkan.so:graphics/vulkan-loader \
		libgraphene-1.0.so:graphics/graphene

USES=		cmake cpe desktop-file-utils gettext \
		gnome gperf iconv:wchar_t localbase pathfix pkgconfig \
		python:build sqlite tar:xz xorg
USE_CXXSTD=	gnu++17
USE_GNOME=	glib20 gtk30 gtk40 introspection:build libxml2
USE_XORG=	x11
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

LDFLAGS=	-L${LOCALBASE}/lib

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ARGS=	-DENABLE_INTROSPECTION=ON \
		-DWITH_LIBDB=OFF \
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
OPTIONS_DEFINE=		VAPI WEATHER KERBEROS LDAP
OPTIONS_DEFAULT=	VAPI WEATHER KERBEROS LDAP

VAPI_USES=		vala:build
VAPI_CMAKE_BOOL=	ENABLE_VALA_BINDINGS

WEATHER_DESC=	Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-4.so:net/libgweather4
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

KERBEROS_CMAKE_ON=	-DWITH_KRB5=/usr
KERBEROS_CMAKE_OFF=	-DWITH_KRB5=OFF
KERBEROS_USES=		ssl

LDAP_CMAKE_ON=		-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=		-DWITH_OPENLDAP=OFF
LDAP_USES=		ldap

.include <bsd.port.mk>
