# Created by: Alex Bakhtin <Alex.Bakhtin@gmail.com>
# $FreeBSD$

PORTNAME=	App-Build
PORTVERSION=	0.74
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Alex.Bakhtin@gmail.com
COMMENT=	Build and install Perl applications

RUN_DEPENDS=	p5-App-Options>=0:${PORTSDIR}/devel/p5-App-Options \
		p5-Module-Build>=0.28:${PORTSDIR}/devel/p5-Module-Build
BUILD_DEPENDS=	p5-Test-Differences>=0.47:${PORTSDIR}/devel/p5-Test-Differences \
		p5-App-Options>=0:${PORTSDIR}/devel/p5-App-Options \
		p5-Module-Build>=0.28:${PORTSDIR}/devel/p5-Module-Build

USES=		perl5
USE_PERL5=	modbuild

.if !defined(NOPORTDOCS)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
