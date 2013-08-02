# Created by: ijliao
# $FreeBSD$

PORTNAME=	Astro-Catalog
PORTVERSION=	4.2.7
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic stellar catalogue object

LICENSE=	GPLv3

# p5-Astro-FITS-CFITSIO is a recommended dependency
BUILD_DEPENDS=	p5-Astro-Coords>=0.12:${PORTSDIR}/astro/p5-Astro-Coords \
		p5-Astro-FITS-CFITSIO>=1.03:${PORTSDIR}/astro/p5-Astro-FITS-CFITSIO \
		p5-Astro-Flux>=0.01:${PORTSDIR}/astro/p5-Astro-Flux \
		p5-Astro-Telescope>=0.50:${PORTSDIR}/astro/p5-Astro-Telescope \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-Misc-Quality>=0.1:${PORTSDIR}/astro/p5-Misc-Quality \
		p5-Number-Uncertainty>=0.1:${PORTSDIR}/math/p5-Number-Uncertainty \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-libwww>=5.53:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		perl5
USE_PERL5=	modbuild

MAN3=		Astro::Catalog.3 \
		Astro::Catalog::IO::ASCII.3 \
		Astro::Catalog::IO::ASSM.3 \
		Astro::Catalog::IO::Astrom.3 \
		Astro::Catalog::IO::Binary.3 \
		Astro::Catalog::IO::Cluster.3 \
		Astro::Catalog::IO::FINDOFF.3 \
		Astro::Catalog::IO::FITSTable.3 \
		Astro::Catalog::IO::GaiaPick.3 \
		Astro::Catalog::IO::JCMT.3 \
		Astro::Catalog::IO::LCOGTFITSTable.3 \
		Astro::Catalog::IO::Northstar.3 \
		Astro::Catalog::IO::RITMatch.3 \
		Astro::Catalog::IO::SExtractor.3 \
		Astro::Catalog::IO::STL.3 \
		Astro::Catalog::IO::Simple.3 \
		Astro::Catalog::IO::TST.3 \
		Astro::Catalog::IO::UKIRTBS.3 \
		Astro::Catalog::IO::VOTable.3 \
		Astro::Catalog::IO::XY.3 \
		Astro::Catalog::Item.3 \
		Astro::Catalog::Item::Morphology.3 \
		Astro::Catalog::Query.3 \
		Astro::Catalog::Query::2MASS.3 \
		Astro::Catalog::Query::CMC.3 \
		Astro::Catalog::Query::GSC.3 \
		Astro::Catalog::Query::MPC.3 \
		Astro::Catalog::Query::SIMBAD.3 \
		Astro::Catalog::Query::Sesame.3 \
		Astro::Catalog::Query::SkyCat.3 \
		Astro::Catalog::Query::SuperCOSMOS.3 \
		Astro::Catalog::Query::USNOA2.3 \
		Astro::Catalog::Query::Vizier.3 \
		Astro::Catalog::Star.3 \
		Astro::Catalog::Star::Morphology.3 \
		Astro::Catalog::Transport::REST.3 \
		Astro::Catalog::Transport::WebService.3 \
		Tk::AstroCatalog.3

post-patch:
	@${REINPLACE_CMD} -e '/\.cfg/ s|\.cfg|&.sample|2' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
