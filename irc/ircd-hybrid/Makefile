# Created by: David Taylor <davidt@yadt.co.uk>
# $FreeBSD$

PORTNAME=	ircd-hybrid
PORTVERSION=	8.2.30
CATEGORIES=	irc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Fast irc daemon with a number of new features

LICENSE=	GPLv2

# :keepla because port uses lt_dlopen
USES=		cpe gmake libtool:keepla tar:tgz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIB_DEPENDS+=	libltdl.so:devel/libltdl

USERS=		ircd
GROUPS=		${USERS}

USE_RC_SUBR=	ircd-hybrid
SUB_FILES=	pkg-message
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		ASSERT
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL WOLFSSL
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=		yes

ASSERT_CONFIGURE_ENABLE=	assert
ASSERT_DESC=			Enable parts of the debugging code

OPENSSL_DESC=	Enable openssl - allows use of CHALLENGE and encrypted links

INSTALL_TARGET=	install-strip

INSTALL_IGNORES=	charby* ircd-rat* ircu-*

CERTSFILE=	${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES+=			ssl
CONFIGURE_ARGS+=	--with-tls=openssl
CONFIGURE_ENV+=		libssl_CFLAGS="-I${OPENSSLINC}" \
			libssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
.elif ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		libgnutls.so:security/gnutls
CONFIGURE_ARGS+=	--with-tls=gnutls
.elif ${PORT_OPTIONS:MWOLFSSL}
LIB_DEPENDS+=		libwolfssl.so:security/wolfssl
CONFIGURE_ARGS+=	--with-tls=wolfssl
.else
CONFIGURE_ARGS+=	--with-tls=none
.endif

.if ${PORT_OPTIONS:MGNUTLS} || ${PORT_OPTIONS:MOPENSSL} || ${PORT_OPTIONS:MWOLFSSL}
RUN_DEPENDS+=	${CERTSFILE}:security/ca_root_nss
.endif

CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION} \
			--localstatedir=/var \
			--sysconfdir=${PREFIX}/etc/ircd-hybrid

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/mkpasswd ${STAGEDIR}${PREFIX}/bin/ircd-hybrid-mkpasswd

.include <bsd.port.mk>
