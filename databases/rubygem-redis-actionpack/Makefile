# $FreeBSD$

PORTNAME=	redis-actionpack
PORTVERSION=	4.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4:www/rubygem-actionpack4 \
		rubygem-redis-store>=1.1.0:devel/rubygem-redis-store \
		rubygem-redis-rack>=1.5.0:www/rubygem-redis-rack

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
