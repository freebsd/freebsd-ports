PORTNAME=	redis-clustering
PORTVERSION=	5.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client that tries to match Redis Cluster API
WWW=		https://github.com/redis/redis-rb/tree/master/cluster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis52>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-redis52 \
		rubygem-redis-cluster-client>=0.7.11:databases/rubygem-redis-cluster-client

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
