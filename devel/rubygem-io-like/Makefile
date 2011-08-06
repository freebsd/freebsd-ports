# New ports collection makefile for:	rubygem-io-like
# Date created:		2011-08-06
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	io-like
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	The interface of IO objects to classes providing a few simple methods

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif

.include <bsd.port.post.mk>
