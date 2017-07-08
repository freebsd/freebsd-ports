# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	DateTime-Util-Calc
PORTVERSION=	0.13002
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Calculation Utilities

BUILD_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GMP

GMP_BUILD_DEPENDS=	p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP
GMP_RUN_DEPENDS=	p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP

.include <bsd.port.mk>
