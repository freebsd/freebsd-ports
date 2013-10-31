# Created by: chinsan
# $FreeBSD$

PORTNAME=	Tie-RefHash-Weak
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie::RefHash subclass with weakened references in the keys

RUN_DEPENDS=	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Tie-RefHash>=1.34:${PORTSDIR}/devel/p5-Tie-RefHash \
		p5-Variable-Magic>=0:${PORTSDIR}/devel/p5-Variable-Magic
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
