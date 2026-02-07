PORTNAME=	fastani
DISTVERSIONPREFIX=	v
DISTVERSION=	1.34
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Whole-Genome Similarity (ANI) Estimation
WWW=		https://github.com/ParBLiSS/FastANI

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		cmake:testing

.if !exists(/usr/include/omp.h)
BROKEN=		build w/out OpenMP support still attempts to use omp.h, see https://github.com/ParBLiSS/FastANI/issues/139
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	ParBLiSS
GH_PROJECT=	FastANI
GH_TUPLE=	catchorg:Catch2:359542d:catch/ext/Catch2

CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING # 6 tests fail, see https://github.com/ParBLiSS/FastANI/issues/138

PLIST_FILES=	bin/fastANI

.include <bsd.port.mk>
