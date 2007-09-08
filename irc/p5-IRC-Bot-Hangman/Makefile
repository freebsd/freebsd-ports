# New ports collection makefile for:	p5-IRC-Bot-Hangman
# Date created:				23 Dec 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IRC-Bot-Hangman
PORTVERSION=	0.1
CATEGORIES=	irc games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/P/PD/PDENIS
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An IRC hangman bot

BUILD_DEPENDS=	${SITE_PERL}/Bot/BasicBot.pm:${PORTSDIR}/irc/p5-Bot-BasicBot \
		${SITE_PERL}/Games/GuessWord.pm:${PORTSDIR}/games/p5-Games-GuessWord \
		${SITE_PERL}/Module/Find.pm:${PORTSDIR}/devel/p5-Module-Find \
		${SITE_PERL}/Chatbot/Eliza.pm:${PORTSDIR}/misc/p5-Chatbot-Eliza \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	IRC::Bot::Hangman.3 \
	IRC::Bot::Hangman::Command.3 \
	IRC::Bot::Hangman::Command::Default.3 \
	IRC::Bot::Hangman::Command::Eliza.3 \
	IRC::Bot::Hangman::Command::Profanity.3 \
	IRC::Bot::Hangman::Response.3 \
	IRC::Bot::Hangman::Response::Default.3 \
	IRC::Bot::Hangman::Response::Profanity.3 \
	IRC::Bot::Hangman::WordList.3 \
	IRC::Bot::Hangman::WordList::Default.3 \
	IRC::Bot::Hangman::WordList::TooEasy.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
