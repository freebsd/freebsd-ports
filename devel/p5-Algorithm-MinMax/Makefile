# New ports collection makefile for:	Algorithm::MinMax
# Date created:				Thu Oct 28 17:18:43 CST 2004
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Algorithm-MinMax
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl modules to find the minimum and maximum of an array

PERL_CONFIGURE=	yes

MAN3=		Algorithm::MinMax.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
