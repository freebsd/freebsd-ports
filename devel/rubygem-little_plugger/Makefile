# Ports collection makefile for:	gem-little_plugger
# Date created:				06 Nov 2009
# Whom:					Ryan Steinmetz (<rpsfa@rit.edu>)
#
# $FreeBSD$

PORTNAME=	little_plugger
PORTVERSION=	1.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	little-plugger-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Mechanism to parse ruby little-plugger files

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes

RUN_DEPENDS=	rubygem-rspec>=0:${PORTSDIR}/devel/rubygem-rspec

.include <bsd.port.mk>
