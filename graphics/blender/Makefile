# New ports collection makefile for:    blender
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.48
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/ \
		http://mirror.cs.umn.edu/blender.org/source/ \
		http://public.planetmirror.com/pub/blender/source/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D modeling/rendering/animation/gaming package

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		alut.1:${PORTSDIR}/audio/freealut\
		openal.0:${PORTSDIR}/audio/openal \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg \
		GLEW.1:${PORTSDIR}/graphics/glew

USE_XORG=	x11 xext xmu xi
USE_PYTHON=	2.5+
USE_SDL=	sdl
USE_GL=		gl glu
USE_GMAKE=	yes

SUB_FILES=	blender

PORTDOCS=	README bf-members.txt blender-scons.txt  python-dev-guide.txt \
		blender-cmake.txt blender-guardedalloc.txt \
		interface_API.txt blender-scons-dev.txt oldbugs.txt

LANG=		ar bg ca cs de el es fi fr hr hr_HR it ja ko nl pl pt_BR ro \
		ru sr sr@Latn sv uk zh_CN

LANG=		ar bg ca cs de el es fi fr hr hr_HR it ja ko nl pl pt_BR ro \
		ru sr sr@Latn sv uk zh_CN

OPTIONS=	OCFLAGS "Enable optimized CFLAGS" off \
		NLS	"Native language support" on

.include <bsd.port.pre.mk>

MAKE_ENV+=	NAN_CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/OpenEXR \
		-I${PYTHON_INCLUDEDIR}/"
MAKE_ENV+=	NAN_FREETYPE="${LOCALBASE}/"
MAKE_ENV+=	NAN_OPENEXR="${LOCALBASE}/"
MAKE_ENV+=	NAN_OPENAL="${LOCALBASE}/"
MAKE_ENV+=	NAN_PYTHON="${LOCALBASE}/"
MAKE_ENV+=	NAN_PYTHON_VERSION=${PYTHON_VER}
MAKE_ENV+=	NAN_FMOD="${LOCALBASE}/"
MAKE_ENV+=	NAN_JPEG="${LOCALBASE}/"
MAKE_ENV+=	NAN_PNG="${LOCALBASE}/"
MAKE_ENV+=	NAN_ZLIB="${LOCALBASE}/"
MAKE_ENV+=	NAN_ODE="${LOCALBASE}/"
MAKE_ENV+=	NAN_GLEW="${LOCALBASE}/"
CFLAGS+=	"-I${LOCALBASE}/include"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
MAKE_ENV+=	INTERNATIONAL="true"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

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
	@${REINPLACE_CMD} -e 's|2.5|${PYTHON_VER}|' \
		${WRKSRC}/source/nan_definitions.mk

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
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/freebsd-${OSREL}-${ARCH}/bin/blender ${PREFIX}/bin/blender-bin

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

.if !defined(WITH_NOPORTDOCS)
	@${CP} -p ${WRKSRC}/README ${WRKSRC}/doc/
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
