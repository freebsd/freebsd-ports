# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	epdfview
PORTVERSION=	0.1.8
PORTREVISION=	14
CATEGORIES=	graphics print gnome
MASTER_SITES=	FRUGALWARE/xapps-extra/${PORTNAME} \
		ftp://ftp.slackware.com/.1/blfs/conglomeration/${PORTNAME}/ \
		http://anduin.linuxfromscratch.org/sources/BLFS/conglomeration/${PORTNAME}/ \
		http://pkgs.fedoraproject.org/repo/pkgs/${PORTNAME}/${DISTNAME}${EXTRACT_SUFX}/e50285b01612169b2594fea375f53ae4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight PDF document viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	cppunit-config:devel/cppunit
LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		desktop-file-utils iconv gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20 intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CUPS NLS
OPTIONS_SUB=	yes

CUPS_CONFIGURE_WITH=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

NLS_USES=	gettext
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/gtk/StockIcons.h

post-install:
	${REINPLACE_CMD} -e 's,Icon.*,Icon=${DATADIR}/pixmaps/icon_epdfview-48.png,' ${WRKSRC}/data/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/data/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
