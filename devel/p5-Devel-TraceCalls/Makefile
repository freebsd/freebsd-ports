# New ports collection makefile for:    devel/p5-Devel-TraceCalls
# Date created:                         Fri Dec  9 18:46:07 CET 2005
# Whom:                                 Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Devel-TraceCalls
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Track calls to subs, classes and object instances

PERL_CONFIGURE=	yes

MAN3=		Devel::TraceCalls.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again.
.endif
.include <bsd.port.post.mk>
