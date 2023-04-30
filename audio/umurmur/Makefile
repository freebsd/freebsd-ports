PORTNAME=	umurmur
DISTVERSION=	0.2.17
PORTREVISION=	2
CATEGORIES=	audio net

MAINTAINER=	ayu@commun.jp
COMMENT=	Minimalistic Murmur (Mumble server)
WWW=		https://umurmur.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: fatal error: byteswap.h file not found
BROKEN_armv6=		fails to compile: fatal error: byteswap.h file not found

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool localbase ssl
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated CRYPTO_MEM_CHECK_ON
USE_GITHUB=	yes
USE_RC_SUBR=	umurmur

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=openssl

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample

.include <bsd.port.mk>
