# Created by: mat
# $FreeBSD$

PORTNAME=	Devel-Cover
PORTVERSION=	1.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Code coverage metrics for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PPI-HTML>=1.07:${PORTSDIR}/textproc/p5-PPI-HTML \
		p5-Parallel-Iterator>=0:${PORTSDIR}/devel/p5-Parallel-Iterator \
		p5-Pod-Coverage>=0.06:${PORTSDIR}/devel/p5-Pod-Coverage \
		p5-Template-Toolkit>=2:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Devel/Cover/Cover.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
