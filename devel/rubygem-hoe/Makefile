# Ports collection makefile for:	rubygem-hoe
# Date created:				5 December 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	hoe
PORTVERSION=	2.8.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A simple rake/rubygems helper for project Rakefiles

RUN_DEPENDS=	rubygem-rubyforge>=2.0.4:${PORTSDIR}/devel/rubygem-rubyforge

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/sow

.include <bsd.port.mk>
