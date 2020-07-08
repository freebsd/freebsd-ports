# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-core
PORTVERSION=	7.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-gherkin>=14.0.1<15:textproc/rubygem-cucumber-gherkin \
		rubygem-cucumber-messages>=12.2.0<13:devel/rubygem-cucumber-messages \
		rubygem-cucumber-tag-expressions>=2.0.4<3:devel/rubygem-cucumber-tag-expressions

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
