# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	DateTime-Util-Calc
PORTVERSION=	0.13002
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Calculation Utilities

BUILD_DEPENDS=	p5-Math-BigInt>=0:math/p5-Math-BigInt \
		p5-DateTime>=0:devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GMP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMP}
BUILD_DEPENDS+=	p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP
.endif

.include <bsd.port.mk>
