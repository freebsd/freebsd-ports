# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.218 2013/03/09 09:12:37 kwm Exp $

PORTNAME=	evolution-data-server
PORTVERSION=	2.32.1
PORTREVISION=	5
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup \
		gdata.7:${PORTSDIR}/devel/libgdata \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		ical:${PORTSDIR}/devel/libical \
		nss3:${PORTSDIR}/security/nss \
		tasn1:${PORTSDIR}/security/libtasn1 \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		bison pathfix gettext pkgconfig
USE_GNOME=	gnomeprefix intlhack ltverhack ltasneededhack gconf2 \
		libxml2
USE_OPENLDAP=	yes
USE_SQLITE=	3
USE_AUTOTOOLS=	libtool
USE_BDB=	41+
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-gnome-keyring=yes \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_SUB=	VERSION="2.32" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
WEATHER_DESC=	Weather calendar backend

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if ${PORT_OPTIONS:MWEATHER}
LIB_DEPENDS+=		gweather:${PORTSDIR}/net/libgweather
CONFIGURE_ARGS+=	--with-weather
PLIST_SUB+=		WEATHER=""
.else
CONFIGURE_ARGS+=	--without-weather
PLIST_SUB+=		WEATHER="@comment "
.endif

EDS_BDB_MSG=	"!!!WARNING!!!: Berkeley Database version is ${BDB_VER}.  If this is an upgrade, you may experience problems if you or any other Evolution-data-server users were previously using BDB_VER 41."

pre-everything::
	@if [ x"${BDB_VER}" != x"41" ]; then \
		${ECHO_MSG} ${EDS_BDB_MSG} | ${FMT} 75 79 ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g ; \
		s|heimlibs=".*"|heimlibs="${KRB5_LIB}"|g ; \
		s|-DGTK_DISABLE_DEPRECATED||g ; \
		s|-DG_DISABLE_DEPRECATED||g ; \
		s|-Wl,--no-undefined||g ; \
		s|-Wmissing-include-dirs||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
