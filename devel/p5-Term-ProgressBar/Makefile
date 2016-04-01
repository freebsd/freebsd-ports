# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Term-ProgressBar
PORTVERSION=	2.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to display a progress bar

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-MethodMaker>=1.02:devel/p5-Class-MethodMaker \
		p5-Term-ReadKey>=2.14:devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.13:devel/p5-Capture-Tiny \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
