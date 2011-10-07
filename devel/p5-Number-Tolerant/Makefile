# New ports collection makefile for:	p5-Number-Tolerant
# Date created:		2010-11-18
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	Number-Tolerant
PORTVERSION=	1.701
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides inexact number comparisons with tolerance ranges

BUILD_DEPENDS=	p5-Math-BigRat>=0:${PORTSDIR}/math/p5-Math-BigRat \
		p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

PERL_CONFIGURE=	yes

MAN3=		Number::Tolerant.3 \
		Number::Tolerant::Constant.3 \
		Number::Tolerant::Type.3 \
		Number::Tolerant::Type::constant.3 \
		Number::Tolerant::Type::infinite.3 \
		Number::Tolerant::Type::less_than.3 \
		Number::Tolerant::Type::more_than.3 \
		Number::Tolerant::Type::offset.3 \
		Number::Tolerant::Type::or_less.3 \
		Number::Tolerant::Type::or_more.3 \
		Number::Tolerant::Type::plus_or_minus.3 \
		Number::Tolerant::Type::plus_or_minus_pct.3 \
		Number::Tolerant::Type::to.3 \
		Number::Tolerant::Union.3 \
		Test::Tolerant.3

.include <bsd.port.mk>
