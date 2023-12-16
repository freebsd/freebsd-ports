PORTNAME=	evolution-data-server
DISTVERSION=	3.44.4
PORTREVISION=	5
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite
WWW=		https://wiki.gnome.org/Apps/Evolution

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libfribidi.so:converters/fribidi \
		libgcr-base-3.so:security/gcr \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgdata.so:devel/libgdata \
		libharfbuzz.so:print/harfbuzz \
		libical.so:devel/libical \
		libnss3.so:security/nss \
		libicudata.so:devel/icu \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libp11-kit.so:security/p11-kit \
		libnspr4.so:devel/nspr \
		libsecret-1.so:security/libsecret \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		bdb:5 cmake compiler:c++11-lib cpe gettext gnome gperf \
		iconv:wchar_t localbase pathfix pkgconfig python:build\
		sqlite tar:xz xorg
USE_CXXSTD=	gnu++11
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build libxml2
USE_XORG=	x11
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

CMAKE_ARGS=	-DENABLE_INTROSPECTION=ON \
		-DENABLE_UOA=OFF

CMAKE_ARGS+=	-DWITH_LIBDB_CFLAGS=-I${LOCALBASE}/include/db5 \
		-DWITH_LIBDB_LIBS="-L${LOCALBASE}/lib -ldb-5"

GLIB_SCHEMAS=	org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution-data-server.gschema.xml \
		org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	EVO_VERSION="1.2"

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	WEATHER KERBEROS LDAP VAPI
OPTIONS_DEFAULT=WEATHER KERBEROS LDAP VAPI

KERBEROS_CMAKE_ON=	-DWITH_KRB5=/usr
KERBEROS_CMAKE_OFF=	-DWITH_KRB5=OFF
KERBEROS_USES=		ssl

LDAP_CMAKE_ON=		-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=		-DWITH_OPENLDAP=OFF
LDAP_USES=		ldap

VAPI_USES=		vala:build
VAPI_CMAKE_BOOL=	ENABLE_VALA_BINDINGS

WEATHER_DESC=	Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

.include <bsd.port.options.mk>

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
