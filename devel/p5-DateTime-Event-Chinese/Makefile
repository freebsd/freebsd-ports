# New ports collection makefile for:	p5-DateTime-Event-Chinese
# Date created:		2007-11-06
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-Chinese
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension for Calculating Important Chinese Dates

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Event-Lunar>=0.06:${PORTSDIR}/devel/p5-DateTime-Event-Lunar \
		p5-DateTime-Event-SolarTerm>=0.05:${PORTSDIR}/devel/p5-DateTime-Event-SolarTerm \
		p5-DateTime-Util-Astro>=0.11:${PORTSDIR}/devel/p5-DateTime-Util-Astro \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round
RUN_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Event-Lunar>=0.06:${PORTSDIR}/devel/p5-DateTime-Event-Lunar \
		p5-DateTime-Event-SolarTerm>=0.05:${PORTSDIR}/devel/p5-DateTime-Event-SolarTerm \
		p5-DateTime-Util-Astro>=0.11:${PORTSDIR}/devel/p5-DateTime-Util-Astro \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::Chinese.3

.include <bsd.port.mk>
