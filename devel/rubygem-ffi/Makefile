# New ports collection makefile for:   rubygem-ffi
# Date created:    28 April 2010
# Whom:	Christoph Kick
#
# $FreeBSD$
#

PORTNAME=	ffi
PORTVERSION=	1.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extension for dynamic libraries & binding functions

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>
RUBY_VER=	19
BROKEN=	rake not found
.include <bsd.port.post.mk>
