# New ports collection makefile for:	p5-MeCab
# Date created:		23 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MeCab
PORTVERSION=	${MECAB_PORTVERSION}
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MeCab library module for Perl5

EXTRACT_DEPENDS=	${NONEXISTENT}:${MECAB_PORTDIR}:patch
LIB_DEPENDS=	mecab.0:${MECAB_PORTDIR}

PERL_CONFIGURE=	yes

.include "${.CURDIR}/../mecab/Makefile.common"

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `${MECAB_WRKSRC_CMD}`/perl ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/mecab
	${INSTALL_DATA} ${WRKSRC}/test.pl ${PREFIX}/share/examples/mecab/
.endif

.include <bsd.port.post.mk>
