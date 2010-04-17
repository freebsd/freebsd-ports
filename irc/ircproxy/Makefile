# New ports collection makefile for:   ircproxy
# Date created:        10 July 2003
# Whom:                Jonas Kvinge <jonas@night-light.net>
#
# $FreeBSD$
#

PORTNAME=	ircproxy
PORTVERSION=	1.3.6
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An IRC proxy/bouncer daemon

LIB_DEPENDS=	cares.2:${PORTSDIR}/dns/c-ares

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

USERS=		ircproxyd
GROUPS=		ircproxyd

SUB_LIST=	IRC_USR=${USERS} IRC_GRP=${GROUPS}
SUB_FILES=	pkg-deinstall

OPTIONS=	SSL "Enable SSL support" on \
		IPV6 "Enable IPv6 support" on \
		MEMDEBUG "Enable memory debugging" on \
		FDDEBUG "Enable file descriptor debugging" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_MEMDEBUG)
CONFIGURE_ARGS+=	--enable-memdebug
.else
CONFIGURE_ARGS+=	--disable-memdebug
.endif

.if defined(WITH_FDDEBUG)
CONFIGURE_ARGS+=	--enable-fddebug
.else
CONFIGURE_ARGS+=	--disable-fddebug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EUSER="ircproxy"|EUSER="ircproxyd"|g; \
		s|EGROUP="users"|EGROUP="ircproxyd"|g' ${WRKSRC}/data/${PORTNAME}d.conf

.include <bsd.port.post.mk>
