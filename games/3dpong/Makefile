# $FreeBSD$

PORTNAME=	3dpong
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/3dpong/src/ \
		ftp://ftp.billsgames.com/unix/x/3dpong/src/ \
		http://www.newbreedsoftware.com/images/prodicons/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.gif:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	X Window 3D Pong game for 1 or 2 players

LICENSE=	GPLv2

BUILD_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_XORG=	x11
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		XLIB="-L${LOCALBASE}/lib -lX11"

MAN6=		${PORTNAME}.6

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		share/examples/${PORTNAME}/${PORTNAME}-handball.sh \
		share/examples/${PORTNAME}/${PORTNAME}-vs-computer.sh
PLIST_DIRS=	share/examples/${PORTNAME}

PORTDATA=	*
PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

DESKTOP_ENTRIES="3D Pong" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|cat sounds/|cat ${DATADIR}/|g' ${WRKSRC}/src/3dpong.c

post-build:
	@(cd ${WRKSRC} && \
		${LOCALBASE}/bin/giftopnm ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.gif | \
		${LOCALBASE}/bin/pnmtopng > ${PORTNAME}.png)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/src/${MAN6} ${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include <bsd.port.mk>
