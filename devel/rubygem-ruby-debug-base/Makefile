# Ports collection makefile for:	rubygem-ruby-debug-base
# Date created:				27 July 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	ruby-debug-base
PORTVERSION=	0.10.2
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-debug

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Fast implementation of the standard Ruby debugger

RUN_DEPENDS=	rubygem-linecache>=0.30:${PORTSDIR}/devel/rubygem-linecache

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
