# Created by: mat
# $FreeBSD$

PORTNAME=	Pod-Coverage
PORTVERSION=	0.23
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Checks if the documentation of a module is comprehensive

BUILD_DEPENDS=	p5-Devel-Symdump>=2.01:${PORTSDIR}/devel/p5-Devel-Symdump
RUN_DEPENDS=	p5-Devel-Symdump>=2.01:${PORTSDIR}/devel/p5-Devel-Symdump

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes
PORTEXAMPLES=	check_installed script-covered

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/examples/|} ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
