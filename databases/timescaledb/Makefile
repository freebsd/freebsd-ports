# Created by: Kevin Bowling <kbowling@freebsd.org>
# $FreeBSD$

PORTNAME=	timescaledb
PORTVERSION=	2.1.0
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Time-series database built on PostgreSQL

LICENSE=		APACHE20 TSL
LICENSE_COMB=		multi
LICENSE_NAME_TSL=	Timescale License Agreement
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_TSL=	${WRKSRC}/tsl/LICENSE-TIMESCALE
LICENSE_PERMS_TSL=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c11 cmake pgsql:11,12,13

USE_GITHUB=	YES
GH_ACCOUNT=	timescale

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		SSL TSL
OPTIONS_DEFAULT=	SSL TSL
OPTIONS_SUB=		yes

SSL_DESC=		Build with OpenSSL support
TSL_DESC=		Enables TSL licensed code in additon to Apache license code

SSL_CMAKE_BOOL=		USE_OPENSSL
SSL_USES=		ssl
TSL_CMAKE_BOOL_OFF=	APACHE_ONLY

CMAKE_OFF=	REGRESS_CHECKS WARNINGS_AS_ERRORS
WANT_PGSQL=	lib server

.include <bsd.port.mk>
