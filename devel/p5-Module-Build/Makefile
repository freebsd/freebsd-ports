# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#
# Do not forget to update p5-Module-Build version in Mk/Uses/perl5.mk
# while updating this port!

PORTNAME=	Module-Build
PORTVERSION=	0.4205
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build and install Perl modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-PAR-Dist>=0.17:${PORTSDIR}/devel/p5-PAR-Dist

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	skipv:0.31011,0.31012

USES=		perl5
USE_PERL5=	modbuild

PORTDOCS=	Changes INSTALL README

post-patch:
	@${RM} -f ${WRKSRC}/bin/config_data
	@${REINPLACE_CMD} -e '/script_files/d' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e '/^bin\/config_data/d' ${WRKSRC}/MANIFEST

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
