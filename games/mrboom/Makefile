PORTNAME=	mrboom
PORTVERSION=	5.2
CATEGORIES=	games
MASTER_SITES=	https://github.com/Javanaise/mrboom-libretro/releases/download/${PORTVERSION}/
DISTNAME=	MrBoom-src-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	8 players Bomberman clone

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmodplug.so:audio/libmodplug

USES=		compiler:c++11-lang gmake minizip sdl
USE_SDL=	mixer2 sdl2

MAKE_ENV+=	LIBSDL2=1
ALL_TARGET=	mrboom

CFLAGS+=	`sdl2-config --cflags`
LDFLAGS+=	`sdl2-config --libs`

PLIST_FILES=	bin/mrboom \
		man/man6/mrboom.6.gz \
		share/applications/mrboom.desktop \
		share/pixmaps/mrboom.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/Assets/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/Assets/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
