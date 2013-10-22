# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	epdfview
PORTVERSION=	0.1.8
PORTREVISION=	4
CATEGORIES=	graphics print gnome
MASTER_SITES=	http://trac.emma-soft.com/epdfview/chrome/site/releases/ \
		http://mirror.slitaz.org/sources/packages/e/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A lightweight PDF document viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	poppler-glib.8:${PORTSDIR}/graphics/poppler-glib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		iconv gmake pkgconfig
USE_GNOME=	gtk20 intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS NLS

MAN1=	epdfview.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=--with-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ARGS+=--without-cups
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/gtk/StockIcons.h

post-install:
	${REINPLACE_CMD} -e 's,Icon.*,Icon=${DATADIR}/pixmaps/icon_epdfview-48.png,' ${WRKSRC}/data/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/data/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@-update-desktop-database

.include <bsd.port.mk>
