# New ports collection makefile for:	devel/p5-POE-XS-Loop-Poll
# Date created:				03 July 2008
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-XS-Loop-Poll
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	XS implementation of POE::Loop, using poll(2)

BUILD_DEPENDS=	${SITE_PERL}/POE/Test/Loops.pm:${PORTSDIR}/devel/p5-POE-Test-Loops
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_SCRIPT+=	Makefile.PL --default

MAN3=	POE::XS::Loop::Poll.3

.include <bsd.port.mk>
