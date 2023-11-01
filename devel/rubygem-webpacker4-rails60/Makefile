PORTNAME=	webpacker
PORTVERSION=	4.3.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4-rails60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails
WWW=		https://github.com/rails/webpacker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=4.2:devel/rubygem-activesupport60 \
		rubygem-rack-proxy>=0.6.1:www/rubygem-rack-proxy \
		rubygem-railties60>=4.2:www/rubygem-railties60 \
		yarn${NODEJS_SUFFIX}>=0:www/yarn${NODEJS_SUFFIX}

USES=		gem nodejs:env

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.mk>
