# Created by: Alex Bakhtin <Alex.Bakhtin@gmail.com>
# $FreeBSD$

PORTNAME=	App-Build
PORTVERSION=	0.74
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	Build and install Perl applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Options>=0:devel/p5-App-Options \
		p5-Module-Build>=0.28:devel/p5-Module-Build
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0.47:devel/p5-Test-Differences

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
