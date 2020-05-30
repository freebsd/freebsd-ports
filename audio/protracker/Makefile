# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protracker
PORTVERSION=	1.17
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt:extras
DISTFILES=	${PORTNAME}-extras-1${EXTRACT_SUFX}:extras

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Amiga ProTracker clone

LICENSE=	WTFPL

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake localbase:ldflags sdl
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	8bitbubsy
GH_PROJECT=	pt2-clone
USE_SDL=	sdl2

CFLAGS_i386+=	-msse2

PLIST_FILES=	bin/protracker \
		man/man1/protracker.1.gz \
		share/applications/protracker.desktop \
		share/pixmaps/protracker.png

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${MANPREFIX}/man/man1 \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/release/other/pt2-clone ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-extras-1/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-extras-1/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
