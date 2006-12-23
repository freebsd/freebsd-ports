# New ports collection makefile for:	p5-Games-GuessWord
# Date created:				23 Dec 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Games-GuessWord
PORTVERSION=	0.15
CATEGORIES=	games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Games
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Guess the letters in a word (ie Hangman)

MAN3=	Games::GuessWord.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
