# Created by: Jonas Kvinge <jonas@night-light.net>
# $FreeBSD$

PORTNAME=	ircproxy
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An IRC proxy/bouncer daemon

LICENSE=	GPLv3

LIB_DEPENDS=	cares:${PORTSDIR}/dns/c-ares

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

USERS=		ircproxyd
GROUPS=		ircproxyd

SUB_LIST=	IRC_USR=${USERS} IRC_GRP=${GROUPS}
SUB_FILES=	pkg-deinstall

OPTIONS_DEFINE=	SSL IPV6 MEMDEBUG FDDEBUG
OPTIONS_DEFAULT=	SSL MEMDEBUG FDDEBUG
MEMDEBUG_DESC=	Enable memory debugging
FDDEBUG_DESC=	Enable file descriptor debugging

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=		yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MMEMDEBUG}
CONFIGURE_ARGS+=	--enable-memdebug
.else
CONFIGURE_ARGS+=	--disable-memdebug
.endif

.if ${PORT_OPTIONS:MFDDEBUG}
CONFIGURE_ARGS+=	--enable-fddebug
.else
CONFIGURE_ARGS+=	--disable-fddebug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EUSER="ircproxy"|EUSER="ircproxyd"|g; \
		s|EGROUP="users"|EGROUP="ircproxyd"|g' ${WRKSRC}/data/${PORTNAME}d.conf

.include <bsd.port.mk>
