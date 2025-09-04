PORTNAME=	c4core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.6
CATEGORIES=	devel

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Library of low-level C++ utilities
WWW=		https://github.com/biojppm/c4core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	git:devel/git@lite

USES=		compiler:c++11-lib cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	biojppm
GH_PROJECT=	cmake:cmake debugbreak:debugbreak fast_float:fast_float
GH_SUBDIR=	cmake:cmake src/c4/ext/debugbreak:debugbreak src/c4/ext/fast_float:fast_float
GH_TAGNAME=	e87e11f:cmake 328e4ab:debugbreak d28a332:fast_float

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
