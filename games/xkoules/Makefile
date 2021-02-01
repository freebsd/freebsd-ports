# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xkoules
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.ucw.cz/~hubicka/koules/packages/ \
		GENTOO \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME:S/x//}${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME:S/x//}.png:icons
EXTRACT_ONLY=	${PORTNAME:S/x//}${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast action arcade-style game for X Window

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME:S/x//}${PORTVERSION}

USES=		imake xorg
USE_XORG=	x11 xext
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	ANNOUNCE ChangeLog Koules.FAQ README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="XKoules" "" "${PORTNAME}" \
		"${PORTNAME} -M" "Game;ArcadeGame;" ""

post-extract:
	@${CP} ${WRKSRC}/xkoules.6 ${WRKSRC}/xkoules.man

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME:S/x//}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
