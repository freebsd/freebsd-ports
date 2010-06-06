# New ports collection makefile for:	rubygem-ptreloaded
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ptreloaded
PORTVERSION=	0.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	ParseTreeReloaded-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A reimplementation of ParseTree using RubyInlineAcceleration

RUN_DEPENDS=	rubygem-rubyinlineaccel>=0.0.1:${PORTSDIR}/devel/rubygem-rubyinlineaccel

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
