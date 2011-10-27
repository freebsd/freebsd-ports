# New ports collection makefile for:	devel/json_pure
# Date created:		Oct 7, 2008
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	json_pure
PORTVERSION=	1.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Parse JSON texts and generate them from ruby data structures in Ruby

RUN_DEPENDS=	rubygem-spruz>=0.1.0:${PORTSDIR}/devel/rubygem-spruz

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.9
USE_RUBY_FEATURES=	iconv
.endif

.include <bsd.port.post.mk>
