PORTNAME=	unordered-dense
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast & densely stored hashmap and hashset
WWW=		https://github.com/martinus/unordered_dense

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	martinus
GH_PROJECT=	${PORTNAME:S/-/_/}

PLIST_FILES=	include/ankerl/stl.h \
		include/ankerl/unordered_dense.h \
		lib/cmake/unordered_dense/unordered_denseConfig.cmake \
		lib/cmake/unordered_dense/unordered_denseConfigVersion.cmake \
		lib/cmake/unordered_dense/unordered_denseTargets.cmake

NO_ARCH=	yes

.include <bsd.port.mk>
