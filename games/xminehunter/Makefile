# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xminehunter
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif minesweeper game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		motif
USE_XORG=	xpm
ALL_TARGET=	${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="XMineHunter" "" "${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"${PORTNAME}" "" ""

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
		 s|cp |$${BSD_INSTALL_DATA} | ; \
		 s| \($${INSTALL_BIN_PATH}\)| $${DESTDIR}\1|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	(cd ${WRKSRC}/bitmaps && ${INSTALL_DATA} normal.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.xpm)

.include <bsd.port.mk>
