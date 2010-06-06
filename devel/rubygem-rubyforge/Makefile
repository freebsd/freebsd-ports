# Ports collection makefile for:	rubygem-rubyforge
# Date created:				3 December 2006
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$
#

PORTNAME=	rubyforge
PORTVERSION=	2.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	codeforpeople

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simplistic script which automates rubyforge operations

RUN_DEPENDS=	rubygem-json_pure>=1.1.7:${PORTSDIR}/devel/rubygem-json_pure

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rubyforge

.include <bsd.port.mk>
