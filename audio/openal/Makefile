# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openal
PORTVERSION=	20060211
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://openal.org/openal_webstf/downloads/
DISTVERSION=	0.0.8

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	A 3D positional spatialized sound library

CONFLICTS=	openal-soft-[0-9]*

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-capture \
		--disable-arts
USES=		pathfix pkgconfig gmake
WANT_SDL=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ESOUND SDL VORBIS SMPEG
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM
SMPEG_DESC=	smpeg support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSMPEG}
WITH_SDL=	yes	# smpeg requires SDL
.endif

.if ${PORT_OPTIONS:MESD}
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.else
CONFIGURE_ARGS+=--disable-esd
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl
CONFIGURE_ENV+=	HAVESDL="${SDL_CONFIG}"
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MSMPEG}
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--enable-smpeg
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${PORT_OPTIONS:MASM}
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif


NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON_ia64=	does not compile

post-patch:
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/; \
		s/x86_64\*/amd64\* | \*ia64\*/g; \
		/CPPFLAGS=/ d; s/ \*linux\*)/ \*bsd\*)/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/#include/ s|SDL/||' \
		${WRKSRC}/src/extensions/al_ext_mp3.c
	@${REINPLACE_CMD} -e 's|"mixaudio16_mmx_prk.h"|"arch/i386/mixaudio16_mmx_prk.h"|' \
		${WRKSRC}/src/mixaudio16.h
	@${REINPLACE_CMD} -e 's|@requirements@||; \
		s|Libs: |&${PTHREAD_LIBS} |;\
		s|Cflags: |&${PTHREAD_CFLAGS} |' \
		${WRKSRC}/admin/pkgconfig/openal.pc.in
.if ! ${PORT_OPTIONS:MASM}
	@${REINPLACE_CMD} -e '/^NASM=/ s|=.*|=no|' ${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
