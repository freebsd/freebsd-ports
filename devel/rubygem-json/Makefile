# New ports collection makefile for:	Ruby replacement for json
# Date created:		Jul 9, 2007
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	json
PORTVERSION=	1.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Parse JSON texts and generate them from ruby data structures

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.9
USE_RUBY_FEATURES=	iconv
.endif

.include <bsd.port.post.mk>
