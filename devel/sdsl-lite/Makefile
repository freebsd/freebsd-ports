PORTNAME=	sdsl-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1-vgteam-20
DISTVERSIONSUFFIX=	-g8abd7c9
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Succinct Data Structure Library 2.0
WWW=		https://github.com/simongog/sdsl-lite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	compilation fails: error: static assertion failed due to requirement 'sizeof(unsigned int) % sizeof(unsigned long long) == 0': The size of a serializable type must be a multiple of 8 bytes

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	simongog
GH_TUPLE=	simongog:libdivsufsort:0f24acd:libdivsufsort/external/libdivsufsort \
		google:googletest:71815bb:googletest/external/googletest

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	WITH_GOOGLETEST

CONFLICTS_INSTALL=	libdivsufsort

PORTSCOUT=	limit:^[v1-9].*$$ # prevent tags like c++11v1

post-install: # remove bundled gtest, see https://github.com/simongog/sdsl-lite/issues/458
	${RM} -r \
		${STAGEDIR}${PREFIX}/include/gtest \
		${STAGEDIR}${PREFIX}/lib/libgtest*

# * uses bundled (too old) divsufsort not compatible with math/libdivsufsort, see https://github.com/simongog/sdsl-lite/issues/457
# * unclear how to run tests, see https://github.com/simongog/sdsl-lite/issues/459

.include <bsd.port.mk>
