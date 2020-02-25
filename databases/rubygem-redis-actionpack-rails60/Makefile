# $FreeBSD$

PORTNAME=	redis-actionpack
PORTVERSION=	5.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>5<7:www/rubygem-actionpack60 \
		rubygem-redis-rack>=2.1.0<3:www/rubygem-redis-rack \
		rubygem-redis-store>=1.1.0<2:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
