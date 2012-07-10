# New ports collection makefile for:	p5-Astro-Coords
# Date created:		2012-07-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-Coords
PORTVERSION=	0.15
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class for handling astronomical coordinates

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Astro-PAL>=0:${PORTSDIR}/astro/p5-Astro-PAL \
		p5-Astro-Telescope>=0.71:${PORTSDIR}/astro/p5-Astro-Telescope \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=	yes

MAN3=		Astro::Coords.3 \
		Astro::Coords::Angle.3 \
		Astro::Coords::Angle::Hour.3 \
		Astro::Coords::Calibration.3 \
		Astro::Coords::Elements.3 \
		Astro::Coords::Equatorial.3 \
		Astro::Coords::Fixed.3 \
		Astro::Coords::Interpolated.3 \
		Astro::Coords::Offset.3 \
		Astro::Coords::Planet.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Time-Piece>=1.02:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS+=	p5-Time-Piece>=1.02:${PORTSDIR}/devel/p5-Time-Piece
.endif

.include <bsd.port.post.mk>
