# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xminehunter
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif minesweeper game

LICENSE=	XMINEHUNTER
LICENSE_NAME=	xminehunter license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler motif xorg
USE_XORG=	xpm
ALL_TARGET=	${PORTNAME}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="XMineHunter" "" "${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"${PORTNAME}" "" ""

post-extract:
	@${HEAD} -10 < ${WRKSRC}/xminehunter.cc > ${WRKSRC}/LICENSE

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INSTALL_BIN/s|=.*|= $${PREFIX}/bin| ; \
		 /^INSTALL_SCORE/s|=.*|= $${PREFIX}/lib/X11/${PORTNAME}| ; \
		 /^INCLUDES/s|-I/.*/include|$${CPPFLAGS}| ; \
		 /^LIBS/s|-L/.*/lib|$${LDFLAGS}| ; \
		 s|-lXm |$${MOTIFLIB} | ; \
		 s|^CC =|CXX ?=| ; \
		 s|^CFLAGS =|CXXFLAGS +=| ; \
		 s|$${CC}|$${CXX}| ; \
		 s|$${CFLAGS}|$${CXXFLAGS}| ; \
		 s| \($${INSTALL_SCORE_PATH}\)| $${DESTDIR}\1| ; \
		 s|chmod 333|chmod 633| ; \
		 s|cp |$${BSD_INSTALL_PROGRAM} | ; \
		 s| \($${INSTALL_BIN_PATH}\)| $${DESTDIR}\1|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	(cd ${WRKSRC}/bitmaps && ${INSTALL_DATA} normal.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm)

.include <bsd.port.mk>
