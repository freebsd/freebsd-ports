# New ports collection makefile for:    p5-Test-LectroTest
# Date created:				October 4th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-LectroTest
PORTVERSION=	0.3600
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex@kapranoff.ru
COMMENT=	Easy, automatic, specification-based tests

PERL_MODBUILD=	yes

MAN3=		Test::LectroTest.3 \
		Test::LectroTest::Compat.3 \
		Test::LectroTest::FailureRecorder.3 \
		Test::LectroTest::Generator.3 \
		Test::LectroTest::Property.3 \
		Test::LectroTest::RegressionTesting.3 \
		Test::LectroTest::TestRunner.3 \
		Test::LectroTest::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
.endif

.include <bsd.port.post.mk>
