PORTNAME=	libflatarray
PORTVERSION=	0.3.0
PORTREVISION=	17
CATEGORIES=	devel science
MASTER_SITES=	http://www.libgeodecomp.org/archive/

MAINTAINER=	kurt@kmk-computers.de
COMMENT=	Struct of arrays library with object oriented interface for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	test/estimate_optimum_short_vec_type_test.cpp:71:22: error: redefinition of 'expected_arity_for_double'

BUILD_DEPENDS=	boost-libs>=1.48:devel/boost-libs

USES=		cmake compiler:c++14-lang

CMAKE_ARGS=	-DWITH_CUDA:BOOL=FALSE

.include <bsd.port.mk>
