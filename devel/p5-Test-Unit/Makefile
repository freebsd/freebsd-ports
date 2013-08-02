# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Test-Unit
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlUnit testing framework

BUILD_DEPENDS=	p5-Class-Inner>=0:${PORTSDIR}/devel/p5-Class-Inner \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
