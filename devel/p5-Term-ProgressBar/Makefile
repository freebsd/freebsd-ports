# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Term-ProgressBar
PORTVERSION=	2.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to display a progress bar

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-MethodMaker>=1.02:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-Term-ReadKey>=2.14:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.13:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -e 's|Term-ProgressBar|Term/ProgressBar|' ${WRKSRC}/Makefile.PL

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
