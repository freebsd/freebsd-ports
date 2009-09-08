# New ports collection makefile for:	brikx
# Date created:		07 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	brikx
PORTVERSION=	0.4.5
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		SF/brikx/Brikx/${PORTVERSION}
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game - remove all tiles from the table

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image ttf
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Brikx" \
		"Puzzle game" \
		"${DATADIR}/tilesets/stone/49.png" \
		"brikx" \
		"Game;LogicGame;" \
		false

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/DIR_DATA/ s|data/|${DATADIR}/|' \
		${WRKSRC}/src/brikx.h

post-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/src/data && ${COPYTREE_SHARE} "*" ${DATADIR}/

.include <bsd.port.mk>
