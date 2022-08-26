PORTNAME=	zfp
DISTVERSION=	1.0.0
CATEGORIES=	devel science
MASTER_SITES=	https://github.com/LLNL/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High throughput library for compressed floating-point arrays

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

LDFLAGS+=	-lm

.include <bsd.port.mk>
