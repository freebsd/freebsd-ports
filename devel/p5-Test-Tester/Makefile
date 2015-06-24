# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	Test-Tester
PORTVERSION=	0.10.9
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FDALY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Helps to test various Test::Builder derivatives

CONFLICTS=	p5-Test-Simple-1.001.0[1-9]*
DEPRECATED=	Part of p5-Test-Simple (use that instead), and included in perl 5.22
EXPIRATION_DATE=2015-07-24

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
