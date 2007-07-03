# Ports collection makefile for:	gem-transaction-simple
# Date created:				09 nov 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	transactionsimple
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	trans-simple
DISTNAME=	transaction-simple-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Simple object transaction support

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/hoe-1.2.1.gemspec:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
