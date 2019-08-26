# $FreeBSD$

PORTNAME=	redis-activesupport
PORTVERSION=	5.0.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport52>0:devel/rubygem-activesupport52 \
		rubygem-redis-store>=1.3.0:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
