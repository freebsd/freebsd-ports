# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MouseX-Foreign
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extends non-Mouse classes as well as Mouse classes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=0.77:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Any-Moose>=0.15:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
