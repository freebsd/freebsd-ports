# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c
PORTVERSION=	6.1.6
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C

LICENSE=	GPLv2

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes
USES=		cmake:outsource compiler:features mysql
CMAKE_ARGS+=	-DWITH_SSL=system \
		-DOPENSSL_INCLUDE_DIR=${LOCALBASE}/include/openssl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
CFLAGS+=	-march=i586
.endif

.include <bsd.port.post.mk>
