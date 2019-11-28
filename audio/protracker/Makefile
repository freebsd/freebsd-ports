# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protracker
DISTVERSION=	2.b${BETA_VERSION}
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	https://16-bits.org/ \
		LOCAL/ehaupt
DISTFILES=	pt2-clone-b${BETA_VERSION}-code${EXTRACT_SUFX} \
		${PORTNAME}-extras-1${EXTRACT_SUFX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Amiga ProTracker clone

LICENSE=	WTFPL

USES=		localbase:ldflags sdl zip
USE_CSTD=	c99
USE_SDL=	sdl2

BETA_VERSION=	37

CFLAGS_i386+=	-msse2
LDFLAGS+=	-lSDL2 -lm

PLIST_FILES=	bin/protracker man/man1/protracker.1.gz \
		share/applications/protracker.desktop \
		share/pixmaps/protracker.png

WRKSRC=		${WRKDIR}/pt2-clone-code

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/src/*.c \
		${WRKSRC}/src/gfx/*.c -o ${WRKSRC}/protracker

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${MANPREFIX}/man/man1 \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-extras-1/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
