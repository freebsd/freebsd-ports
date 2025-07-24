PORTNAME=	redis
PORTVERSION=	5.4.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client library for Redis, the key value storage server
WWW=		https://github.com/redis/redis-rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis-client>=0.22.0:databases/rubygem-redis-client

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/build

.include <bsd.port.mk>
