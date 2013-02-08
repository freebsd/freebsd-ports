# $FreeBSD$
#   $MCom: ports/deskutils/gnote/Makefile,v 1.14 2010/11/15 16:21:49 kwm Exp $

PORTNAME=	gnote
PORTVERSION=	0.7.6
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A port of Tomboy to C++, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre.3:${PORTSDIR}/devel/pcre \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		boost_filesystem:${PORTSDIR}/devel/boost-libs \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix gconf2 gtk20 intltool libxml2 libxslt \
		ltverhack gnomepanel
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	gnote.schemas
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PANELAPPLET_SERVER_DIR="${PREFIX}/libdata/bonobo/servers"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-dbus
DOCS=		AUTHORS ChangeLog NEWS README TODO
MAN1=		gnote.1

.if !defined(WITHOUT_APPLET)
LIB_DEPENDS+=	panelappletmm-2.6:${PORTSDIR}/x11-toolkits/libpanelappletmm
CONFIGURE_ARGS+=--enable-applet
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-applet
PLIST_SUB+=	APPLET="@comment "
.endif

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/boost|${LOCALBASE}/include/boost|g' \
		${WRKSRC}/configure

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
