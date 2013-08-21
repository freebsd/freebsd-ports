# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Moos
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moo s{imple,peedy,ingle}

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-XSAccessor>=1.07:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-Role-Tiny>=1.002.000:${PORTSDIR}/devel/p5-Role-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USE_PERL5=	configure
USES=		perl5

MAN1=		remoos.1
MAN3=		Moos.3 \
		Moos::Role.3 \
		oos.3

.include <bsd.port.mk>
