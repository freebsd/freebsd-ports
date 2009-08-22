# Ports collection makefile for:	Solid-IRCd
# Date created:				26 May 2005
# Whom:					mj <systemoperator@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	solid-ircd
PORTVERSION=	3.4.8
CATEGORIES=	irc
MASTER_SITES=	SF/solidircd/Solid-Stable/solidircd-stable.${PORTVERSION}
DISTNAME=	solidircd-stable3.4.8

MAINTAINER=	systemoperator@gmail.com
COMMENT=	Solid Internet Relay Chat Daemon based on bahamut IRCd

WRKSRC=		${WRKDIR}/solidircd-stable

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PORTNAME}

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.mk>
