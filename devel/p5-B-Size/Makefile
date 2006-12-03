# New ports collection makefile for:	p5-B-Size
# Date created:	   12 dec 2004
# Whom:		   Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Size
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Tools to measure size of Perl OPs and [SAV]Vs

PERL_CONFIGURE=	yes

MAN3=		B::Size.3 B::TerseSize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.0 or higher. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
