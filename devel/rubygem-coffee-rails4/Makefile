# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	coffee-rails
PORTVERSION=	4.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Coffee Script adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-coffee-script>=2.2.0:devel/rubygem-coffee-script \
		rubygem-railties4>=4.0.0:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
