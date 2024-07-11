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
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jansson=${PREFIX} --with-openssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=strict-prototypes
.endif

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
CFLAGS+=	-Wno-error=deprecated-declarations
.endif


.include <bsd.port.post.mk>
