# Ports collection makefile for:	Astro-satpass
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-satpass
PORTVERSION=	0.025
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Classes and app to compute satellite visibility

RUN_DEPENDS=	p5-Date-Manip>=1.14:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Params-Util>=0.25:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-y

MAN1=	satpass.1
MAN3=	Astro::Coord::ECI::Utils.3 \
	Astro::Coord::ECI::TLE::Iridium.3 \
	Astro::Coord::ECI::TLE::Set.3 \
	Astro::Coord::ECI::TLE.3 \
	Astro::Coord::ECI::Star.3 \
	Astro::Coord::ECI::OVERVIEW.3 \
	Astro::Coord::ECI::Moon.3 \
	Astro::Coord::ECI::Sun.3 \
	Astro::Coord::ECI.3

.include <bsd.port.mk>
