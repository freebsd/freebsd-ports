# New ports collection makefile for:	ruby-inline
# Date created:		2003-01-30
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inline
PORTVERSION=	3.8.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

BUILD_DEPENDS=	sow:${PORTSDIR}/devel/rubygem-hoe \
    		zentest:${PORTSDIR}/devel/rubygem-zentest
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
