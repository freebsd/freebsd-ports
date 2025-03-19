PORTNAME=	cucumber-core
PORTVERSION=	15.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin30>=27<31:textproc/rubygem-cucumber-gherkin30 \
		rubygem-cucumber-messages>=26<29:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=5<7:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
