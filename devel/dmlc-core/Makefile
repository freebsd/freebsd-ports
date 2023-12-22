PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5-23
DISTVERSIONSUFFIX=	-ga355fbf
CATEGORIES=	devel # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning
WWW=		https://github.com/dmlc/dmlc-core

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DUSE_OPENMP:BOOL=OFF
.endif

.include <bsd.port.mk>
