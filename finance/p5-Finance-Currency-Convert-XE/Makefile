# New ports collection makefile for:	finance/p5-Finance-Currency-Convert-XE
# Date created:				10 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Finance-Currency-Convert-XE
PORTVERSION=	0.15
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Finance
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Finance::Currency::Convert::XE - Currency conversion module

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/TokeParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Finance::Currency::Convert::XE.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
