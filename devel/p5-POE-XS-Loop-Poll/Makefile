# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-XS-Loop-Poll
PORTVERSION=	1.000
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XS implementation of POE::Loop, using poll(2)

BUILD_DEPENDS=	p5-POE-Test-Loops>=1.033:devel/p5-POE-Test-Loops \
		p5-POE>=1.003:devel/p5-POE
RUN_DEPENDS=	p5-POE>=1.003:devel/p5-POE

USES=		perl5
USE_PERL5=	configure
CONFIGURE_SCRIPT+=	Makefile.PL --default

.include <bsd.port.mk>
