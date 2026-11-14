PORTNAME=	cucumber-core
PORTVERSION=	20.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://cucumber.io/ \
		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin42>=36<43:textproc/rubygem-cucumber-gherkin42 \
		rubygem-cucumber-messages34>=31<35:devel/rubygem-cucumber-messages34 \
		rubygem-cucumber-tag-expressions>=6<12:devel/rubygem-cucumber-tag-expressions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
