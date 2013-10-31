# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	Test-Tester
PORTVERSION=	0.10.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FDALY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps to test various Test::Builder derivatives

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
