# Created by: gahr

PORTNAME=	mysql-connector-c
PORTVERSION=	6.1.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:features mysql ssl
CMAKE_ARGS+=	-DOPENSSL_INCLUDE_DIR="${OPENSSLINC}"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
CFLAGS+=	-march=i586
.endif

.if (${OPSYS} == FreeBSD && ${OSVERSION} > 1200085 && ${SSL_DEFAULT} == base) || ${SSL_DEFAULT} == openssl
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-vio_viosslfactories.c \
		${FILESDIR}/extra-patch-mysys__ssl_my__aes__openssl.cc
.endif

.if ${SSL_DEFAULT} == base
CMAKE_ARGS+=	-DWITH_SSL="system"
.else
CMAKE_ARGS+=	-DWITH_SSL="${OPENSSLBASE}"
.endif

.include <bsd.port.post.mk>
