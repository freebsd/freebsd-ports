# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xemeraldia
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.reloco.com.ar/xemeraldia/ \
		SUNSITE/games/tetris \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Falling blocks game

USES=		gnome pkgconfig
USE_GNOME=	cairo gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		${DESKTOPDIR}/${PORTNAME}.desktop \
		%%NLS%%share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
		%%NLS%%share/locale/gl/LC_MESSAGES/${PORTNAME}.mo \
		share/pixmaps/${PORTNAME}.png \
		share/pixmaps/${PORTNAME}.xpm

PORTDOCS=	NEWS README
OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|$${prefix}/games|$${prefix}/bin|; \
		s|/var/games/x|.x|; \
		s|) install-data-hook|)|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@prefix@/games/||; \
		s|^Icon.*|Icon=${PORTNAME}|' \
		${WRKSRC}/xemeraldia.desktop.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
