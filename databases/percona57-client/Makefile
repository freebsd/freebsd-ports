# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	percona
PORTREVISION?=	0
PKGNAMESUFFIX=	57-client

COMMENT=	Multithreaded SQL database (client)

LICENSE=	GPLv2+

MASTERDIR=	${.CURDIR}/../percona57-server

OPTIONS_EXCLUDE=TOKUDB

PKGMESSAGE=	${.CURDIR}/pkg-message
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql*-client-* \
			mariadb*-client-* \
			percona5[0-68-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

MANPAGES=	comp_err.1 mysql.1 mysql_config.1 mysql_config_editor.1 \
		mysql_waitpid.1 mysqladmin.1 mysqlbinlog.1 \
		mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1

CLIENT_ONLY=	yes

OPTIONS_GROUP+=	PLUGINS
PLUGINS_DESC=	Default Client Plugins
OPTIONS_GROUP_PLUGINS=	SASLCLIENT
SASLCLIENT_DESC=	SASL client plugin module
SASLCLIENT_CMAKE_BOOL=	WITH_AUTHENTICATION_LDAP
SASLCLIENT_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASLCLIENT_BUILD_DEPENDS=	${LOCALBASE}/include/lber.h:net/openldap24-sasl-client
OPTIONS_DEFAULT+=	SASLCLIENT
OPTIONS_SUB=	yes

# Percona renamed the libraries, until we decide how to deal with it create some symlinks
# to prevent breaking installed ports.
post-install:
	${LN} -s libperconaserverclient.so ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient.so
	${LN} -s libperconaserverclient.so.20 ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient.so.20
	${LN} -s libperconaserverclient.a ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.a
	${LN} -s libperconaserverclient.so ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so
	${LN} -s libperconaserverclient.so.20 ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so.20
	${LN} -s perconaserverclient.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/mysqlclient.pc

.include "${MASTERDIR}/Makefile"
