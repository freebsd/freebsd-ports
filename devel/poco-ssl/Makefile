# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poco
# New version 1.4.6p4 is available; please use DISTVERSION upon updating
PORTVERSION=	1.4.3
PORTREVISION=	5
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	${PORTNAME}-${PORTVERSION}p1-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ libraries with a network/internet focus (full version)

LICENSE=	BSL

CONFLICTS=	poco-[0-9]*

USES=		gmake tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --config=FreeBSD
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=	TEST SAMPLES MYSQL SQLITE ODBC
OPTIONS_DEFAULT=MYSQL SQLITE
OPTIONS_SUB=	yes
SAMPLES_DESC=	Build sample programs

TEST_CONFIGURE_OFF=	--no-tests
SAMPLES_CONFIGURE_OFF=	--no-samples

ODBC_LIB_DEPENDS=	libodbc.so:databases/libiodbc
ODBC_CONFIGURE_OFF=	--omit=Data/ODBC

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_OFF=	--omit=Data/MySQL

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_OFF=	--omit=Data/SQLite

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MTEST)
	@${REINPLACE_CMD} -e '/^all:/s/tests//' ${WRKSRC}/Makefile
.endif
.if empty(PORT_OPTIONS:MSAMPLES)
	@${REINPLACE_CMD} -e '/^all:/s/samples//' ${WRKSRC}/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*d.so.*

.include <bsd.port.mk>
