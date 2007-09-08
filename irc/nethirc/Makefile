# New ports collection makefile for:	nethirc
# Date created:		15 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	NetHirc
PORTVERSION=	0.94
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/nethirc/

MAINTAINER=	matt_mills@btopenworld.com
COMMENT=	Perl-based IRC client that uses Net::IRC

BUILD_DEPENDS=	${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC \
		${SITE_PERL}/String/Format.pm:${PORTSDIR}/textproc/p5-String-Format \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		nethirc.pl.1
MAN3=		NetHirc.3

.include <bsd.port.mk>
