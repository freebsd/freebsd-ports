# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	apipie-bindings
PORTVERSION=	0.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kvedulv@kvedulv.de
COMMENT=	Ruby bindings for API calls that are documented with Apipie

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-awesome_print>=1.1.0:${PORTSDIR}/devel/rubygem-awesome_print \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-mime-types=1.25.1:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-rest-client>=1.6.7:${PORTSDIR}/www/rubygem-rest-client

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
