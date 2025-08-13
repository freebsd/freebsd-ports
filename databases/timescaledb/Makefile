PORTNAME=	timescaledb
PORTVERSION=	2.21.3
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Time-series database built on PostgreSQL
WWW=		https://www.timescale.com/

LICENSE=	APACHE20 TSL
LICENSE_COMB=	multi
LICENSE_NAME_TSL=	Timescale License Agreement
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_TSL=	${WRKSRC}/tsl/LICENSE-TIMESCALE
LICENSE_PERMS_TSL=	dist-mirror pkg-mirror auto-accept

BROKEN_i386=	compilation fails: undeclared type '__uint128_t'

USES=		cmake compiler:c11 cpe pgsql:15-17

CPE_VENDOR=	timescale
WANT_PGSQL=	lib server
USE_GITHUB=	YES
GH_ACCOUNT=	timescale

CMAKE_OFF=	REGRESS_CHECKS TAP_CHECKS WARNINGS_AS_ERRORS

SUB_FILES=	pkg-message
SUB_LIST=	PORTVERSION=${PORTVERSION}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		SSL TSL
OPTIONS_DEFAULT=	SSL TSL
OPTIONS_SUB=		yes

SSL_DESC=	Build with OpenSSL support
TSL_DESC=	Enables TSL licensed code in additon to Apache license code

SSL_USES=		ssl
SSL_CMAKE_BOOL=		USE_OPENSSL
TSL_CMAKE_BOOL_OFF=	APACHE_ONLY

.include <bsd.port.mk>
