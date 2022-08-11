PORTNAME=	cucumber-core
PORTVERSION=	11.0.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin23>=23.0.1<24:textproc/rubygem-cucumber-gherkin23 \
		rubygem-cucumber-messages18>=18.0.0<19:devel/rubygem-cucumber-messages18 \
		rubygem-cucumber-tag-expressions>=4.1.0<5:devel/rubygem-cucumber-tag-expressions

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
