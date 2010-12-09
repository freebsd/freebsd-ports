# Ports collection makefile for:	rubygem-linecache
# Date created:				17 Oct 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$

PORTNAME=	linecache
PORTVERSION=	0.43
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Caches(Ruby source) Files as Might Be Used in a Debugger

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>
