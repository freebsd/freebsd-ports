# $FreeBSD$

PORTNAME=	redis-actionpack
PORTVERSION=	5.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack50>0:www/rubygem-actionpack50 \
		rubygem-redis-rack>=1:www/rubygem-redis-rack \
		rubygem-redis-store>=1.1.0:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
