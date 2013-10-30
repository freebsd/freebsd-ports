# $FreeBSD$

PORTNAME=	redis-actionpack
PORTVERSION=	4.0.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack

RUN_DEPENDS=	rubygem-actionpack4>=4:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-redis-store>=1.1.0:${PORTSDIR}/devel/rubygem-redis-store \
		rubygem-redis-rack>=1.5.0:${PORTSDIR}/www/rubygem-redis-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
