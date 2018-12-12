# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poco
# New version 1.4.6p4 is available; please use DISTVERSION upon updating
PORTVERSION=	1.4.3
PORTREVISION=	6
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	${PORTNAME}-${PORTVERSION}p1-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ libraries with a network/internet focus (full version)

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	field has incomplete type 'EVP_CIPHER_CTX' (aka 'evp_cipher_ctx_st')

CONFLICTS=	poco-[0-9]*

USES=		${USES_${ARCH}} gmake tar:bzip2 ssl
USES_powerpc=	compiler:c++11-lang
USES_powerpcspe=	compiler:c++11-lang
USES_powerpc64=	compiler:c++11-lang
USES_sparc64=	compiler:c++11-lang
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --config=FreeBSD
USE_LDCONFIG=	yes
CXXFLAGS+=	-D_WANT_SEMUN

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

post-extract:
	@${RM} -f ${WRKSRC}/Foundation/include/Poco/._Version.h

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/^all:/s/tests//' ${WRKSRC}/Makefile

post-patch-SAMPLES-off:
	@${REINPLACE_CMD} -e '/^all:/s/samples//' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*d
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*d.so.*

.include <bsd.port.mk>
