# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openal
PORTVERSION=	20060211
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	GENTOO
DISTNAME=	${PORTNAME}-0.0.8

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	3D positional spatialized sound library

LICENSE=	GPLv2

CONFLICTS=	openal-soft-[0-9]*

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-capture \
		--disable-arts \
		--disable-esd
USES=		pathfix pkgconfig gmake libtool:keepla
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SDL VORBIS SMPEG ALSA
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM
SMPEG_DESC=	smpeg support

SDL_USE=		SDL=sdl
SDL_CONFIGURE_ENABLE=	sdl
VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=vorbis
SMPEG_LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg
SMPEG_CONFIGURE_ENABLE=	mp3
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
ASM_BUILD_DEPENDS=	nasm:devel/nasm

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64\*/amd64\* | \*ia64\*/g; \
		/CPPFLAGS=/ d; s/ \*linux\*)/ \*bsd\*)/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/#include/ s|SDL/||' \
		${WRKSRC}/src/extensions/al_ext_mp3.c
	@${REINPLACE_CMD} -e 's|"mixaudio16_mmx_prk.h"|"arch/i386/mixaudio16_mmx_prk.h"|' \
		${WRKSRC}/src/mixaudio16.h
	@${REINPLACE_CMD} -e 's|@requirements@||' \
		${WRKSRC}/admin/pkgconfig/openal.pc.in
post-patch-ASM-off:
	@${REINPLACE_CMD} -e '/^NASM=/ s|=.*|=no|' ${WRKSRC}/configure

.include <bsd.port.mk>
