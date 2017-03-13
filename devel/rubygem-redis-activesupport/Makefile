# $FreeBSD$

PORTNAME=	redis-activesupport
PORTVERSION=	5.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport4>=4:devel/rubygem-activesupport4 \
		rubygem-redis-rack>=1:www/rubygem-redis-rack \
		rubygem-redis-store>=1.1.0:devel/rubygem-redis-store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
