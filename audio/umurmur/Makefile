PORTNAME=	umurmur
DISTVERSION=	0.2.20
CATEGORIES=	audio net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Minimalistic Murmur (Mumble server)
WWW=		https://umurmur.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool localbase
USE_GITHUB=	yes
USE_RC_SUBR=	umurmur

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092
LIB_DEPENDS+=	libmbedtls.so:security/mbedtls
CONFIGURE_ARGS=	--with-ssl=mbedtls
.else
USES+=		ssl
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Requires OpenSSL 3.0.0 deprecated CRYPTO_MEM_CHECK_ON
CONFIGURE_ARGS=	--with-ssl=openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample

.include <bsd.port.post.mk>
