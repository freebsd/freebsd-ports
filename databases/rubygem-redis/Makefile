# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	4.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client library for Redis, the key value storage server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/build

.include <bsd.port.mk>
