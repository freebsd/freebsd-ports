# New ports collection makefile for:    p5-Test-LectroTest
# Date created:				October 4th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-LectroTest
PORTVERSION=	0.2007
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex@kapranoff.ru
COMMENT=	Easy, automatic, specification-based tests

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Test::LectroTest.3 Test::LectroTest::Generator.3 \
		Test::LectroTest::Property.3 Test::LectroTest::TestRunner.3 \
		Test::LectroTest::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
