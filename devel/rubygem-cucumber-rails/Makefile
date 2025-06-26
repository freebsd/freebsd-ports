PORTNAME=	cucumber-rails
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber generator and runtime for Rails
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-capybara>=3.11<4:devel/rubygem-capybara \
		rubygem-cucumber9>=5<10:devel/rubygem-cucumber9 \
		rubygem-railties72>=5.2<9:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
