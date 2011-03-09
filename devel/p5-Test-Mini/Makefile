# New ports collection makefile for:	p5-Test-Mini
# Date created:		2011-01-13
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Mini
PORTVERSION=	v1.1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/P/PV/PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Provides lightweight unit testing framework

BUILD_DEPENDS=	p5-Data-Inspect>=0.03:${PORTSDIR}/devel/p5-Data-Inspect \
		p5-Exception-Class>=1.30:${PORTSDIR}/devel/p5-Exception-Class \
		p5-IO-stringy>=2.110:${PORTSDIR}/devel/p5-IO-stringy \
		p5-MRO-Compat>=0.10:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Text-Outdent>=0.01:${PORTSDIR}/devel/p5-Text-Outdent \
		p5-Try-Tiny>=0.04:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-aliased>=0.30:${PORTSDIR}/devel/p5-aliased \
		p5-namespace-clean>=0.14:${PORTSDIR}/devel/p5-namespace-clean

PERL_CONFIGURE=	yes

MAN3=	Test::Mini.3 \
	Test::Mini::Assertions.3 \
	Test::Mini::Logger.3 \
	Test::Mini::Logger::TAP.3 \
	Test::Mini::Runner.3 \
	Test::Mini::TestCase.3 \
	Test::README.3

.include <bsd.port.mk>
