# New ports collection makefile for:	p5-DateTime-Util-Calc
# Date created:		2007-06-16
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Util-Calc
PORTVERSION=	0.13002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Calculation Utilities

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Util::Calc.3

OPTIONS=	GMP	"Use GMP library"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GMP)
BUILD_DEPENDS+=	p5-Math-BigInt-GMP>=0:${PORTSDIR}/math/p5-Math-BigInt-GMP
.endif

.include <bsd.port.post.mk>
