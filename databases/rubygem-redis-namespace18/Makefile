PORTNAME=	redis-namespace
PORTVERSION=	1.8.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	18

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client class for Redis with namespace support
WWW=		https://github.com/resque/redis-namespace

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis>=3.0.4:databases/rubygem-redis

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.8\.

.include <bsd.port.mk>
