# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#
# If you have compelling evidence that some ports need at least this version of
# p5-Module-Build to build, be sure to update the BUILD_DEPENDS version in
# Mk/Uses/perl5.mk.

PORTNAME=	Module-Build
PORTVERSION=	0.4218
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build and install Perl modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-PAR-Dist>=0.17:devel/p5-PAR-Dist

PORTSCOUT=	skipv:0.31011,0.31012

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Test-Harness>=3.29:devel/p5-Test-Harness
RUN_DEPENDS+=	p5-Test-Harness>=3.29:devel/p5-Test-Harness
.endif

.if ${PERL_LEVEL} < 502105
BUILD_DEPENDS+=	p5-CPAN-Meta>=2.142060:devel/p5-CPAN-Meta
RUN_DEPENDS+=	p5-CPAN-Meta>=2.142060:devel/p5-CPAN-Meta
.endif

post-patch:
	@${RM} -f ${WRKSRC}/bin/config_data
	@${REINPLACE_CMD} -e '/script_files/d' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e '/^bin\/config_data/d' ${WRKSRC}/MANIFEST

.include <bsd.port.post.mk>
