# $FreeBSD$

PORTNAME=	pcg-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.98.1-59
DISTVERSIONSUFFIX=	-g5b5cac8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PCG Random Number Generation, C++ Edition

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	imneme

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/pcg_extras.hpp \
		include/pcg_random.hpp \
		include/pcg_uint128.hpp

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CXXFLAGS=-I${WRKSRC}/include ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
