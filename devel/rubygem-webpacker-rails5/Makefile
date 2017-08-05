# $FreeBSD$

PORTNAME=	webpacker
PORTVERSION=	2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport5>0:devel/rubygem-activesupport5 \
		rubygem-multi_json>=1.2:devel/rubygem-multi_json \
		rubygem-railties5>0:www/rubygem-railties5 \
		yarn>0:www/yarn

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
