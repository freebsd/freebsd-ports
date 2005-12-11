# New ports collection makefile for:	Data::Swap
# Date created:				10 December 2005
# Whom:					Parv <parv@pair.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Swap
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	parv@pair.com
COMMENT=	XS module to swap the contents and types of referenced variables

PERL_CONFIGURE=	yes

MAN3=	Data::Swap.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		need at least Perl 5.6; install lang/perl or lang/perl5.8
.endif

.include <bsd.port.post.mk>
