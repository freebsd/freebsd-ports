# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mimalloc
PORTVERSION=	1.0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
#MASTER_SITES=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	microsoft

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmimalloc.so

.include <bsd.port.mk>
