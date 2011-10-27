# New ports collection makefile for:	rubygem-dm-transactions
# Date created:		2010-08-26
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	dm-transactions
PORTVERSION=	1.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Makes transaction support available for adapters that support them

RUN_DEPENDS=	rubygem-dm-core>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-core

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
