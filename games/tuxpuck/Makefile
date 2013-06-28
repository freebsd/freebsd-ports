# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	tuxpuck
PORTVERSION=	0.8.2
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	http://www.sourcefiles.org/Games/Sports/Miscellaneous/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shufflepuck Cafe Clone

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		vorbis:${PORTSDIR}/audio/libvorbis \
		freetype:${PORTSDIR}/print/freetype2

USE_SDL=	sdl
USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include/libpng15

MANCOMPRESSED=	yes

PLIST_FILES=	bin/${PORTNAME}

MAN6=		${PORTNAME}.6

.include <bsd.port.pre.mk>

post-patch:
	cd ${WRKSRC}; \
	${REINPLACE_CMD} 's|timer_create|_timer_create|g' \
	tuxpuck.c video.c timer.c intro.c tuxpuck.h
	${REINPLACE_CMD} -e 's|sdl-config|$$(SDL_CONFIG)|g' ${WRKSRC}/utils/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN6}.gz ${MAN6PREFIX}/man/man6

.include <bsd.port.post.mk>
