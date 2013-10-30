# $FreeBSD$

PORTNAME=	cinch
PORTVERSION=	2.0.5
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	The IRC Bot Building Framework

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.8
IGNORE=	only works with Ruby 1.9
.endif
.include <bsd.port.post.mk>
