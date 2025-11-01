PORTNAME=	osgearth
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	8
CATEGORIES=	graphics geography

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ terrain rendering toolkit for OpenSceneGraph
WWW=		http://osgearth.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		Fails to build, error: cannot assign to non-static data member 'length' with const-qualified type 'const SizeType'
EXPIRATION_DATE=2025-12-31

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgdal.so:graphics/gdal \
		libgeos_c.so:graphics/geos \
		libosg.so:graphics/osg \
		libprotobuf.so:devel/protobuf \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++17-lang gl pkgconfig sqlite
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron ocornut:imgui Esri:lerc Tencent:rapidjson
GH_PROJECT=	imgui:imgui lerc:lerc rapidjson:rapidjson
GH_TAGNAME=	cab7edd:imgui 19542a0:lerc f54b0e4:rapidjson
USE_GL=		gl
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING=""

LDFLAGS+=	-Wl,--as-needed

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		SPDLOG
OPTIONS_DEFAULT=	SPDLOG
SPDLOG_DESC=		Logging support via devel/spdlog

SPDLOG_LIB_DEPENDS=	libspdlog.so:devel/spdlog

post-extract:
.for sm in imgui lerc rapidjson
	@${MV} ${WRKSRC_${sm}}/* ${WRKSRC}/src/third_party/${sm}/
.endfor

post-patch-SPDLOG-off:
	@${REINPLACE_CMD} '/find_package(spdlog)/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.options.mk>

.if ${ARCH} != amd64
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-no-ia32-sse
.endif

.include <bsd.port.mk>
