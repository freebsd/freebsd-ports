# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	3.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-rack>=1.0:${PORTSDIR}/www/rubygem-rack

CONFLICTS_INSTALL=	rubygem-sprockets211-[0-9]* rubygem-sprockets-[0-9]*

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sprockets

.include <bsd.port.mk>
