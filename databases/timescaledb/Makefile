# Created by: Kevin Bowling <kbowling@freebsd.org>
# $FreeBSD$

PORTNAME=	timescaledb
PORTVERSION=	1.2.0
CATEGORIES=	databases

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Time-series database built on PostgreSQL

LICENSE=		APACHE20 TSL
LICENSE_COMB=		multi
LICENSE_NAME_TSL=	Timescale License Agreement
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_TSL=	${WRKSRC}/tsl/LICENSE-TIMESCALE
LICENSE_PERMS_TSL=	dist-mirror pkg-mirror auto-accept

USES=		compiler:c11 cmake pgsql:9.6,10,11 ssl

USE_GITHUB=	YES
GH_ACCOUNT=	timescale

OPTIONS_DEFINE=		APACHEONLY
OPTIONS_SUB=		yes

APACHEONLY_CMAKE_BOOL=	APACHE_ONLY
APACHEONLY_DESC=	Only build Apache licensed code

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message

WANT_PGSQL=	server

.include <bsd.port.mk>
