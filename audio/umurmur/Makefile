# Created by: Ayumi Mitsui <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	umurmur
DISTVERSION=	0.2.17
CATEGORIES=	audio net

MAINTAINER=	ayu@commun.jp
COMMENT=	Minimalistic Murmur (Mumble server)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: fatal error: byteswap.h file not found
BROKEN_armv6=		fails to compile: fatal error: byteswap.h file not found
BROKEN_SSL=		openssl-devel
BROKEN_SSL_REASON_openssl-devel=	configure: error: could not find libcrypto

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libprotobuf-c.so:devel/protobuf-c

USES=		autoreconf gmake libtool localbase ssl
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
CONFIGURE_ARGS=	--with-ssl=openssl

USE_RC_SUBR=	umurmur

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/conf.c
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/umurmur.conf.example

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/umurmur
	${INSTALL_DATA} ${WRKSRC}/umurmur.conf.example ${STAGEDIR}${PREFIX}/etc/umurmur/umurmur.conf.sample

.include <bsd.port.mk>
