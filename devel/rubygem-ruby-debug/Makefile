# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	ruby-debug
PORTVERSION=	0.10.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	A generic command line interface for ruby-debug

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-21

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.10.4.0:${PORTSDIR}/devel/rubygem-ruby-debug-base \
		rubygem-columnize>=0.1:${PORTSDIR}/devel/rubygem-columnize

PORTSCOUT=	skipv:0.10.5

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug

NO_STAGE=	yes
.include <bsd.port.mk>
