# New ports collection makefile for:	p5-Games-Bingo-Bot
# Date created:				20. August 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Games-Bingo-Bot
PORTVERSION=	0.01
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A simple class holding IRC related methods for bingo

BUILD_DEPENDS=	${SITE_PERL}/Games/Bingo.pm:${PORTSDIR}/games/p5-Games-Bingo
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Games::Bingo::Bot.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing example for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingobot.pl ${EXAMPLESDIR}
.endif

test:
	@cd ${WRKSRC}; make test

.include <bsd.port.mk>
