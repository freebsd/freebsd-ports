# New ports collection makefile for:	rubygem-bugspots
# Date created:		2012-01-11
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugspots
PORTVERSION=	0.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Bugspots - Bug Prediction Heuristic

RUN_DEPENDS=	rubygem-grit>=0:${PORTSDIR}/devel/rubygem-grit \
		rubygem-rainbow>=0:${PORTSDIR}/devel/rubygem-rainbow

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bugspots bin/git-bugspots

.include <bsd.port.mk>
