# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protracker
DISTVERSION=	2.3d
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Amiga ProTracker clone

LICENSE=	WTFPL
LICENSE_NAME=	Do What The Fuck You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		localbase:ldflags
USE_SDL=	sdl2

LDFLAGS+=	-lSDL2 -lm

PLIST_FILES=	bin/protracker

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/trunk/src/*.c \
		${WRKSRC}/trunk/src/gfx/*.c -o ${WRKSRC}/trunk/protracker

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/trunk/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
