# New ports collection makefile for:	p5-Lingua-JA-Numbers
# Date created:				18 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-JA-Numbers
PORTVERSION=	0.04
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Converts numeric values to and from their Japanese string equivalents

MAN3=	Lingua::JA::Numbers.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801 # as set by vendor
IGNORE=	requires at least Perl 5.8.1.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
