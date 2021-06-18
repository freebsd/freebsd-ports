# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	evolution-data-server
DISTVERSION=	3.40.2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libfribidi.so:converters/fribidi \
		libgcr-base-3.so:security/gcr \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgdata.so:devel/libgdata \
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

USES=		bdb:5 cmake compiler:c++11-lib gettext gnome gperf \
		iconv localbase pathfix pkgconfig python:3.6+,build\
		sqlite tar:xz
USE_CXXSTD=	gnu++11
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_VALA_BINDINGS=ON \
		-DENABLE_INTROSPECTION=ON \
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
OPTIONS_DEFINE=	WEATHER KERBEROS LDAP
OPTIONS_DEFAULT=WEATHER KERBEROS LDAP

KERBEROS_CMAKE_ON=	-DWITH_KRB5=/usr
KERBEROS_CMAKE_OFF=	-DWITH_KRB5=OFF
KERBEROS_USES=		ssl

LDAP_CMAKE_ON=		-DWITH_OPENLDAP=${LOCALBASE}
LDAP_CMAKE_OFF=		-DWITH_OPENLDAP=OFF
LDAP_USE=		openldap=yes

WEATHER_DESC=	Weather calendar backend
WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CMAKE_BOOL=	ENABLE_WEATHER

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| python3| ${PYTHON_VERSION}|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
