# New ports collection makefile for:	IrcII Client
# Date created:		02 May 1996
# Whom:			Masafumi
#
# $FreeBSD$
#

PORTNAME=	ircii
PORTVERSION=	2.8.2
PORTREVISION=	1
CATEGORIES=	japanese irc
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/ \
		ftp://ftp.kyoto.wide.ad.jp/IRC/ircII/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:R}help.tar.gz

PATCH_SITES=	ftp://ftp.kyoto.wide.ad.jp/IRC/ircII/
PATCHFILES=	${DISTNAME}-jp.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	max@FreeBSD.org
COMMENT=	The 'Internet Relay Chat' Client

GNU_CONFIGURE=	yes
MAN1=		irc.1

post-install:
	${CP} -R ${WRKDIR}/help ${PREFIX}/lib/irc/
	${INSTALL_MAN} ${WRKSRC}/doc/ircII.1 ${PREFIX}/man/man1/irc.1

.include <bsd.port.mk>
