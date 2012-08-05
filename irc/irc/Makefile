# New ports collection makefile for:	Irc Server
# Date created:		23 August 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	2.11.2p3
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.irc.org/ftp/irc/server/ \
		ftp://ftp.archive.de.uu.net/pub/mirrors/ftp.irc.org/server/ \
		ftp://ftp.nl.uu.net/pub/mirrors/ftp.irc.org/server/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The "Internet Relay Chat" Server

CONFLICTS_INSTALL=	charybdis-[0-9]* ircd-hybrid-[0-9]* Nefarious-[0-9]* \
			ru-ircd-hybrid-[0-9]* ircd-ru-[0-9]*

USE_RC_SUBR=	ircd
MAN5=		iauth.conf.5
MAN8=		ircd.8 iauth.8 ircdwatch.8

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd
BUILD_WRKSRC=	${WRKSRC}/${MACHINE_ARCH}-unknown-freebsd${OSREL}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include <bsd.port.mk>
