# Created by: Jeff Molofee
# $FreeBSD$

PORTNAME=	timeless
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/shaun

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD/SDL port of Tran's Timeless Demo with Sound

USES=		sdl
USE_SDL=	sdl mixer
LDFLAGS+=	-lm

PLIST_FILES=	bin/timeless %%DATADIR%%/time.s3m

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/timeless ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/time.s3m ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
