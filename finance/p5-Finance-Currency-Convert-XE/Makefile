# New ports collection makefile for:	finance/p5-Finance-Currency-Convert-XE
# Date created:				10 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Finance-Currency-Convert-XE
PORTVERSION=	0.21
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Finance::Currency::Convert::XE - Currency conversion module

LICENSE=	ART20

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-WWW-Mechanize>=1.60:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

OPTIONS_DEFINE=	DOCS

PERL_CONFIGURE=	yes

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
