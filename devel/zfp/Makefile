PORTNAME=	zfp
DISTVERSION=	1.0.1
CATEGORIES=	devel science
MASTER_SITES=	https://github.com/LLNL/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High throughput library for compressed floating-point arrays
WWW=		https://computing.llnl.gov/projects/zfp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
CMAKE_OFF=	ZFP_WITH_OPENMP
.endif

LDFLAGS+=	-lm

.include <bsd.port.mk>
