# New ports collection makefile for:	devel/p5-POE-Test-Loops
# Date created:				05 July 2008
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Test-Loops
PORTVERSION=	1.020
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Reusable tests for POE Loop authors

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Test::Loops.3
MAN1=	poe-gen-tests.1

.include <bsd.port.mk>
