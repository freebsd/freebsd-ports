# New ports collection makefile for:	Heap::Simple
# Date created:				26 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Heap-Simple
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Heap
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Fast and easy to use classic heaps

PERL_CONFIGURE=	yes

MAN3=		Heap::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Uses ??{} in regexps, which came with perl5.6, install lang/perl5 or lang/perl5.8
.endif

.include <bsd.port.post.mk>
