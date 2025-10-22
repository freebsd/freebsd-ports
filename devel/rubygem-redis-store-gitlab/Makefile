PORTNAME=	redis-store
PORTVERSION=	1.11.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Namespaced Redis stores for Ruby web frameworks
WWW=		https://redis-store.org/redis-store/ \
		https://github.com/redis-store/redis-store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-redis-gitlab>=4<6:databases/rubygem-redis-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
