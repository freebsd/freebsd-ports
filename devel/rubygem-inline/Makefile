# New ports collection makefile for:	ruby-inline
# Date created:		2003-01-30
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

# XXX: note 3.8.5+ require EXACT (~> 4.3.0) versions of ZenTest 
# XXX: currently at 4.4.0. This will break 5 other ports directly

PORTNAME=	inline
PORTVERSION=	3.8.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

RUN_DEPENDS=	sow:${PORTSDIR}/devel/rubygem-hoe \
    		zentest:${PORTSDIR}/devel/rubygem-zentest

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
