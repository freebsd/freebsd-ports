# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-core
PORTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library for the Cucumber BDD app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-tag_expressions1>=1.1.0<1.2:devel/rubygem-cucumber-tag_expressions1 \
		rubygem-gherkin>=5.0<6:textproc/rubygem-gherkin

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
# Remove backports
	@${REINPLACE_CMD} -e '/backports/d' ${WRKSRC}/cucumber-core.gemspec
	@${REINPLACE_CMD} -e "/require 'backports/d" ${WRKSRC}/lib/cucumber/core/event.rb

.include <bsd.port.mk>
