# New ports collection makefile for:	p5-Test-Inline
# Date created:				Mon Sep 12
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Inline
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Test::Inline - Inlining your tests next to the code being tested

BUILD_DEPENDS=	${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2test.1
MAN3=		Pod::Tests.3 Pod::Tests::Tutorial.3 Test::Inline.3 Test::Inline::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
