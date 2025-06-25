PORTNAME=	tecnoballz
PORTVERSION=	0.93.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/TecnoballZ/download/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Brick breaker (Arkanoid-like game)
WWW=		https://linux.tlk.fr/games/TecnoballZ/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmikmod.so:audio/libmikmod \
		libvorbisfile.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libsmpeg.so:multimedia/smpeg \
		libtinyxml.so:textproc/tinyxml

USES=		autoreconf compiler:c++11-lang gmake sdl tar:tgz
USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PORTDATA=	*

DESKTOP_ENTRIES="TecnoballZ" \
		"A brick breaker (Arkanoid-like game)" \
		"" \
		"tecnoballz" \
		"Game;ArcadeGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS=[^$$]*$$/ s|^|#|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|$$(prefix)/games|$$(prefix)/bin|; \
		/chmod/ d; /chown/ d' ${WRKSRC}/src/Makefile.am
.for f in tecnoballz.cc tiles_background.cc sprite_ship.cc controller_magnetic_eyes.cc
	@${REINPLACE_CMD} -e '/rand/ s|(Sint32)|(intptr_t)|' ${WRKSRC}/src/${f}
.endfor

post-install:
	${MV} ${STAGEDIR}/var/games/tecnoballz/tecnoballz.hi \
		${STAGEDIR}/var/games/tecnoballz/tecnoballz.hi.sample

.include <bsd.port.mk>
