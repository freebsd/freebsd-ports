# New ports collection makefile for:	rubygem-cinch
# Date created:		October 30, 2011
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	cinch
PORTVERSION=	1.1.3
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	The IRC Bot Building Framework

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.8
IGNORE=	Only works with 1.9
.endif
.include <bsd.port.post.mk>
