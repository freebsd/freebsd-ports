# $FreeBSD$

PORTNAME=	redis-activesupport
PORTVERSION=	5.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport50>=3<7:devel/rubygem-activesupport50 \
		rubygem-redis-store>=1.3<2:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
