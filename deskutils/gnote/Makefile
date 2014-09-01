# $FreeBSD$
#   $MCom: ports/deskutils/gnote/Makefile,v 1.14 2010/11/15 16:21:49 kwm Exp $

PORTNAME=	gnote
PORTVERSION=	0.7.6
PORTREVISION=	8
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Port of Tomboy to C++, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GNOME=	gnomeprefix gconf2 gtk20 intltool libxml2 libxslt \
		gnomepanel
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	gnote.schemas
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PANELAPPLET_SERVER_DIR="${PREFIX}/libdata/bonobo/servers"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-dbus
INSTALL_TARGET=	install-strip
DOCS=		AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS APPLET
OPTIONS_DEFAULT=APPLET
OPTIONS_SUB=	yes

APPLET_LIB_DEPENDS=	libpanelappletmm-2.6.so:${PORTSDIR}/x11-toolkits/libpanelappletmm
APPLET_CONFIGURE_ENABLE=applet

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/boost|${LOCALBASE}/include/boost|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
