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

BUILD_DEPENDS=	p5-POE-Test-Loops>=1.033:${PORTSDIR}/devel/p5-POE-Test-Loops \
		p5-POE>=1.003:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	p5-POE>=1.003:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes
CONFIGURE_SCRIPT+=	Makefile.PL --default

MAN3=	POE::XS::Loop::Poll.3

.include <bsd.port.mk>
