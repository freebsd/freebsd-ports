# New ports collection makefile for:	p5-B-Size
# Date created:	   12 dec 2004
# Whom:		   Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Size
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Tools to measure size of Perl OPs and [SAV]Vs

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		B::Size.3 B::TerseSize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
BROKEN=		Does not build with perl >= 5.10
.endif

.include <bsd.port.post.mk>
