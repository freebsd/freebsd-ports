# $FreeBSD$

PORTNAME=	zfp
DISTVERSION=	0.5.4
CATEGORIES=	devel science
MASTER_SITES=	https://computation.llnl.gov/projects/floating-point-compression/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High throughput library for compressed floating-point arrays

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_LDCONFIG=	yes

LDFLAGS+=	-lm

.include <bsd.port.mk>
