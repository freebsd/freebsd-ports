# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/evolution-data-server/Makefile,v 1.218 2013/03/09 09:12:37 kwm Exp $

PORTNAME=	evolution-data-server
PORTVERSION=	2.32.1
PORTREVISION=	12
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The data backends for the Evolution integrated mail/PIM suite

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libgdata.so:${PORTSDIR}/devel/libgdata \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libical.so:${PORTSDIR}/devel/libical \
		libnss3.so:${PORTSDIR}/security/nss \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring

USES=		bison gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack gconf2 libxml2
USE_OPENLDAP=	yes
USE_SQLITE=	3
USE_BDB=	41+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--enable-gnome-keyring=yes \
		--with-openldap=yes \
		--with-libdb=${LOCALBASE}
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_SUB=	VERSION="2.32" EVO_VERSION="1.2"

OPTIONS_DEFINE=	WEATHER KERBEROS
OPTIONS_DEFAULT=WEATHER KERBEROS
OPTIONS_SUB=	yes
WEATHER_DESC=	Weather calendar backend

WEATHER_LIB_DEPENDS=	libgweather.so:${PORTSDIR}/net/libgweather
WEATHER_CONFIGURE_WITH=	weather
KERBEROS_CONFIGURE_ON=	--with-krb5=/usr
KERBEROS_CONFIGURE_OFF=	--without-krb5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
KRB5_LIB=	`/usr/bin/krb5-config gssapi --libs`
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
	@${REINPLACE_CMD} '/g_thread_init/d' \
		${WRKSRC}/calendar/backends/file/e-cal-backend-file.c \
		${WRKSRC}/camel/camel-index-control.c \
		${WRKSRC}/camel/providers/imapx/test-imapx.c \
		${WRKSRC}/libedataserverui/test-name-selector.c \
		${WRKSRC}/servers/groupwise/soap-test.c

.include <bsd.port.mk>
