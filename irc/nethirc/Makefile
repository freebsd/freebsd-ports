# New ports collection makefile for:	nethirc
# Date created:		15 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	NetHirc
PORTVERSION=	0.7
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/nethirc/old/

MAINTAINER=	matt_mills@btopenworld.com
COMMENT=	Perl-based IRC client that uses Net::IRC

RUN_DEPENDS=	${SITE_PERL}/Net/IRC.pm:${PORTSDIR}/irc/p5-IRC

PERL_CONFIGURE=	yes

MANCOMPRESSED=	no
MAN1=		nethirc.pl.1
MAN3=		NetHirc.3 nethirc.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
