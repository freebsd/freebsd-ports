PORTNAME=	cucumber-core
PORTVERSION=	15.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=27<40:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=26<33:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=5<9:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^15\.

.include <bsd.port.mk>
