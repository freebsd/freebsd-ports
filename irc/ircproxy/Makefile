# Created by: Jonas Kvinge <jonas@night-light.net>
# $FreeBSD$

PORTNAME=	ircproxy
PORTVERSION=	1.3.6
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	https://BSDforge.com/projects/source/irc/ircproxy/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	IRC proxy/bouncer daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcares.so:dns/c-ares

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
SSL_USES=		ssl

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	gnutls library not found. Install gnutls or use --with-openssl
BROKEN_FreeBSD_13=	gnutls library not found. Install gnutls or use --with-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|EUSER="ircproxy"|EUSER="ircproxyd"|g; \
		s|EGROUP="users"|EGROUP="ircproxyd"|g' ${WRKSRC}/data/${PORTNAME}d.conf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/imkpasswd ${STAGEDIR}${PREFIX}/bin/ircproxyd

.include <bsd.port.post.mk>
