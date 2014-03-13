# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	foreman_api
PORTVERSION=	0.1.11
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helps you to use Foreman API calls from your app

LICENSE=	MIT

RUN_DEPENDS=	rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-rest-client>=1.6.1:${PORTSDIR}/www/rubygem-rest-client

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
