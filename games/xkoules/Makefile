PORTNAME=	xkoules
PORTVERSION=	1.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.ucw.cz/~hubicka/koules/packages/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME:S/x//}${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME:S/x//}.png:icons
EXTRACT_ONLY=	${PORTNAME:S/x//}${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast action arcade-style game for X Window
WWW=		https://www.ucw.cz/~hubicka/koules/English/koules.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	x11 xext

MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="XKoules" "" "${PORTNAME}" \
		"${PORTNAME} -M" "Game;ArcadeGame;" ""

WRKSRC=		${WRKDIR}/${PORTNAME:S/x//}${PORTVERSION}

PORTDOCS=	ANNOUNCE ChangeLog Koules.FAQ README

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${WRKSRC}/xkoules.6 ${WRKSRC}/xkoules.man

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME:S/x//}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
