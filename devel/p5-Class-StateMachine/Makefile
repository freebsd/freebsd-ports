# $FreeBSD$

PORTNAME=	Class-StateMachine
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Define classes for state machines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MRO-Define>=0.01:devel/p5-MRO-Define \
		p5-Package-Stash>=0.29:devel/p5-Package-Stash \
		p5-Sub-Name>=0.05:devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
