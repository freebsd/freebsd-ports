# Created by: mj <systemoperator@gmail.com>
# $FreeBSD$

PORTNAME=	solid-ircd
PORTVERSION=	3.4.8
CATEGORIES=	irc
MASTER_SITES=	SF/solidircd/Solid-Stable/solidircd-stable.${PORTVERSION}
DISTNAME=	solidircd-stable3.4.8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solid Internet Relay Chat Daemon based on bahamut IRCd

DEPRECATED=	Fails to build with new utmpx
EXPIRATION_DATE=	2014-07-23
WRKSRC=		${WRKDIR}/solidircd-stable

USES=		gmake
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${PORTNAME}

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
