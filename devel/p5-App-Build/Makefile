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

RUN_DEPENDS=	p5-App-Options>=0:devel/p5-App-Options \
		p5-Module-Build>=0.28:devel/p5-Module-Build
BUILD_DEPENDS=	p5-Test-Differences>=0.47:devel/p5-Test-Differences \
		p5-App-Options>=0:devel/p5-App-Options \
		p5-Module-Build>=0.28:devel/p5-Module-Build

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
