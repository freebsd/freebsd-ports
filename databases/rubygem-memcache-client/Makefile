# Ports collection makefile for:	rubygem-memchache-client
# Date created:				26 January 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	memcache-client
PORTVERSION=	1.7.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	jw@innerewut.de
COMMENT=	Ruby bindings for MemCached

BUILD_DEPENDS=	rubygem-zentest>=3.4.2:${PORTSDIR}/devel/rubygem-zentest \
		rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
