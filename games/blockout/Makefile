# New ports collection makefile for: games/blockout
# Date created:		06 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	blockout
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blockout
DISTNAME=	bl24-src-linux-i586

MAINTAINER=	stast@bsdportal.ru
COMMENT=	BlockOut II is an adaptation of the original Blockout DOS game

ONLY_FOR_ARCHS=	i386

USE_SDL=	mixer sdl
USE_GMAKE=	yes
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/bl24_lin_src
BUILD_WRKSRC=	${WRKSRC}/BlockOut

FETCH_ARGS?=	-pRr

pre-build:
		cd ${WRKSRC}/ImageLib/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/BlockOut/blockout ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/ImageLib/src/libimagelib.a ${PREFIX}/lib
		${MKDIR} ${DATADIR}
		${MKDIR} ${DATADIR}/sounds
		${MKDIR} ${DATADIR}/images
.		for i in allPieces background background2 background3 font gameover gameovera marble \
marbleg menuback menucredits menufont menufont2 menupit online onlinea spark sparka sprites spritesa star_crystal_grid
		    ${INSTALL_DATA} ${WRKSRC}/BlockOut/images/${i}.png ${DATADIR}/images
.		endfor
.		for s in blub empty empty2 hit level level2 line line2 tchh welldone welldone2 wozz
		    ${INSTALL_DATA} ${WRKSRC}/BlockOut/sounds/${s}.wav ${DATADIR}/sounds
.		endfor
		${INSTALL_DATA} ${WRKSRC}/BlockOut/sounds/music.mp3 ${DATADIR}/sounds
post-install:
		${SED} -e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/g" ${PKGMESSAGE};

.include <bsd.port.mk>
