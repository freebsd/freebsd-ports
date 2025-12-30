PORTNAME=	cucumber-core
PORTVERSION=	16.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=33<40:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=28<33:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=6<9:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
