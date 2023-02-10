PORTNAME=	mysql-connector-c
PORTVERSION=	6.1.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C
WWW=		https://dev.mysql.com/downloads/c-api/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	C Connector is included in mysql packages since 5.6
EXPIRATION_DATE=	2023-03-31

USES=		cmake compiler:features mysql ssl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

CMAKE_ARGS+=	-DOPENSSL_INCLUDE_DIR="${OPENSSLINC}"

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if (${OPSYS} == FreeBSD && ${SSL_DEFAULT} == base) || ${SSL_DEFAULT} == openssl
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-vio_viosslfactories.c \
		${FILESDIR}/extra-patch-mysys__ssl_my__aes__openssl.cc
.endif

.if ${SSL_DEFAULT} == base
CMAKE_ARGS+=	-DWITH_SSL="system"
.else
CMAKE_ARGS+=	-DWITH_SSL="${OPENSSLBASE}"
.endif

.include <bsd.port.post.mk>
