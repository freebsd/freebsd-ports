# $FreeBSD$

PORTNAME=	MooseX-CoverableModifiers
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Make Moose method modifiers Devel::Cover friendly

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=2:devel/p5-Moose \
		p5-Devel-Declare>=0:devel/p5-Devel-Declare
BUILD_DEPENDS=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
