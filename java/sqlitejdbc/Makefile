# New ports collection makefile for:   sqlitejdbc
# Date created:        23 June 2008
# Whom:                Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	sqlitejdbc
PORTVERSION=	056
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-src
CATEGORIES=	java databases
MASTER_SITES=	http://files.zentus.com/sqlitejdbc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lapo@lapo.it
COMMENT=	A Java JDBC driver for SQLite

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_GMAKE=	yes
MAKE_ENV=	JAVA_HOME="${JAVA_HOME}"
ALL_TARGET=	native
USE_LDCONFIG=	yes

PLIST_FILES=	%%JAVAJARDIR%%/sqlitejdbc-native.jar lib/libsqlitejdbc.so

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/sqlitejdbc-v${PORTVERSION}-native.jar ${JAVAJARDIR}/sqlitejdbc-native.jar
	${INSTALL_DATA} ${WRKSRC}/build/FreeBSD/libsqlitejdbc.so ${PREFIX}/lib/

.include <bsd.port.mk>
