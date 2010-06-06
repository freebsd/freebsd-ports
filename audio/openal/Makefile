# New ports collection makefile for:	openal
# Date created:		25 September 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openal
PORTVERSION=	20060211
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://openal.org/openal_webstf/downloads/
DISTVERSION=	0.0.8

MAINTAINER=	erik@smluc.org
COMMENT=	A 3D positional spatialized sound library

CONFLICTS=	openal-soft-[0-9]*

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-capture
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
WANT_SDL=	yes
USE_LDCONFIG=	yes

OPTIONS=	ARTS "aRts backend" off \
		ESD "esd backend" off \
		SDL "SDL backend" off \
		VORBIS "vorbis support" off \
		SMPEG "smpeg support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SMPEG)
WITH_SDL=	yes	# smpeg requires SDL
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
.else
CONFIGURE_ARGS+=--disable-arts
.endif

.if defined(WITH_ESD)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
.else
CONFIGURE_ARGS+=--disable-esd
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ENV+=	HAVESDL="${SDL_CONFIG}"
CONFIGURE_ARGS+=--enable-sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if defined(WITH_SMPEG)
LIB_DEPENDS+=	smpeg.1:${PORTSDIR}/multimedia/smpeg
CONFIGURE_ARGS+=--enable-smpeg
.else
CONFIGURE_ARGS+=--disable-smpeg
.endif

.if ${ARCH} == "i386"
OPTIONS+=	X86_ASM "Enable x86 assembly code" on
.if !defined(WITHOUT_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif
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
.if defined(WITHOUT_X86_ASM)
	@${REINPLACE_CMD} -e '/^NASM=/ s|=.*|=no|' ${WRKSRC}/configure
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
