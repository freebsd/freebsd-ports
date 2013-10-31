# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	TheSchwartz
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIXAPART
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reliable job queue

BUILD_DEPENDS=	p5-Data-ObjectDriver>=0.04:${PORTSDIR}/devel/p5-Data-ObjectDriver
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extras/check_schwartz ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/extras/thetop ${STAGEDIR}${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
