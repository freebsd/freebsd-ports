# New ports collection makefile for:	ruby-mecab
# Date created:		23 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${MECAB_PORTNAME}
PORTVERSION=	${MECAB_PORTVERSION}
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MeCab library module for Ruby

EXTRACT_DEPENDS=	${NONEXISTENT}:${MECAB_PORTDIR}:patch
LIB_DEPENDS=	mecab.0:${MECAB_PORTDIR}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_WITH_PTHREAD=	yes

INSTALL_TARGET=	site-install

.include "${.CURDIR}/../mecab/Makefile.common"

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${MECAB_WRKSRC_CMD}`/ruby ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/mecab
	${INSTALL_DATA} ${WRKSRC}/test.rb ${PREFIX}/share/examples/mecab/
.endif

.include <bsd.port.post.mk>
