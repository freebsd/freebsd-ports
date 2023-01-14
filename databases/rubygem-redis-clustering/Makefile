PORTNAME=	redis-clustering
PORTVERSION=	5.0.5
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client that tries to match Redis Cluster API
WWW=		https://github.com/redis/redis-rb/tree/master/cluster

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-redis>=${PORTVERSION}:databases/rubygem-redis \
		rubygem-redis-cluster-client>=0.3.7:databases/rubygem-redis-cluster-client

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
