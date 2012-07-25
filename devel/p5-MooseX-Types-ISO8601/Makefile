# New ports collection makefile for:	devel/p5-MooseX-Types-ISO8601
# Date created:				23 Jun 2009
# Whom:					Dag-Erling Smørgrav <des@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-ISO8601
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	ISO8601 date and duration string type constraints and coercions

RUN_DEPENDS=	p5-DateTime>=0.03:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Duration>=1.03:${PORTSDIR}/devel/p5-DateTime-Format-Duration \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0.79:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.10:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-DateTime>=0.03:${PORTSDIR}/devel/p5-MooseX-Types-DateTime \
		p5-namespace-clean>=0.05:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	MooseX::Types::ISO8601.3

.include <bsd.port.mk>
