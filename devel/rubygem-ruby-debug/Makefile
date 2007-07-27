# Ports collection makefile for:	rubygem-ruby-debug
# Date created:				27 July 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	ruby-debug
PORTVERSION=	0.9.3
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	A generic command line interface for ruby-debug

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.9.3:${PORTSDIR}/devel/rubygem-ruby-debug-base

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
