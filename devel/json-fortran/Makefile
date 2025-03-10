PORTNAME=	json-fortran
DISTVERSION=	9.0.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern Fortran JSON API
WWW=		https://github.com/jacobwilliams/json-fortran/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: Cannot find an intrinsic module named 'ieee_arithmetic'

USES=		cmake:testing fortran

USE_GITHUB=	yes
GH_ACCOUNT=	jacobwilliams

CMAKE_ON=	USE_GNU_INSTALL_CONVENTION
CMAKE_OFF=	JSONFORTRAN_ENABLE_TESTS
CMAKE_TESTING_ON=	JSONFORTRAN_ENABLE_TESTS ENABLE_TESTS
CMAKE_TESTING_TARGET=	check

.include <bsd.port.mk>
