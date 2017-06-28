# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#
# If you have compelling evidence that some ports need at least this version of
# p5-Module-Build to build, be sure to update the BUILD_DEPENDS version in
# Mk/Uses/perl5.mk.

PORTNAME=	Module-Build
PORTVERSION=	0.4224
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build and install Perl modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-PAR-Dist>=0.17:devel/p5-PAR-Dist

PORTSCOUT=	skipv:0.31011,0.31012

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

post-patch:
	@${RM} ${WRKSRC}/bin/config_data
	@${REINPLACE_CMD} -e '/script_files/d' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e '/^bin\/config_data/d' ${WRKSRC}/MANIFEST

.include <bsd.port.mk>
