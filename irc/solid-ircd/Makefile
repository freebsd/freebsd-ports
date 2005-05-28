# Ports collection makefile for:	Solid-IRCd
# Date created:				26 May 2005
# Whom:					mj <freebsd@nsacenter.com>
#
# $FreeBSD$
#

PORTNAME=	solid-ircd
PORTVERSION=	3.4.7
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=solidircd
DISTNAME=	solid5

MAINTAINER=	freebsd@nsacenter.com
COMMENT=	Solid Internet Relay Chat Daemon based on bahamut IRCd

WRKSRC=		${WRKDIR}/solidircd-dev

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PORTNAME}

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.mk>
