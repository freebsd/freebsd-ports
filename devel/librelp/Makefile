# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librelp
PORTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Reliable event logging protocol library

LICENSE=	GPLv3

OPTIONS_MULTI=			SSLLIB
OPTIONS_MULTI_SSLLIB=		GNUTLS OPENSSL
OPTIONS_DEFAULT=		GNUTLS OPENSSL

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=	tls

OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_ENABLE=	tls-openssl
OPENSSL_CONFIGURE_ENV=		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
				OPENSSL_CFLAGS="-I ${OPENSSLINC}"

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	include/${PORTNAME}.h \
		lib/${PORTNAME}.a \
		lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		lib/${PORTNAME}.so.0.5.0 \
		libdata/pkgconfig/relp.pc

PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/s| -g||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
