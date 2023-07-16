PORTNAME=	osgearth
PORTVERSION=	3.4
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	graphics geography

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	C++ terrain rendering toolkit for OpenSceneGraph
WWW=		http://osgearth.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libosg.so:graphics/osg \
		libprotoc.so:devel/protobuf \
		libwebp.so:graphics/webp

USES=		cmake gl pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron ocornut:imgui Esri:lerc Tencent:rapidjson
GH_PROJECT=	imgui:imgui lerc:lerc rapidjson:rapidjson
GH_TAGNAME=	9e8e5ac:imgui 19542a0:lerc f54b0e4:rapidjson

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_GL+=	gl glu

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING=""

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-extract:
.for sm in imgui lerc rapidjson
	@${MV} ${WRKSRC_${sm}}/* ${WRKSRC}/src/third_party/${sm}/
.endfor

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CXXFLAGS+=	-DNO_WARN_X86_INTRINSICS -maltivec -mvsx
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.if ${ARCH} == i386
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-i386
.endif

.include <bsd.port.mk>
