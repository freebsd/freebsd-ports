# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.49a
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D modeling/rendering/animation/gaming package

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		GLEW.1:${PORTSDIR}/graphics/glew \
		IlmThread.6:${PORTSDIR}/graphics/ilmbase

USE_XORG=	x11 xext xmu xi
USE_PYTHON=	2.5+
USE_SDL=	sdl
USE_GL=		gl glu
USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	blender

PORTDOCS=	README bf-members.txt blender-scons.txt  python-dev-guide.txt \
		blender-cmake.txt blender-guardedalloc.txt \
		interface_API.txt blender-scons-dev.txt oldbugs.txt

LANG=		ar bg ca cs de el es fi fr hr hr_HR it ja ko nl pl pt_BR ro \
		ru sr sr@Latn sv uk zh_CN

LANG=		ar bg ca cs de el es fi fr hr hr_HR it ja ko nl pl pt_BR ro \
		ru sr sr@Latn sv uk zh_CN

OPTIONS=	DDS		"DDS file format support" on \
		FFMPEG		"Audio and video support using ffmpeg" on \
		FREETYPE	"Improved font rendering support" on \
		ICONV		"Iconv support for localisation (only with NLS)" off \
		KETSJI		"Build GameEngine and BlenderPlayer" off \
		NLS		"Native language support" on \
		OCFLAGS		"Optimized Cflags" off \
		OPENAL		"3D sound support using OpenAL" off \
		OPENEXR		"High dynamic-range (HDR) support using OpenEXR" on \
		OPENJPEG	"Enhanced JPEG graphics support using OpenJPEG" on \
		OPENMP		"Parallel processing support" off \
		VERSE		"Shared networking support using Verse" on

.include <bsd.port.pre.mk>

BDSUFFIX=	${OSREL}-${ARCH}
.if ${ARCH} == "amd64"
BDSUFFIX=	${OSREL}-x86_64
.endif

MAKE_ENV+=	NAN_FMOD="${LOCALBASE}/"
MAKE_ENV+=	NAN_PYTHON="${LOCALBASE}/"
MAKE_ENV+=	NAN_PYTHON_VERSION=${PYTHON_VER}
MAKE_ENV+=	NAN_JPEG="${LOCALBASE}/"
MAKE_ENV+=	NAN_OPENJPEG="${LOCALBASE}/"
MAKE_ENV+=	NAN_PNG="${LOCALBASE}/"
MAKE_ENV+=	NAN_ZLIB="${LOCALBASE}/"
MAKE_ENV+=	NAN_ODE="${LOCALBASE}/"
MAKE_ENV+=	NAN_GLEW="${LOCALBASE}/"
MAKE_ENV+=	NAN_JUST_BLENDERDYNAMIC="true"
MAKE_ENV+=	WITH_BF_DYNAMICOPENGL="true"

CFLAGS+=	"-I${LOCALBASE}/include"
NANCPPFLAGS=

.if !defined(WITHOUT_DDS)
MAKE_ENV+=	WITH_DDS="true"
.else
MAKE_ENV+=	WITH_DDS="false"
.endif

.if defined(WITHOUT_FFMPEG)
MAKE_ENV+=	WITH_FFMPEG="false"
.else
MAKE_ENV+=	WITH_FFMPEG="true"
MAKE_ENV+=	NAN_USE_FFMPEG_CONFIG="true"
MAKE_ENV+=	NAN_FFMPEG="${LOCALBASE}/"
LIB_DEPENDS+=	avutil.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITHOUT_FREETYPE)
MAKE_ENV+=	WITH_FREETYPE2="false"
.else
MAKE_ENV+=	WITH_FREETYPE2="true"
MAKE_ENV+=	NAN_FREETYPE="${LOCALBASE}/"
MAKE_ENV+=	NAN_FTGL="${LOCALBASE}/"
NANCPPFLAGS+=	"-I${LOCALBASE}/include/freetype2"
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=	ftgl.2:${PORTSDIR}/graphics/ftgl
.endif

.if defined(WITH_KETSJI)
.if ${ARCH} == "amd64"
BROKEN=		GameEngine and BlenderPlayer cannot be build on amd64
.endif
MAKE_ENV+=	NAN_NO_KETSJI="false"
MAKE_ENV+=	NAN_USE_BULLET="true"
MAKE_ENV+=	WITH_BF_BLENDERGAMEENGINE="true"
MAKE_ENV+=	WITH_BF_BLENDERPLAYER="true"
PLIST_SUB+=	KETSJI=""
.else
MAKE_ENV+=	NAN_NO_KETSJI="true"
MAKE_ENV+=	WITH_BF_BLENDERGAMEENGINE="false"
MAKE_ENV+=	WITH_BF_BLENDERPLAYER="false"
PLIST_SUB+=	KETSJI="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
MAKE_ENV+=	INTERNATIONAL="true"

