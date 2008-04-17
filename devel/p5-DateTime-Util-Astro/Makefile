# New ports collection makefile for:	p5-DateTime-Util-Astro
# Date created:		2007-06-19
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Util-Astro
PORTVERSION=	0.11001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Utilities for Astronomical Calculations

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Util-Calc>=0.13:${PORTSDIR}/devel/p5-DateTime-Util-Calc \
		p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Util::Astro.3 \
		DateTime::Util::Astro::Common.3 \
		DateTime::Util::Astro::Moon.3 \
		DateTime::Util::Astro::Sun.3

.include <bsd.port.mk>
