PORTNAME=	cucumber-core
PORTVERSION=	14.0.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin29>=27<30:textproc/rubygem-cucumber-gherkin29 \
		rubygem-cucumber-messages26>=22<27:devel/rubygem-cucumber-messages26 \
		rubygem-cucumber-tag-expressions>=5<7:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
