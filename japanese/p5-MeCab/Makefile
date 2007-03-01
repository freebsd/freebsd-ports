# New ports collection makefile for:	p5-MeCab
# Date created:		23 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	MeCab
PORTVERSION=	0.94
CATEGORIES=	japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=     ${PORTNAME:L}
DISTNAME=		${PORTNAME:L}-perl-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	MeCab library module for Perl5

LIB_DEPENDS=	mecab.1:${PORTSDIR}/japanese/mecab

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.x or later.  Install lang/perl5.8 and try again
.endif

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
