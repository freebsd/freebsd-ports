# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	apipie-bindings
PORTVERSION=	0.0.15
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for API calls that are documented with Apipie

LICENSE=	MIT

RUN_DEPENDS=	rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-rest-client>=1.6.7:${PORTSDIR}/www/rubygem-rest-client

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
