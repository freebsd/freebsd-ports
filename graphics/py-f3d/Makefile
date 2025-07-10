PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer
WWW=		https://f3d.app/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libf3d.so:graphics/f3d

USES=		cmake:testing compiler:c++17-lang localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	f3d-app

WRKSRC_SUBDIR=	python

CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER} \
		-DCMAKE_INSTALL_LIBDIR=lib
#CMAKE_OFF=	F3D_MULTI_CONFIG_GENERATOR # for https://github.com/f3d-app/f3d/issues/1149 but didn't help

CXXFLAGS+=	-I${LOCALBASE}/include/f3d

.include <bsd.port.mk>
