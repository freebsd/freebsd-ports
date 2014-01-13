# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	opencolorio
PORTVERSION=	1.0.8
PORTREVISION?=	2
CATEGORIES=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	Complete color management solution

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenColorIO
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8883824

OPTIONS_DEFINE=	DOCS

LDFLAGS+=	-L${LOCALBASE}/lib
PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX}
USES=		cmake:outsource pkgconfig
CMAKE_ARGS=	-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_NUKE:BOOL=OFF \
		-DOCIO_BUILD_STATIC:BOOL=OFF \
		-DUSE_EXTERNAL_TINYXML:BOOL=ON \
		-DUSE_EXTERNAL_YAML:BOOL=ON

.if ${MACHINE_CPU:Msse2}
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=ON
.else
CMAKE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
.endif

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libtinyxml.so:${PORTSDIR}/textproc/tinyxml \
		libyaml-cpp.so:${PORTSDIR}/devel/yaml-cpp
USE_PYTHON=	yes
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF \
		-DOCIO_BUILD_SHARED:BOOL=ON \
		-DOCIO_BUILD_PYGLUE:BOOL=ON \
		-DPYTHON:FILEPATH=${PYTHON_CMD}
.else
LIB_DEPENDS=	libOpenImageIO.so:${PORTSDIR}/graphics/openimageio \
		libOpenColorIO.so:${PORTSDIR}/graphics/opencolorio
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=ON \
		-DOCIO_BUILD_SHARED:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=ON
.else
CMAKE_ARGS+=	-DOCIO_BUILD_DOCS:BOOL=OFF
.endif

.include <bsd.port.mk>
