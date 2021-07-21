# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-core
PORTVERSION=	10.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=20.0.1<21:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=17.0.1<18:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=3.0.1<4:devel/rubygem-cucumber-tag-expressions

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
