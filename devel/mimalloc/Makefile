# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mimalloc
PORTVERSION=	1.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
USE_LDCONFIG=	yes

# shows broken links: 400: Invalid request
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
