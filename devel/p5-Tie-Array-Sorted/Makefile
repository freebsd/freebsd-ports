# New ports collection makefile for:	p5-Tie-Array-Sorted
# Date created:				27 July 2004
# Whom:	      				Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-Array-Sorted
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl array which is kept sorted

PERL_CONFIGURE=	yes

MAN3=		Tie::Array::Sorted.3 \
		Tie::Array::Sorted::Lazy.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"This port requires perl 5.6 or above."
.endif

.include <bsd.port.post.mk>
