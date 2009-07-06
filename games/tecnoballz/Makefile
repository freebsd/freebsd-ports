# New ports collection makefile for:	TecnoballZ
# Date created:				19 Jan 2005
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	tecnoballz
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/TecnoballZ/download/ \
		http://mirror.amdmi3.ru/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A brick breaker (Arkanoid-like game)

LIB_DEPENDS=	mikmod.2:${PORTSDIR}/audio/libmikmod \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis \
		ogg.6:${PORTSDIR}/audio/libogg \
		smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_AUTOTOOLS=	automake:19 aclocal:19
USE_SDL=	sdl mixer image
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN6=		tecnoballz.6

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
	@cd ${WRKSRC}/src/TecnoballZ && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
