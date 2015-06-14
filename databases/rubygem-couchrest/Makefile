# Created by: Mike Carlson (carlson39@llnl.gov)
# $FreeBSD$

PORTNAME=	couchrest
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a simple interface on top of CouchDBs RESTful HTTP API

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-mime-types>=1.15:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rest-client>=1.6.1:${PORTSDIR}/www/rubygem-rest-client

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
