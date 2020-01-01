# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	7.0.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GNU/commoncpp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_SSL=	openssl
BROKEN_SSL_REASON_openssl=	error: allocation of incomplete type 'EVP_CIPHER_CTX'

USES=		compiler:c++11-lib cmake pathfix pkgconfig ssl
CMAKE_ARGS=	-DBUILD_TESTING:BOOL=ON \
		-DCMAKE_INSTALL_BINDIR:STRING=bin/${PORTNAME}
USE_LDCONFIG=	yes
TEST_TARGET=	test

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	error: allocation of incomplete type 'EVP_CIPHER_CTX' (aka 'evp_cipher_ctx_st')
BROKEN_FreeBSD_13=	error: allocation of incomplete type 'EVP_CIPHER_CTX' (aka 'evp_cipher_ctx_st')
.endif

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/ucommon-config.h ${STAGEDIR}${PREFIX}/include/ucommon

.include <bsd.port.post.mk>
