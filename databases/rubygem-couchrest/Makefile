# Ports collection makefile for:	rubygem-couchrest
# Date created:				20 June 2011
# Whom:						Mike Carlson (carlson39@llnl.gov)
#
# $FreeBSD$

PORTNAME=	couchrest
PORTVERSION=	1.1.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a simple interface on top of CouchDBs RESTful HTTP API

RUN_DEPENDS=	rubygem-multi_json>=1.0.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-mime-types>=1.15:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-rest-client>=1.6.1:${PORTSDIR}/www/rubygem-rest-client

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
