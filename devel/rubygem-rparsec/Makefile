# Created by: stas
# $FreeBSD$

PORTNAME=	rparsec
PORTVERSION=	1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Recursive descent parser combinator framework for Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
