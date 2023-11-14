PORTNAME=	cucumber-core
PORTVERSION=	12.0.0
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin26>=25<27:textproc/rubygem-cucumber-gherkin26 \
		rubygem-cucumber-messages22>=20<23:devel/rubygem-cucumber-messages22 \
		rubygem-cucumber-tag-expressions5>=5.0.4<6:devel/rubygem-cucumber-tag-expressions5

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
