# Ports collection makefile for:	rubygem-rparsec
# Date created:				24 September 2008
# Whom:					stas
#
# $FreeBSD$

PORTNAME=	rparsec
PORTVERSION=	1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recursive descent parser combinator framework for Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
