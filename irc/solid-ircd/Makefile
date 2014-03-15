# Created by: mj <systemoperator@gmail.com>
# $FreeBSD$

PORTNAME=	solid-ircd
PORTVERSION=	3.4.8
CATEGORIES=	irc
MASTER_SITES=	SF/solidircd/Solid-Stable/solidircd-stable.${PORTVERSION}
DISTNAME=	solidircd-stable3.4.8

MAINTAINER=	systemoperator@gmail.com
COMMENT=	Solid Internet Relay Chat Daemon based on bahamut IRCd

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
