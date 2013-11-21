# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bread-Board
PORTVERSION=	0.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Solderless way to wire up your application components

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Clone>=0.05:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-MooseX-Params-Validate>=0.14:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Form-Sensible>=0:${PORTSDIR}/devel/p5-Form-Sensible \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
