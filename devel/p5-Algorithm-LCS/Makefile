# New ports collection makefile for:   Algorithm::LCS
# Date created:        26 July 2005
# Whom:                tiger@whitetigersd.com
#
# $FreeBSD$
#

PORTNAME=	Algorithm-LCS
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/J/JO/JOESUF
PKGNAMEPREFIX=	p5-

MAINTAINER=	tiger@whitetigersd.com
COMMENT=	Fast (XS) implementation of the Longest Common Subsequence Algorithm

PERL_CONFIGURE=	yes
MAN3=		Algorithm::LCS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>

