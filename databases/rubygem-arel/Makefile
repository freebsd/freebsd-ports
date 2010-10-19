# Ports collection makefile for:	rubygem-arel
# Date created:				1 September 2010
# Whom:						Philip M. Gollucci <pgollucci@p6m7g8.com>	
#
# $FreeBSD$

# XXX: rails,active* require ~> 1.0.1 of arel, *sigh*

PORTNAME=	arel
PORTVERSION=	1.0.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Relational Algebra for Ruby.

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport

USE_RUBY=   yes
USE_RUBYGEMS=   yes
RUBYGEM_AUTOPLIST=  yes

.include <bsd.port.mk>
