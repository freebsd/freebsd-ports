# Created by: Jonas Kvinge <jonas@night-light.net>
# $FreeBSD$

PORTNAME=	ircproxy
PORTVERSION=	1.3.6
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy/bouncer daemon

LICENSE=	GPLv3

LIB_DEPENDS=	libcares.so:${PORTSDIR}/dns/c-ares

USES=		tar:bzip2
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lcrypto
CFLAGS+=	-I${LOCALBASE}/include

USERS=		ircproxyd
GROUPS=		ircproxyd

SUB_LIST=	IRC_USR=${USERS} IRC_GRP=${GROUPS}
SUB_FILES=	pkg-deinstall

OPTIONS_DEFINE=	SSL IPV6 MEMDEBUG FDDEBUG
OPTIONS_DEFAULT=	SSL MEMDEBUG FDDEBUG
MEMDEBUG_DESC=	Enable memory debugging
FDDEBUG_DESC=	Enable file descriptor debugging

MEMDEBUG_CONFIGURE_ENABLE=	memdebug
FDDEBUG_CONFIGURE_ENABLE=	fddebug
IPV6_CONFIGURE_ENABLE=		ipv6
SSL_CONFIGURE_ENABLE=		ssl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=		yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EUSER="ircproxy"|EUSER="ircproxyd"|g; \
		s|EGROUP="users"|EGROUP="ircproxyd"|g' ${WRKSRC}/data/${PORTNAME}d.conf

.include <bsd.port.mk>
