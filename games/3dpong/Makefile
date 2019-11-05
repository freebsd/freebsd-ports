# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	3dpong
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/3dpong/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window 3D Pong game for 1 or 2 players

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USES=		gmake xorg
USE_XORG=	x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		XLIB="-L${LOCALBASE}/lib -lX11"
USE_CSTD=	gnu89

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DESKTOP_ENTRIES="3D Pong" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|cat sounds/|cat ${DATADIR}/|g' \
		${WRKSRC}/src/3dpong.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
