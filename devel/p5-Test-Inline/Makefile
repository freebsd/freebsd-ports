# New ports collection makefile for:	p5-Test-Inline
# Date created:				Mon Sep 12
# Whom:					Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-Inline
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2test.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Pod::Tests.3 Pod::Tests::Tutorial.3 Test::Inline.3 Test::Inline::Tutorial.3

.include <bsd.port.mk>
