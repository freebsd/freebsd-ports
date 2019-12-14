# $FreeBSD$

PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-123
DISTVERSIONSUFFIX=	-gb3a4c71
CATEGORIES=	devel # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.pre.mk>

# XXX Drop after FreeBSD 12.0 EOL
.if ${CHOSEN_COMPILER_TYPE} == clang && !exists(/usr/include/omp.h)
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

.include <bsd.port.post.mk>
