# -*-mode: makefile-*-
# New ports collection makefile for:	qt-mysql-plugin
# Date created:				20 April 2003
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	qt-mysql-plugin
PORTREVISION=	0
CATEGORIES=	databases x11-toolkits

MAINTAINER=	kay_lehmann@web.de
COMMENT=	A plugin for QT to connect to MySQL-Databases

LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_QT_VER=	3
QT_NONSTANDARD=	yes

LDCONFIG_DIRS=	%%PREFIX%%/lib/plugins/sqldrivers
CONFIGURE_ARGS=	-plugin-sql-mysql -fast
CONFIGURE_ENV=	${ECHO} yes | MOC="${MOC}" CPPFLAGS="${QTCPPFLAGS}" \
		LIBS="${QTCFGLIBS}" LOCALBASE="${LOCALBASE}"

BUILD_PLUGIN_ONLY=	yes


do-build:
	cd ${WRKSRC}/plugins/src/sqldrivers/mysql; \
		${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
	${MKDIR} ${PREFIX}/lib/plugins/sqldrivers
	${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlmysql.so \
		${PREFIX}/lib/plugins/sqldrivers/

.include "../../x11-toolkits/qt31/Makefile"
