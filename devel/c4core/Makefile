PORTNAME=	c4core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.8
CATEGORIES=	devel

PATCH_SITES=	https://github.com/biojppm/c4core/commit/
PATCHFILES=	ed9bf87ab152509fcd5c54bdc40ebed9a2b4ede7.patch:-p1

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Library of low-level C++ utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	git:devel/git@lite

USES=		compiler:c++11-lib cmake:noninja

USE_GITHUB=	yes
GH_ACCOUNT=	biojppm
GH_PROJECT=	cmake:cmake debugbreak:debugbreak fast_float:fast_float
GH_SUBDIR=	cmake:cmake src/c4/ext/debugbreak:debugbreak src/c4/ext/fast_float:fast_float
GH_TAGNAME=	9416f29:cmake 5dcbe41:debugbreak 052975d:fast_float

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
