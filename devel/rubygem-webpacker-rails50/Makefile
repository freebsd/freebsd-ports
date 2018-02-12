# $FreeBSD$

PORTNAME=	webpacker
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=4.2:devel/rubygem-activesupport50 \
		rubygem-rack-proxy>=0.6.1:www/rubygem-rack-proxy \
		rubygem-railties50>=4.2:www/rubygem-railties50 \
		yarn>=0:www/yarn

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/webpack ${STAGEDIR}${PREFIX}/bin/webpack-dev-server

.include <bsd.port.mk>
