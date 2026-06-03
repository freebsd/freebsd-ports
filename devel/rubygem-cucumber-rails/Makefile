PORTNAME=	cucumber-rails
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber generator and runtime for Rails
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-capybara>=3.25<4:devel/rubygem-capybara \
		rubygem-cucumber10>=7<11:devel/rubygem-cucumber10 \
		rubygem-railties81>=6.1<9:www/rubygem-railties81

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
