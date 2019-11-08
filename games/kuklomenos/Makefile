# Created by: chinsan
# $FreeBSD$

PORTNAME=	kuklomenos
PORTVERSION=	0.4.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://mbays.freeshell.org/kuklomenos/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but challenging abstract shoot-em-up game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

OPTIONS_DEFINE=	VORBIS
OPTIONS_DEFAULT=	VORBIS
OPTIONS_SUB=	yes

USES=		compiler sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	sound

post-patch:
	@${REINPLACE_CMD} -e \
		's|<SDL/SDL_mixer.h>|"SDL_mixer.h"|g' ${WRKSRC}/SDL_mixer/load_ogg.c
	@${REINPLACE_CMD} -e \
		'/^sounds_DATA/s|Makefile.am||g' ${WRKSRC}/sounds/Makefile.in

.include <bsd.port.mk>
