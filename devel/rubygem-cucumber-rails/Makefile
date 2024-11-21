PORTNAME=	cucumber-rails
PORTVERSION=	3.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber generator and runtime for Rails
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-capybara>=3.11<4:devel/rubygem-capybara \
		rubygem-cucumber>=5<10:devel/rubygem-cucumber \
		rubygem-railties72>=5.2<8:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
