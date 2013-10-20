# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	ruby-debug-base
PORTVERSION=	0.10.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Fast implementation of the standard Ruby debugger

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-21

RUN_DEPENDS=	rubygem-linecache>=0.3:${PORTSDIR}/devel/rubygem-linecache

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
