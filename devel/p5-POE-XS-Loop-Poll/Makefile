# New ports collection makefile for:	devel/p5-POE-XS-Loop-Poll
# Date created:				03 July 2008
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-XS-Loop-Poll
PORTVERSION=	1.000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XS implementation of POE::Loop, using poll(2)

BUILD_DEPENDS=	${SITE_PERL}/POE/Test/Loops.pm:${PORTSDIR}/devel/p5-POE-Test-Loops
RUN_DEPENDS=	${SITE_PERL}/POE/Kernel.pm:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes
CONFIGURE_SCRIPT+=	Makefile.PL --default

MAN3=	POE::XS::Loop::Poll.3

.include <bsd.port.mk>
