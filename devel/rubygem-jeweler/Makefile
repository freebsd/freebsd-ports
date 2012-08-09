# New ports collection makefile for:	rubygem-jeweler
# Date created:				23 February 2012
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	jeweler
PORTVERSION=	1.8.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Simple and opinionated helper for creating Rubygem projects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bundler>=1.0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-git>=1.2.5:${PORTSDIR}/devel/rubygem-git \
		rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake \
		rubygem-rdoc>=0:${PORTSDIR}/devel/rubygem-rdoc

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jeweler

.include <bsd.port.mk>
