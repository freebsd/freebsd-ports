# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/evolution-data-server/Makefile 19001 2014-02-07 11:57:24Z kwm $

PORTNAME=	evolution-data-server
PORTVERSION=	3.6.4
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcr>=3.4.1:${PORTSDIR}/security/gcr
LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		liboauth.so:${PORTSDIR}/net/liboauth \
		libgoa-1.0.so:${PORTSDIR}/net/gnome-online-accounts \
		libgdata.so.13:${PORTSDIR}/devel/libgdata \
		libical.so:${PORTSDIR}/devel/libical \
		libnss3.so:${PORTSDIR}/security/nss \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

USE_XZ=		yes
USES=		bison gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gconf2 \
		libxml2 gtk30 introspection:build
USE_OPENLDAP=	yes
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
USE_BDB=	5
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Evolution.DefaultSources.gschema.xml \
		org.gnome.evolution.eds-shell.gschema.xml \
		org.gnome.evolution-data-server.addressbook.gschema.xml \
		org.gnome.evolution-data-server.calendar.gschema.xml \
		org.gnome.evolution.shell.network-config.gschema.xml

PLIST_SUB=	VERSION="3.6" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if ${PORT_OPTIONS:MWEATHER}
LIB_DEPENDS+=		libgweather-3.so:${PORTSDIR}/net/libgweather
CONFIGURE_ARGS+=	--enable-weather
PLIST_SUB+=		WEATHER=""
.else
CONFIGURE_ARGS+=	--disable-weather
PLIST_SUB+=		WEATHER="@comment "
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
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
