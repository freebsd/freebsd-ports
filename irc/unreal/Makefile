# Ports collection makefile for:	Unreal-IRCd
# Date created:				15 April 2004
# Whom:					Gerrit Beine (<tux@pinguru.net>)
# ToDo:	Make the configuration more flexible using -DOPTION for the
#	configuration values, especially support for IPv6.
#
# $FreeBSD$
#

PORTNAME=	Unreal
PORTVERSION=	3.2
CATEGORIES=	irc
MASTER_SITES=	http://mirror.nimsay-networks.com/unrealircd/ \
		http://unrealircd.za.net/ \
		ftp://unrealircd.za.net/pub/UnrealIRCd/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tux@pinguru.net
COMMENT=	Unreal - the next generation ircd

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-nospoof \
		--enable-hub \
		--enable-ziplinks \
		--with-listen=5 \
		--with-dpath=${PREFIX}/Unreal \
		--with-spath=${PREFIX}/Unreal/ircd \
		--with-nick-history=2000 \
		--with-sendq=3000000 \
		--with-bufferpool=18 \
		--with-permissions=0600 \
		--with-fd-setsize=1024 \
		--enable-dynamic-linking

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.endif

.include <bsd.port.mk>
