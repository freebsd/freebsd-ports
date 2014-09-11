# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tecnoballz
PORTVERSION=	0.92
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/TecnoballZ/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Brick breaker (Arkanoid-like game)

LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg \
		libsmpeg.so:${PORTSDIR}/multimedia/smpeg

USES=		gmake tar:tgz
USE_AUTOTOOLS=	automake aclocal
AUTOMAKE_ARGS=	--add-missing
USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes

PORTDATA=	*

DESKTOP_ENTRIES=	"TecnoballZ" \
			"A brick breaker (Arkanoid-like game)" \
			"" \
			"tecnoballz" \
			"Game;ArcadeGame;" \
			false

post-patch:
	@${FIND} ${WRKSRC}/include -name '*.h' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|SDL/||'
	@${REINPLACE_CMD} -e '/^CXXFLAGS=[^$$]*$$/ s|^|#|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(prefix)/games|$$(prefix)/bin|' \
		${WRKSRC}/Makefile.am ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's|supervisor.c|&c|' ${WRKSRC}/src/Makefile.am
.for f in tecnoballz.cc tiles_background.cc sprite_ship.cc controller_magnetic_eyes.cc
	@${REINPLACE_CMD} -e '/rand/ s|(Sint32)|(intptr_t)|' ${WRKSRC}/src/${f}
.endfor

post-install:
	@cd ${WRKSRC}/src/TecnoballZ && ${FIND} . -name "Makefile*" -delete
	@cd ${WRKSRC}/src/TecnoballZ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
