# New ports collection makefile for:	p5-Lingua-ZH-Segment
# Date created:		2007-06-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-ZH-Segment
PORTVERSION=	0.02
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Chinese Text Segmentation

PERL_CONFIGURE=	yes

MAN3=		Lingua::ZH::Segment.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=		requires Perl 5.8.1 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
