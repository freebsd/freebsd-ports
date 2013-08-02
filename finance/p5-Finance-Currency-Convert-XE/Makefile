# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Finance-Currency-Convert-XE
PORTVERSION=	0.25
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Currency conversion module

LICENSE=	ART20

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-WWW-Mechanize>=1.60:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

MAN3=		Finance::Currency::Convert::XE.3
PORTDOCS=	Changes README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
