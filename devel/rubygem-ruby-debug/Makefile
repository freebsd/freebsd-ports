# Ports collection makefile for:	rubygem-ruby-debug
# Date created:				27 July 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	ruby-debug
PORTVERSION=	0.10.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	A generic command line interface for ruby-debug

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.10.0:${PORTSDIR}/devel/rubygem-ruby-debug-base \
		rubygem-columnize>=0.2:${PORTSDIR}/devel/rubygem-columnize

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug

.include <bsd.port.mk>
