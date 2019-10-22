# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mimalloc
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
#MASTER_SITES=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11

USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	microsoft

# shows broken links: 400: Invalid request
PORTSCOUT=	ignore

.include <bsd.port.mk>
