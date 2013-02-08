# New ports collection makefile for:	rubygem-racc
# Date created:		2012-02-07
# Whom:			Shin-ya MURAKAMI <murashin@gfd-dennou.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.4.9
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	An LALR(1) parser generator for Ruby

LICENSE=	LGPL21

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/racc bin/racc2y bin/y2racc

CONFLICTS=	ruby1[89]-racc-1\.4\*

.include <bsd.port.mk>
