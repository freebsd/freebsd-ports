PORTNAME=	cucumber-core
PORTVERSION=	15.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin34>=27<35:textproc/rubygem-cucumber-gherkin34 \
		rubygem-cucumber-messages29>=26<30:devel/rubygem-cucumber-messages29 \
		rubygem-cucumber-tag-expressions>=5<9:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
