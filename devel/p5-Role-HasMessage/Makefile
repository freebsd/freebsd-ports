# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	Role-HasMessage
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Thing with a message method

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-String-Errf>=0:${PORTSDIR}/devel/p5-String-Errf \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
