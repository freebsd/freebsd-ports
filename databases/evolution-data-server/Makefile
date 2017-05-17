# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-data-server
PORTVERSION=	3.22.7
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libgcr-base-3.so:security/gcr \
		liboauth.so:net/liboauth \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgdata.so:devel/libgdata \
		libical.so:devel/libical \
		libicui18n.so:devel/icu \
		libnss3.so:security/nss \
		libtasn1.so:security/libtasn1 \
		libicudata.so:devel/icu \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libp11-kit.so:security/p11-kit \
		libnspr4.so:devel/nspr \
		libsecret-1.so:security/libsecret

PORTSCOUT=	limitw:1,even

USES=		bdb:5 bison compiler:c++11-lib gettext gmake gnome gperf \
		iconv:wchar_t libtool localbase pathfix pkgconfig ssl \
		sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build libxml2
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--with-openldap=yes \
		--disable-uoa \
		--enable-vala-bindings \
		--disable-gtk-doc \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution-data-server.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.22" EVO_VERSION="1.2"

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

WEATHER_LIB_DEPENDS=	libgweather-3.so:net/libgweather
WEATHER_CONFIGURE_ENABLE=	weather

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS} && exists(/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 5."

pre-everything::
	@if [ x"${BDB_VER}" != x"5" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-Wl,--no-undefined||g ; \
		s|-Wnoexcept||g ; \
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
