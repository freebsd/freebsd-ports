PORTNAME=	ogre3d
DISTVERSIONPREFIX=	v
DISTVERSION=	14.4.0
CATEGORIES=	graphics devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Scene-oriented, flexible 3D engine written in C++
WWW=		https://www.ogre3d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzzip.so:devel/zziplib \
		libfreetype.so:print/freetype2
#		libimgui.so:x11-toolkits/imgui

CONFLICTS=	ogre3d19

USES=		cmake compiler:c++14-lang pkgconfig sdl xorg
USE_LDCONFIG=	yes
USE_SDL=	sdl2
USE_XORG=	x11 xaw xext xrandr xt

USE_GITHUB=	yes
GH_ACCOUNT=	OGRECave
GH_PROJECT=	ogre

PORTDOCS=	*

CMAKE_ARGS+=	OGRE_MEDIA_PATH="share/OGRE/Media"
CMAKE_ON=	OGRE_CONFIG_ENABLE_ZIP
CMAKE_OFF=	OGRE_INSTALL_SAMPLES_SOURCE \
		OGRE_BUILD_COMPONENT_OVERLAY_IMGUI

OPTIONS_DEFINE=		BULLET CSHARP DOCS FREEIMAGE JAVA OPENEXR OPENGL PROFILE \
			PYTHON
OPTIONS_DEFAULT=	FREEIMAGE OPENGL
OPTIONS_SUB=		yes

BULLET_DESC=		Build Bullet bindings
BULLET_CMAKE_BOOL=	OGRE_BUILD_COMPONENT_BULLET
BULLET_IMPLIES=		PYTHON
BULLET_LIB_DEPENDS=	libBulletCollision.so:devel/bullet@double

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	OGRE_INSTALL_DOCS

FREEIMAGE_DESC=		Build FreeImage codec
FREEIMAGE_CMAKE_BOOL=	OGRE_BUILD_PLUGIN_FREEIMAGE
FREEIMAGE_LIB_DEPENDS=	libfreeimage.so:graphics/freeimage

OPENEXR_USE=		XORG=ice
OPENEXR_CMAKE_BOOL=	OGRE_BUILD_PLUGIN_EXRCODEC
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath

OPENGL_CMAKE_BOOL=	OGRE_BUILD_RENDERSYSTEM_GL3PLUS \
			OGRE_BUILD_RENDERSYSTEM_GL \
			OGRE_BUILD_RENDERSYSTEM_GLES2
OPENGL_USES=		gl
OPENGL_USE=		XORG=sm,ice GL=gl,glu

PROFILE_CMAKE_BOOL=	OGRE_PROFILING

CSHARP_DESC=		Build Csharp bindings
CSHARP_CMAKE_BOOL=	OGRE_BUILD_COMPONENT_CSHARP
CSHARP_BUILD_DEPENDS=	swig:devel/swig

JAVA_CMAKE_BOOL=	OGRE_BUILD_COMPONENT_JAVA
JAVA_BUILD_DEPENDS=	swig:devel/swig
JAVA_VARS=		CMAKE_ARGS+=-DJAVA_HOME=${JAVA_HOME}
JAVA_USES=		java
JAVA_BROKEN=		error: incompatible types: SWIGTYPE_p_std__mapT_std__string_std__string_std__lessT_std__string_t_t__iterator cannot be converted to Iterator

PYTHON_CMAKE_BOOL=	OGRE_BUILD_COMPONENT_PYTHON
PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_USES=		python

CXXFLAGS+=		-DNDEBUG -I${LOCALBASE}/include -I${LOCALBASE}/include/Imath
PLIST_SUB+=		LIBVERSION=${PORTVERSION:R}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '\
		s,defined(__x86_64__),& || defined(__amd64__),' \
		${WRKSRC}/OgreMain/include/OgrePlatform.h
.if ${ARCH:Naarch64:Namd64}
	@${REINPLACE_CMD} -e '\
		/check_cxx_compiler_flag(-msse OGRE_GCC_HAS_SSE)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e 's/\(Python_ADDITIONAL_VERSIONS\) [0-9\.]*/\$1 ${PYTHON_VER}/' \
		${WRKSRC}/CMake/Dependencies.cmake
	@${REINPLACE_CMD} -e "s/dist-packages/site-packages/" \
		${WRKSRC}/Components/Python/CMakeLists.txt

post-build-DOCS-on:
	${MAKE_CMD} -C ${BUILD_WRKSRC} OgreDoc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README.md LICENSE AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-JAVA-on:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/OGRE/java
	${INSTALL_DATA} ${BUILD_WRKSRC}/java/Ogre-${DISTVERSION}.jar \
		${STAGEDIR}${LOCALBASE}/share/OGRE/java
	${INSTALL_LIB} ${BUILD_WRKSRC}/java/libs/libOgreJNI.so \
		${STAGEDIR}${LOCALBASE}/lib/OGRE

.include <bsd.port.mk>
