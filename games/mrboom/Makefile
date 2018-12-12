# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mrboom
PORTVERSION=	4.5
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	8 players Bomberman clone

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libmodplug.so:audio/libmodplug

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
USE_SDL=	sdl2 mixer2

GH_ACCOUNT=	Javanaise
GH_PROJECT=	mrboom-libretro

ALL_TARGET=	mrboom

CFLAGS+=	`sdl2-config --cflags`
LDFLAGS+=	`sdl2-config --libs`

MAKE_ENV+=	LIBSDL2=1

PLIST_FILES=	bin/mrboom man/man6/mrboom.6.gz \
		share/applications/mrboom.desktop share/pixmaps/mrboom.png

post-patch:
	@${REINPLACE_CMD} -E '/^GIT_VERSION/d' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/Assets/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/Assets/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
