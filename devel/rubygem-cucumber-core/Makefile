PORTNAME=	cucumber-core
PORTVERSION=	11.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app
WWW=		https://github.com/cucumber/cucumber-ruby-core

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=24<27:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=19<22.1:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions4>=4.1.0<5:devel/rubygem-cucumber-tag-expressions4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
