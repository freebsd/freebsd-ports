# New ports collection makefile for:	p5-String-Similarity
# Date created:				22 June 2001
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Similarity
PORTVERSION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Perl module that calculates the similarity of two strings

PERL_CONFIGURE=	yes

MAN3=		String::Similarity.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
