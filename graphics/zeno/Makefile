PORTNAME=	zeno
DISTVERSION=	2023.11.16
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	ZEn NOde system - a simulation & rendering engine in nodes
WWW=		https://zenustech.com/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	openmpi>0:net/openmpi \
		cgal>=5.0.2:math/cgal \
		onetbb>0:devel/onetbb \
		openvdb>0:misc/openvdb

USES=		cmake compiler:c++17-lang eigen:3 localbase:ldflags qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	zenustech
USE_LDCONFIG=	yes
USE_QT=		core gui network opengl svg widgets buildtools:build qmake:build

CMAKE_ON=	ZENO_BUILD_EDITOR ZENO_BUILD_SHARED ZENO_IPC_USE_TCP \
		ZENO_MULTIPROCESS ZENO_NO_WARNING ZENO_USE_CCACHE
CMAKE_OFF=	ZENO_BUILD_DESIGNER ZENO_BUILD_PLAYER ZENO_INSTALL_TARGET \
		ZENO_MARCH_NATIVE ZENO_OPTIX_PROC ZENO_USE_FAST_MATH \
		ZENO_WIN32_RC ZENO_WITH_CUDA
# ZENO_BUILD_DESIGNER - bug https://github.com/zenustech/zeno/issues/1907

# fix on 13.3: "ld: error: undefined reference due to --no-allow-shlib-undefined:
LDFLAGS+=	-Wl,--allow-shlib-undefined -lomp

PLIST_FILES=	bin/autotest \
		bin/zenoedit \
		lib/libzeno.so
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/autotest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/zenoedit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKDIR}/.build/bin/libzeno.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
