# New ports collection makefile for:	ruby-inline
# Date created:		2003-01-30
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inline
PORTVERSION=	3.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
DISTNAME=	RubyInline-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Inline::C allows you to embed C/Ruby directly in ruby scripts

BUILD_DEPENDS=  sow:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=    ${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
