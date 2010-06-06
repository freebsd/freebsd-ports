# New ports collection makefile for:	kuklomenos
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	kuklomenos
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mbays.freeshell.org/kuklomenos/src/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but challenging abstract shoot-em-up game

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

OPTIONS=	VORBIS "Enable Ogg/Vorbis support" on

USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include ${PTHEAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-sound
PLIST_SUB+=	VORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<SDL/SDL_mixer.h>|"SDL_mixer.h"|g' ${WRKSRC}/SDL_mixer/load_ogg.c
	@${REINPLACE_CMD} -e \
		'/^sounds_DATA/s|Makefile.am||g' ${WRKSRC}/sounds/Makefile.in

.include <bsd.port.post.mk>
