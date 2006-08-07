# New ports collection makefile for:	p5-Tie-Simple
# Date created:		2006-08-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-Simple
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Variable ties made easier: much, much, much easier

PERL_CONFIGURE=	yes

MAN3=		Tie::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
