# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.43
PORTREVISION=	2
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dyeske@yahoo.com
COMMENT=	3D modeling/rendering/animation/gaming package

BUILD_DEPENDS=	${X11BASE}/lib/libftgl.a:${PORTSDIR}/graphics/ftgl
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		SDL.11:${PORTSDIR}/devel/sdl12 \
		Half.4:${PORTSDIR}/graphics/OpenEXR \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

PLIST_FILES=	bin/blender
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_PYTHON=	2.4+
USE_SDL=	sdl
USE_GL=		yes
USE_GMAKE=	yes

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|sdl11-config|${SDL_CONFIG}|; \
		s|2.3|${PYTHON_VER}|' \
		${WRKSRC}/source/nan_definitions.mk

	@${REINPLACE_CMD} -e \
		's|gcc|${CC}|; \
		s|g++|${CXX}|; \
		s|-O2|${CFLAGS}|; \
		s|-DGAMEBLENDER=1||; \
		s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|; \
		s|/usr/X11R6|${X11BASE}|' \
		${WRKSRC}/source/nan_compile.mk

	@${REINPLACE_CMD} -e \
		's|-lc_r||; \
		s|-pthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/source/nan_link.mk

	@${REINPLACE_CMD} -e \
		's|-FIX_NAN_WARN||' \
		${WRKSRC}/source/nan_warn.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd/bin/blender ${PREFIX}/bin

.include <bsd.port.post.mk>
