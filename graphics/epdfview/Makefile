# New ports collection makefile for:	epdfview
# Date created:				2006/06/01
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	epdfview
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	graphics print gnome
MASTER_SITES=	http://trac.emma-soft.com/epdfview/chrome/site/releases/ \
		http://mirror.slitaz.org/sources/packages/e/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A lightweight PDF document viewer

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	poppler-glib.6:${PORTSDIR}/graphics/poppler-gtk

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	CUPS	"Use cups printing system"		off \
		NLS	"Native language support"		on

MAN1=	epdfview.1

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS)
CONFIGURE_ARGS+=--with-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ARGS+=--without-cups
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${REINPLACE_CMD} -e 's,Icon.*,Icon=${DATADIR}/pixmaps/icon_epdfview-48.png,' ${WRKSRC}/data/${PORTNAME}.desktop
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@-update-desktop-database

.include <bsd.port.post.mk>
