# New ports collection makefile for:	Class-Gomor
# Date created:			3 Jan 2007
# Whom:				Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Finance-Amortization
PORTVERSION=	0.4
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	boumenot@gmail.com
COMMENT=	Simple amortization schedules

PERL_CONFIGURE=	yes

MAN3=	Finance::Amortization.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=Needs perl 5.6.0 or higher, install lang/perl5.6 and try again.
.endif

.include <bsd.port.post.mk>
