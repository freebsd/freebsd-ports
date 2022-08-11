PORTNAME=	ledger
PORTVERSION=	3.2.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_FreeBSD_12_powerpc64=	fails to link on powerpc64 elfv1: ibledger.so.3: undefined reference to boost::match_results

BUILD_DEPENDS=	${LOCALBASE}/include/utf8cpp/utf8.h:devel/utf8cpp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib cpe libedit
CPE_VENDOR=	${PORTNAME}-cli
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \
		-DCMAKE_INCLUDE_PATH=${LOCALBASE}/include

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
