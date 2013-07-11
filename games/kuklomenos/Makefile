# New ports collection makefile for:	kuklomenos
# Date created:				2008/08/31
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	kuklomenos
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mbays.freeshell.org/kuklomenos/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but challenging abstract shoot-em-up game

LICENSE=	GPLv3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	VORBIS
OPTIONS_DEFAULT=	VORBIS

USE_SDL=	sdl
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHEAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=--disable-sound
PLIST_SUB+=	VORBIS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<SDL/SDL_mixer.h>|"SDL_mixer.h"|g' ${WRKSRC}/SDL_mixer/load_ogg.c
	@${REINPLACE_CMD} -e \
		'/^sounds_DATA/s|Makefile.am||g' ${WRKSRC}/sounds/Makefile.in

.include <bsd.port.mk>
