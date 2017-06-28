# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	coffee-rails
PORTVERSION=	4.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Coffee Script adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:devel/rubygem-coffee-script \
		rubygem-railties50>=5.0.0:www/rubygem-railties50

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
