PORTNAME=	redis-actionpack
PORTVERSION=	5.5.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack
WWW=		https://redis-store.org/redis-actionpack/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=5:www/rubygem-actionpack-gitlab \
		rubygem-redis-rack-gitlab>=2.1.0<4:www/rubygem-redis-rack-gitlab \
		rubygem-redis-store-gitlab>=1.1.0<2:devel/rubygem-redis-store-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
