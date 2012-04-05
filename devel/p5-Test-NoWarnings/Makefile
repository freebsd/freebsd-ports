# New ports collection makefile for:    p5-Test-NoWarnings
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-NoWarnings
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Hide and store warnings while running test scripts

BUILD_DEPENDS=	p5-Test-Tester>=0.107:${PORTSDIR}/devel/p5-Test-Tester \
		p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
		p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \

PERL_CONFIGURE=	yes

MAN3=		Test::NoWarnings.3

OPTIONS=	DEVEL_STACKTRACE "Stack trace support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEVEL_STACKTRACE)
RUN_DEPENDS+=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace
.endif

.include <bsd.port.post.mk>
