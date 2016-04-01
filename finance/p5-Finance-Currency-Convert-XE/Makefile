# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Finance-Currency-Convert-XE
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Currency conversion module

LICENSE=	ART20

RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-WWW-Mechanize>=1.60:www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
