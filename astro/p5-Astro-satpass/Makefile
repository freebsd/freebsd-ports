# Ports collection makefile for:	Astro-satpass
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-satpass
PORTVERSION=	0.031
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Classes and app to compute satellite visibility

BUILD_DEPENDS=	p5-Date-Manip>=1.14:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Params-Util>=0.25:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

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

OPTIONS=	SIMBAD		"Add support for Astro::SIMBAD::Client" ON \
		SPACETRACK	"Add support for Astro::SpaceTrack" ON \
		USGS		"Add support for Geo::WebService::Elevation::USGS" ON \
		SOAPLITE	"Add support for SOAP::Lite" ON

.include <bsd.port.pre.mk>
.if defined(WITH_SIMBAD)
RUN_DEPENDS+=	p5-Astro-SIMBAD-Client>=0:${PORTSDIR}/astro/p5-Astro-SIMBAD-Client
.endif

.if defined(WITH_SPACETRACK)
RUN_DEPENDS+=	p5-Astro-SpaceTrack>=0:${PORTSDIR}/astro/p5-Astro-SpaceTrack
.endif

.if defined(WITH_USGS)
RUN_DEPENDS+=	p5-Geo-WebService-Elevation-USGS>=0:${PORTSDIR}/science/p5-Geo-WebService-Elevation-USGS
.endif

.if defined(WITH_SOAPLITE)
RUN_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif
.include <bsd.port.post.mk>
