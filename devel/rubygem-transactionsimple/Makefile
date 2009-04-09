# Ports collection makefile for:	gem-transaction-simple
# Date created:				09 nov 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	transactionsimple
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	trans-simple
DISTNAME=	transaction-simple-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple object transaction support

BUILD_DEPENDS=	rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
