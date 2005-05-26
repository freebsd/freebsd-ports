# New ports collection makefile for:	Test-Unit
# Date created:	   26 September 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-Unit
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PerlUnit testing framework

BUILD_DEPENDS=	${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Class/Inner.pm:${PORTSDIR}/devel/p5-Class-Inner \
		${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Unit.3 Test::Unit::Assert.3 Test::Unit::Assertion.3 \
		Test::Unit::Assertion::Boolean.3 \
		Test::Unit::Assertion::CodeRef.3 \
		Test::Unit::Assertion::Exception.3 \
		Test::Unit::Assertion::Regexp.3 Test::Unit::Debug.3 \
		Test::Unit::Decorator.3 Test::Unit::Error.3 \
		Test::Unit::Exception.3 Test::Unit::Failure.3 \
		Test::Unit::HarnessUnit.3 Test::Unit::Listener.3 \
		Test::Unit::Loader.3 Test::Unit::Procedural.3 \
		Test::Unit::Result.3 Test::Unit::Runner.3 \
		Test::Unit::Runner::Terminal.3 Test::Unit::Setup.3 \
		Test::Unit::Test.3 Test::Unit::TestCase.3 \
		Test::Unit::TestRunner.3 Test::Unit::TestSuite.3 \
		Test::Unit::TkTestRunner.3 Test::Unit::Tutorial.3 \
		Test::Unit::UnitHarness.3 Test::Unit::Warning.3

.include <bsd.port.mk>
