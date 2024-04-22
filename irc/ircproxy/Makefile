PORTNAME=	ircproxy
DISTVERSION=	1.3.8
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	IRC proxy/bouncer daemon
WWW=		https://codeberg.org/BSDforge/ircproxy

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcares.so:dns/c-ares

USES=		autoreconf localbase:ldflags
GNU_CONFIGURE=	yes
LDFLAGS+=	-lcrypto

WRKSRC=		${WRKDIR}/${PORTNAME}

USERS=		ircproxyd
GROUPS=		ircproxyd

OPTIONS_DEFINE=		FDDEBUG IPV6 MEMDEBUG SSL
OPTIONS_DEFAULT=	FDDEBUG MEMDEBUG SSL
FDDEBUG_DESC=		Enable file descriptor debugging
MEMDEBUG_DESC=		Enable memory debugging

FDDEBUG_CONFIGURE_ENABLE=	fddebug
IPV6_CONFIGURE_ENABLE=		ipv6
MEMDEBUG_CONFIGURE_ENABLE=	memdebug
SSL_USES=			ssl
SSL_CONFIGURE_ENABLE=		ssl

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|EUSER="ircproxy"|EUSER="ircproxyd"|g; \
		s|EGROUP="users"|EGROUP="ircproxyd"|g' ${WRKSRC}/data/${PORTNAME}d.conf
	@${REINPLACE_CMD} -e '/gnutls/!s,SSL_library_init,OPENSSL_init_ssl,' \
		${WRKSRC}/configure.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/imkpasswd ${STAGEDIR}${PREFIX}/bin/ircproxyd

.include <bsd.port.post.mk>
