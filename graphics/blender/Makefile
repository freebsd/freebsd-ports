# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.45
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/	\
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	dyeske@gmail.com
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		SDL.11:${PORTSDIR}/devel/sdl12 \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg

PLIST_FILES=	bin/blender
USE_XORG=	x11 xext xmu xi
USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_SDL=	sdl
USE_GL=	gl glu
USE_GMAKE=	yes

PORTDOCS=	README bf-members.txt blender-scons.txt  python-dev-guide.txt \
		blender-cmake.txt blender-guardedalloc.txt \
		interface_API.txt blender-scons-dev.txt oldbugs.txt

OPTIONS=	OCFLAGS "With Optimized Cflags" off \
		NOPORTDOCS "Don't Install Docs" off

.include <bsd.port.pre.mk>

MAKE_ENV+=	NAN_CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/OpenEXR \
		-I${PYTHON_INCLUDEDIR}/"
MAKE_ENV+=	NAN_FREETYPE="${LOCALBASE}/"
MAKE_ENV+=	NAN_OPENEXR="${LOCALBASE}/"
MAKE_ENV+=	NAN_OPENAL="${LOCALBASE}/"

.if defined(WITH_OCFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

.if ${ARCH} == "amd64"
MAKE_ENV+=	NAN_NO_KETSJI="true"
MAKE_ENV+=	WITH_BF_BLENDERGAMEENGINE="false"
MAKE_ENV+=	WITH_BF_BLENDERPLAYER="false"
.else
MAKE_ENV+=	WITH_BF_BLENDERGAMEENGINE="true"
MAKE_ENV+=	WITH_BF_OPENAL="true"
MAKE_ENV+=	WITH_BF_BLENDERPLAYER="true"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

pre-configure:
	@${REINPLACE_CMD} -e \
		's|sdl11-config|${SDL_CONFIG}|; \
		s|2.3|${PYTHON_VER}|' \
		${WRKSRC}/source/nan_definitions.mk

	@${REINPLACE_CMD} -e \
		's|gcc|${CC}|; \
		s|g++|${CXX}|; \
		s|-pipe||; \
		s|-O2|${CFLAGS}|; \
		s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|; \
		s|/usr/X11R6|${X11BASE}|' \
		${WRKSRC}/source/nan_compile.mk

	@${REINPLACE_CMD} -e \
		's|-lc_r||; \
		s|-pthread|-lintl -lIlmThread ${PTHREAD_LIBS}|' \
		${WRKSRC}/source/nan_link.mk

	@${REINPLACE_CMD} -e \
		's|-FIX_NAN_WARN||' \
		${WRKSRC}/source/nan_warn.mk
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd/bin/blender ${PREFIX}/bin
.if !defined(WITH_NOPORTDOCS)
	@${CP} -p ${WRKSRC}/README ${WRKSRC}/doc/
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
