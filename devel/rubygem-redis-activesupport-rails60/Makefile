# $FreeBSD$

PORTNAME=	redis-activesupport
PORTVERSION=	5.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis store for ActiveSupport::Cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport60>3<7:devel/rubygem-activesupport60 \
		rubygem-redis-store>=1.3.0<2:devel/rubygem-redis-store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
