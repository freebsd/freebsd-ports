# ex:ts=8
# Ports collection makefile for:	rubygem-mash
# Date created:			May 1, 2009
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mash
PORTVERSION=	0.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	mash-hash

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Mocking Hash library for Ruby

BUILD_DEPENDS=	rubygem-hoe>=1.5.1:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
