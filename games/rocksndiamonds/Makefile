# New ports collection makefile for:	rocksndiamonds
# Date created:		27 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rocksndiamonds
PORTVERSION=	3.0.8
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/ \
		http://homepages.compuserve.de/rocksndiamonds/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colorful Boulderdash'n'Emerald Mine'n'Sokoban'n'Stuff

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" MAKE="${GMAKE}" X11_PATH="${X11BASE}" \
		RO_GAME_DIR=${DATADIR} RW_GAME_DIR=${DATADIR}/scores \
		X11_PATH=${X11BASE} OPTIONS="${CFLAGS}"

MAN1=		rocksndiamonds.1

.if defined(WITH_SDL)
USE_SDL=	image mixer sdl
ALL_TARGET=	sdl
.else
USE_XLIB=	yes
ALL_TARGET=	x11
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's:sdl-config:$${SDL_CONFIG}:g' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - graphics levels scores sounds | \
		${TAR} -C ${DATADIR} -xf -
	@${CHMOD} 777 ${DATADIR}/scores
.if !defined(NOPPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in CHANGES CREDITS HARDWARE README TODO
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/elements
	${INSTALL_DATA} ${WRKSRC}/docs/elements/*.txt ${DOCSDIR}/elements
.endif

.include <bsd.port.mk>
