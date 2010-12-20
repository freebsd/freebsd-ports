# New ports collection makefile for:	p5-Bot-BasicBot
# Date created:				23 Dec 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bot-BasicBot
PORTVERSION=	0.84
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN/Bot
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Simple irc bot baseclass

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Bot::BasicBot.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
