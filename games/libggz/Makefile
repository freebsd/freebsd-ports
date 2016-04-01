# Created by: ijliao
# $FreeBSD$

PORTNAME=	libggz
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	17
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Base Library

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SINGLE=		TLS
OPTIONS_SINGLE_TLS=	GNUTLS OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ARGS=	--with-tls=GnuTLS

OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_ARGS=	--with-tls=OpenSSL

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
