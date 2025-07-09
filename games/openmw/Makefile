PORTNAME=	openmw
DISTVERSIONPREFIX=	openmw-
DISTVERSION=	0.49.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Unofficial open source engine reimplementation of the game Morrowind
WWW=		https://openmw.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so.60:multimedia/ffmpeg \
		libboost_thread.so:devel/boost-libs \
		libMyGUIEngine.so:x11-toolkits/mygui \
		libBulletCollision.so:devel/bullet@double \
		libosg.so:graphics/osg \
		libRecast.so:graphics/recastnavigation \
		libunshield.so:archivers/unshield \
		liblz4.so:archivers/liblz4 \
		libicui18n.so:devel/icu \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++20-lang desktop-file-utils gl luajit openal \
		pkgconfig qt:5 sdl sqlite xorg
USE_GITHUB=	yes
GH_ACCOUNT=	OpenMW
USE_GL=		gl
USE_QT=		core gui linguisttools network opengl printsupport svg widgets \
		buildtools:build qmake:build
#USE_QT=		base imageformats multimedia svg tools:build
USE_SDL=	sdl2
USE_CXXSTD=	c++20
#USE_GCC=	yes

CMAKE_ARGS=	-DDESIRED_QT_VERSION=5 \
		-DOPENMW_USE_SYSTEM_BULLET=ON \
		-DOPENMW_USE_SYSTEM_RECASTNAVIGATION=ON \
		-DGLOBAL_DATA_PATH="${PREFIX}/share" \
		-DMORROWIND_DATA_FILES="${DATADIR}/data" \
		-DOPENMW_RESOURCE_FILES="${DATADIR}/resources"

# passed from openal to prevent linker errors
LDFLAGS+=	-Wl,--as-needed
LDFLAGS_i386=	-Wl,-z,notext

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	BUILD_DOCS
DOCS_BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}
DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		python:build

PORTDOCS=	*

.include <bsd.port.pre.mk>

# The following is actually meant for lld 15.0 and later, but the ports
# framework does not support LINKER_TYPE and LINKER_VERSION yet.
.if ${COMPILER_TYPE} == "clang"
# Turn off checking of dynamic relocations, to avoid lld diagnostics about
# possibly incorrect addend values.
LDFLAGS_i386+=	-Wl,--no-check-dynamic-relocations
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.post.mk>