# Iconv support?
.if defined(WITH_ICONV)
USE_ICONV=	yes
MAKE_ENV+=	WITH_ICONV="true"
.else
MAKE_ENV+=	WITH_ICONV="false"
.endif

.if defined(WITHOUT_FREETYPE)
# Implies Freetype2 - ignore the without knob.
MAKE_ENV+=	WITH_FREETYPE2="true"
MAKE_ENV+=	NAN_FREETYPE="${LOCALBASE}/"
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=	ftgl.2:${PORTSDIR}/graphics/ftgl
.endif

PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	WITH_ICONV="false"
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_OCFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

.if defined(WITH_OPENAL)
MAKE_ENV+=	NAN_NO_OPENAL="false"
MAKE_ENV+=	NAN_OPENAL="${LOCALBASE}/"
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
.else
MAKE_ENV+=	NAN_NO_OPENAL="true"
.endif

.if defined(WITHOUT_OPENEXR)
MAKE_ENV+=	WITH_OPENEXR="false"
.else
MAKE_ENV+=	WITH_OPENEXR="true"
MAKE_ENV+=	NAN_OPENEXR="${LOCALBASE}/"
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
NANCPPFLAGS+=	"-I${LOCALBASE}/include/OpenEXR"
.endif

.if defined(WITHOUT_OPENJPEG)
MAKE_ENV+=	WITH_OPENJPEG="false"
.else
MAKE_ENV+=	WITH_OPENJPEG="true"
MAKE_ENV+=	NAN_OPENJPEG="${LOCALBASE}/"
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
.endif

.if defined(WITH_OPENMP)
.if ${OSVERSION} < 700000
BROKEN=		OpenMP support is not available for FreeBSD 6.x and below
.else
MAKE_ENV+=	WITH_BF_OPENMP="true"
.endif
.else
MAKE_ENV+=	WITH_BF_OPENMP="false"
.endif

.if defined(WITHOUT_VERSE)
MAKE_ENV+=	WITH_VERSE="false"
PLIST_SUB+=	VERSE="@comment "
.else
MAKE_ENV+=	WITH_VERSE="true"
PLIST_SUB+=	VERSE=""
.endif

MAKE_ENV+=	NAN_CPPFLAGS="-I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR} \
			${NANCPPFLAGS}"

.if ${ARCH} == "sparc64"
BROKEN=		Fails to link
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|2.5|${PYTHON_VER}|' \
		${WRKSRC}/source/nan_definitions.mk

.if defined(WITHOUT_FFMPEG)
	@${REINPLACE_CMD} -e 's|%%FFMPEGCFLAGS%%||;s|%%FFMPEGLIBS%%||;' \
		${WRKSRC}/user-def.mk
.else
	@${REINPLACE_CMD} -e \
		's|%%FFMPEGCFLAGS%%|$$\(shell pkg-config --cflags libavcodec libavformat libavdevice\)|; \
		s|%%FFMPEGLIBS%%|$$\(shell pkg-config --libs libavcodec libavformat libavdevice\)|;' \
		${WRKSRC}/user-def.mk
.endif

	@${REINPLACE_CMD} -e \
		's|gcc|${CC}|; \
		s|g++|${CXX}|; \
		s|-pipe||; \
		s|-O2|${CFLAGS}|; \
		s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|; \
		s|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/source/nan_compile.mk

	@${REINPLACE_CMD} -e \
		's|-lc_r||; \
		s|-pthread|-lintl -lIlmThread ${PTHREAD_LIBS}|' \
		${WRKSRC}/source/nan_link.mk

	@${REINPLACE_CMD} -e 's|-FIX_NAN_WARN||' \
		${WRKSRC}/source/nan_warn.mk

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/blender ${PREFIX}/bin/blender
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd-${BDSUFFIX}/bin/blender ${PREFIX}/bin/blender-bin
.if defined(WITH_KETSJI)
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd-${BDSUFFIX}/bin/blenderplayer ${PREFIX}/bin/blenderplayer
.endif
.if !defined(WITHOUT_VERSE)
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd-${BDSUFFIX}/bin/verse ${PREFIX}/bin/verse
.endif

	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/release/scripts ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/.blender/.Blanguages ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/.blender/.bfont.ttf ${DATADIR}
.if !defined(WITHOUT_NLS)
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/bin/.blender/locale/${ii}/LC_MESSAGES/blender.mo \
		${DATADIR}/locale/${ii}/LC_MESSAGES/blender.mo
.endfor
.endif

.if !defined(NOPORTDOCS)
	@${CP} -p ${WRKSRC}/README ${WRKSRC}/doc/
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
