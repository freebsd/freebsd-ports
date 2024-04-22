PORTNAME=	redis-clustering
PORTVERSION=	5.0.8
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client that tries to match Redis Cluster API
WWW=		https://github.com/redis/redis-rb/tree/master/cluster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis50>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-redis50 \
		rubygem-redis-cluster-client>=0.7.0:databases/rubygem-redis-cluster-client

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.0\.

.include <bsd.port.mk>
