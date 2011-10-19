# Ports collection makefile for:	Astro-satpass
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-satpass
PORTVERSION=	0.044
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Classes and app to compute satellite visibility

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Date-Manip>=1.14:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	p5-Date-Manip>=1.14:${PORTSDIR}/devel/p5-Date-Manip

OPTIONS=	SIMBAD		"Add support for Astro::SIMBAD::Client" on \
		SOAPLITE	"Add support for SOAP::Lite" on \
		SPACETRACK	"Add support for Astro::SpaceTrack" on \
		USGS		"Add support for Geo::WebService::Elevation::USGS" on

CONFIGURE_ARGS=	-y
PERL_CONFIGURE=	yes

MAN1=		satpass.1
MAN3=		Astro::Coord::ECI::Utils.3 \
		Astro::Coord::ECI::TLE::Iridium.3 \
		Astro::Coord::ECI::TLE::Set.3 \
		Astro::Coord::ECI::TLE.3 \
		Astro::Coord::ECI::Star.3 \
		Astro::Coord::ECI::OVERVIEW.3 \
		Astro::Coord::ECI::Moon.3 \
		Astro::Coord::ECI::Sun.3 \
		Astro::Coord::ECI.3

.include <bsd.port.options.mk>

.if !defined(WITHOUT_SIMBAD)
RUN_DEPENDS+=	p5-Astro-SIMBAD-Client>=0:${PORTSDIR}/astro/p5-Astro-SIMBAD-Client
.endif

.if !defined(WITHOUT_SPACETRACK)
RUN_DEPENDS+=	p5-Astro-SpaceTrack>=0:${PORTSDIR}/astro/p5-Astro-SpaceTrack
.endif

.if !defined(WITHOUT_USGS)
RUN_DEPENDS+=	p5-Geo-WebService-Elevation-USGS>=0:${PORTSDIR}/science/p5-Geo-WebService-Elevation-USGS
.endif

.if !defined(WITHOUT_SOAPLITE)
RUN_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
