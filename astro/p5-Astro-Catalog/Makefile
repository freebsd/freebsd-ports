# ex:ts=8
# Ports collection makefile for:	Astro-Catalog
# Date created:				Oct 19, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	Astro-Catalog
PORTVERSION=	4.1.0
CATEGORIES=	astro perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.estar.org.uk/software/
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic stellar catalogue object

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

CONFIG=		sss.cfg skycat.cfg

MAN3=		Astro::Catalog.3 \
		Astro::Catalog::IO::ASCII.3 \
		Astro::Catalog::IO::Astrom.3 \
		Astro::Catalog::IO::Binary.3 \
		Astro::Catalog::IO::Cluster.3 \
		Astro::Catalog::IO::FINDOFF.3 \
		Astro::Catalog::IO::FITSTable.3 \
		Astro::Catalog::IO::GaiaPick.3 \
		Astro::Catalog::IO::JCMT.3 \
		Astro::Catalog::IO::RITMatch.3 \
		Astro::Catalog::IO::SExtractor.3 \
		Astro::Catalog::IO::STL.3 \
		Astro::Catalog::IO::Simple.3 \
		Astro::Catalog::IO::TST.3 \
		Astro::Catalog::IO::UKIRTBS.3 \
		Astro::Catalog::IO::VOTable.3 \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

post-patch:
	@${PERL} -pi -e "s!^(my.*cfg_to_install).*!\$$1=\"\";!;" ${WRKSRC}/Makefile.PL

post-install:
.for f in ${CONFIG}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}.default
.if !exists(${PREFIX}/etc/${f})
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endif
.endfor

.include <bsd.port.post.mk>
