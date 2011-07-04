# Ports collection makefile for:	rubygem-kirbybase
# Date created:				07 Jan 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$

PORTNAME=	kirbybase
PORTVERSION=	2.6
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
DISTNAME=	KirbyBase-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Small and Plain-text DBMS Written in Ruby

DEPRECATED=	Doesn't work with Ruby 1.9
EXPIRATION_DATE=	2011-08-03

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/kbserver.rb

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
