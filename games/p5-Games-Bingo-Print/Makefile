# New ports collection makefile for:	p5-Games-Bingo
# Date created:				14. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Games-Bingo-Print
PORTVERSION=	0.02
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Games::Bingo::Print - PDF Generation Class

BUILD_DEPENDS=	${SITE_PERL}/Games/Bingo.pm:${PORTSDIR}/games/p5-Games-Bingo \
		${SITE_PERL}/PDFLib.pm:${PORTSDIR}/print/p5-PDFLib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Games::Bingo::Print.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing example for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingo_print.pl ${EXAMPLESDIR}
.endif

test:
	@cd ${WRKSRC}; make test

.include <bsd.port.mk>
