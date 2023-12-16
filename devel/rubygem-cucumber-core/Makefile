PORTNAME=	cucumber-core
PORTVERSION=	13.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=27<28:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages22>=20<23:devel/rubygem-cucumber-messages22 \
		rubygem-cucumber-tag-expressions>=5<7:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
