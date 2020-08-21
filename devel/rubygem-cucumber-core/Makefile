# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-core
PORTVERSION=	8.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=15.0.2<16:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=13.0.1<14:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=2.0.4<3:devel/rubygem-cucumber-tag-expressions

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
