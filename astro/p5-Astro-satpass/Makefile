# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Astro-satpass
PORTVERSION=	0.057
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Classes and app to compute satellite visibility

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Date-Manip>=1.14:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

OPTIONS_DEFINE=	GEOCODER_US SIMBAD SOAPLITE SPACETRACK USGS
OPTIONS_DEFAULT=	GEOCODER_US SIMBAD SPACETRACK USGS
GEOCODER_US_DESC=	Add support for Geo::Coder::Geocoder::US
SIMBAD_DESC=		Add support for Astro::SIMBAD::Client
SOAPLITE_DESC=		Add support for SOAP::Lite (deprecated)
SPACETRACK_DESC=	Add support for Astro::SpaceTrack
USGS_DESC=		Add support for Geo::WebService::Elevation::USGS

CONFIGURE_ARGS=	-y
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOCODER_US}
RUN_DEPENDS+=	p5-Geo-Coder-Geocoder-US>=0:${PORTSDIR}/misc/p5-Geo-Coder-Geocoder-US
.endif

.if ${PORT_OPTIONS:MSIMBAD}
RUN_DEPENDS+=	p5-Astro-SIMBAD-Client>=0:${PORTSDIR}/astro/p5-Astro-SIMBAD-Client
.endif

.if ${PORT_OPTIONS:MSPACETRACK}
RUN_DEPENDS+=	p5-Astro-SpaceTrack>=0:${PORTSDIR}/astro/p5-Astro-SpaceTrack
.endif

.if ${PORT_OPTIONS:MUSGS}
RUN_DEPENDS+=	p5-Geo-WebService-Elevation-USGS>=0:${PORTSDIR}/science/p5-Geo-WebService-Elevation-USGS
.endif

.if ${PORT_OPTIONS:MSOAPLITE}
RUN_DEPENDS+=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
.endif

.include <bsd.port.mk>
