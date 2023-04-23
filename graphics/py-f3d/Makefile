PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer
WWW=		https://f3d-app.github.io/f3d/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libf3d.so:graphics/f3d

USES=		cmake:testing compiler:c++17-lang localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	f3d-app

WRKSRC_SUBDIR=	python

CXXFLAGS+=	-I${LOCALBASE}/include/f3d

.include <bsd.port.mk>
