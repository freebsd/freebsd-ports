PORTNAME=	cucumber-core
PORTVERSION=	16.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=36<40:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=31<33:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions8>=6<9:devel/rubygem-cucumber-tag-expressions8

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
