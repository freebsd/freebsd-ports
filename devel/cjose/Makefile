PORTNAME=	cjose
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	jamie@chair6.net
COMMENT=	C library implementing JavaScript Object Signing and Encryption (JOSE)
WWW=		https://github.com/cisco/cjose

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c++11-lang libtool pathfix pkgconfig ssl
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated RSA_ routines
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jansson=${PREFIX} --with-openssl=${OPENSSLBASE}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=strict-prototypes
.endif

.include <bsd.port.mk>
