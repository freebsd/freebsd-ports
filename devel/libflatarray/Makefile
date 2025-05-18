PORTNAME=	libflatarray
PORTVERSION=	0.3.0
PORTREVISION=	19
CATEGORIES=	devel science
MASTER_SITES=	http://www.libgeodecomp.org/archive/

MAINTAINER=	kurt@kmk-computers.de
COMMENT=	Struct of arrays library with object oriented interface for C++
WWW=		http://www.libgeodecomp.org/libflatarray.html

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_armv7=	test/estimate_optimum_short_vec_type_test.cpp:71:22: error: redefinition of 'expected_arity_for_double'
BROKEN=		Unfetchable
DEPRECATED=	Last activity from upstream 5 years ago and last release in 2016
EXPIRATION_DATE=2025-06-30

BUILD_DEPENDS=	boost-libs>=1.48:devel/boost-libs

USES=		cmake compiler:c++14-lang

CMAKE_ARGS=	-DWITH_CUDA:BOOL=FALSE

.include <bsd.port.mk>
