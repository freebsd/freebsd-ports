PORTNAME=	redis-actionpack
PORTVERSION=	5.3.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack
WWW=		https://redis-store.org/redis-actionpack/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=5<8:www/rubygem-actionpack70 \
		rubygem-redis-rack2>=2.1.0<3:www/rubygem-redis-rack2 \
		rubygem-redis-store>=1.1.0<2:devel/rubygem-redis-store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
