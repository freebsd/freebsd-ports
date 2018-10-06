# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Games-Bingo-Bot
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple class holding IRC related methods for bingo

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Games-Bingo>=0:games/p5-Games-Bingo

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/bingobot.pl
USE_PERL5=	configure
NO_ARCH=	yes

PORTEXAMPLES=	bingobot.pl

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bingobot.pl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
