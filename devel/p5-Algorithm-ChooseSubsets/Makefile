# New ports collection makefile for:	Algorithm::ChooseSubsets
# Date created:				04 Mar 2005
# Whom:					lars.eggert@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Algorithm-ChooseSubsets
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Algorithm
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Perl algorithm to iterate through subsets of a list

PERL_CONFIGURE=	yes

MAN3=		Algorithm::ChooseSubsets.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Needs perl 5.6.0 or higher, install lang/perl5.6 and try again"
.endif

.include <bsd.port.post.mk>
