# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-core
PORTVERSION=	10.1.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin22>=22.0.0<23:textproc/rubygem-cucumber-gherkin22 \
		rubygem-cucumber-messages17>=17.1.1<18:devel/rubygem-cucumber-messages17 \
		rubygem-cucumber-tag-expressions>=4.1.0<5:devel/rubygem-cucumber-tag-expressions

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
