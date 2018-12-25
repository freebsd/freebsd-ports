# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c
PORTVERSION=	6.1.11
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	variable has incomplete type 'EVP_CIPHER_CTX' (aka 'evp_cipher_ctx_st')

USES=		cmake compiler:features mysql ssl
CMAKE_ARGS+=	-DOPENSSL_INCLUDE_DIR="${OPENSSLINC}"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
CFLAGS+=	-march=i586
.endif

.if ${SSL_DEFAULT} == base
CMAKE_ARGS+=	-DWITH_SSL="system"
.else
CMAKE_ARGS+=	-DWITH_SSL="${OPENSSLBASE}"
.endif

.include <bsd.port.post.mk>
