# New ports collection makefile for:	gnote
# Date created:				20 July 2009
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gnote/Makefile,v 1.11 2010/03/14 05:52:37 marcus Exp $
#

PORTNAME=	gnote
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A port of Tomboy to C++, note taking application

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 intltool ltverhack gnomepanel
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GCONF_SCHEMAS=	gnote.schemas
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PANELAPPLET_SERVER_DIR="${PREFIX}/libdata/bonobo/servers"
CONFIGURE_ARGS=	--disable-dbus
DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
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
