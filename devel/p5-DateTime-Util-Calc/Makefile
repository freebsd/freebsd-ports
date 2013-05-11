# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	DateTime-Util-Calc
PORTVERSION=	0.13002
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Calculation Utilities

BUILD_DEPENDS=	p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Util::Calc.3

OPTIONS_DEFINE=	GMP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMP}
BUILD_DEPENDS+=	p5-Math-BigInt-GMP>=0:${PORTSDIR}/math/p5-Math-BigInt-GMP
.endif

.include <bsd.port.mk>
