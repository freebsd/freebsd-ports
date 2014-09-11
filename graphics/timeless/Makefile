# Created by: Jeff Molofee
# $FreeBSD$

PORTNAME=	timeless
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shaun

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD/SDL port of Tran's Timeless Demo with Sound

USE_SDL=	sdl mixer
LDFLAGS+=	-lm

PLIST_FILES=	bin/timeless %%DATADIR%%/time.s3m
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/timeless ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/time.s3m ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
