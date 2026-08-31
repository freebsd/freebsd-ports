PORTNAME=	cucumber-core
PORTVERSION=	18.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin39>=36<40:textproc/rubygem-cucumber-gherkin39 \
		rubygem-cucumber-messages32>=31<33:devel/rubygem-cucumber-messages32 \
		rubygem-cucumber-tag-expressions9>=6<10:devel/rubygem-cucumber-tag-expressions9

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
