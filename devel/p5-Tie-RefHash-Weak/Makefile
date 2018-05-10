# Created by: chinsan
# $FreeBSD$

PORTNAME=	Tie-RefHash-Weak
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie::RefHash subclass with weakened references in the keys

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Task-Weaken>=0:devel/p5-Task-Weaken \
		p5-Variable-Magic>=0:devel/p5-Variable-Magic
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
