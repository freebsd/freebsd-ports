PORTNAME=	scnlib
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	scanf for modern C++
WWW=		https://www.scnlib.dev/

LICENSE=	APACHE20

BUILD_DEPENDS=	${NONEXISTENT}:devel/googletest:patch	\
		${NONEXISTENT}:math/fast_float:patch	\
		${NONEXISTENT}:devel/benchmark:patch

USES=		cmake compiler:c++20-lang python
USE_CXXSTD=	c++20

USE_GITHUB=	yes
GH_ACCOUNT=	eliaskosunen

BINARY_ALIAS=	git=false
CMAKE_ON=	BUILD_SHARED_LIBS
USE_LDCONFIG=	yes

GB_WRKSRC=	${MAKE} -C ${.CURDIR}/../benchmark -V WRKSRC
GT_WRKSRC=	${MAKE} -C ${.CURDIR}/../googletest -V WRKSRC
FF_WRKSRC=	${MAKE} -C ${.CURDIR}/../../math/fast_float -V WRKSRC

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/_deps/googletest-src	\
		${CONFIGURE_WRKSRC}/_deps/google-benchmark-src	\
		${CONFIGURE_WRKSRC}/_deps/fast_float-src
	${CP} -Rp $$(${GB_WRKSRC})/ ${CONFIGURE_WRKSRC}/_deps/google-benchmark-src
	${CP} -Rp $$(${GT_WRKSRC})/ ${CONFIGURE_WRKSRC}/_deps/googletest-src
	${CP} -Rp $$(${FF_WRKSRC})/ ${CONFIGURE_WRKSRC}/_deps/fast_float-src

.include <bsd.port.mk>
