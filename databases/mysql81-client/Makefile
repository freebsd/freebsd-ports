PORTNAME=	mysql
PORTREVISION=	1
PKGNAMESUFFIX=	81-client

COMMENT=	Multithreaded SQL database (client)

LICENSE+=	LGPL21

DEPRECATED=	MySQL 8.1 is not supported by the vendor and has unfixed vulnerabilies
EXPIRATION_DATE=2024-09-01

MASTERDIR=	${.CURDIR}/../mysql81-server

PKGMESSAGE=	${.CURDIR}/pkg-message
PATCHDIR=	${MASTERDIR}/files
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql8[1-9]-client \
			mysql[0-79][0-9]-client \
			mariadb[0-9][0-9]-client \
			percona[0-9][0-9]-client

CMAKE_ARGS+=	-DWITHOUT_SERVER=1 -DINSTALL_SUPPORTFILESDIR=0

USE_LDCONFIG+=	${PREFIX}/lib/mysql

MMAN1=		comp_err.1 lz4_decompress.1 mysql.1 mysql_config.1 mysql_config_editor.1 \
		mysqladmin.1 mysqlbinlog.1 mysqlcheck.1 mysqldump.1 mysqlimport.1 mysqlman.1 \
		mysqlpump.1 mysqlshow.1 mysqlslap.1 perror.1 zlib_decompress.1

CLIENT_ONLY=	yes

OPTIONS_GROUP+=	PLUGINS
PLUGINS_DESC=	Default Client Plugins
OPTIONS_GROUP_PLUGINS=	SASLCLIENT
SASLCLIENT_DESC=	SASL client plugin module
SASLCLIENT_CMAKE_BOOL=	WITH_AUTHENTICATION_LDAP
SASLCLIENT_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASLCLIENT_USES=		ldap

OPTIONS_DEFAULT+=	SASLCLIENT
OPTIONS_SUB=	yes

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/mysql/private
	@${LN} -s libmysqlclient.a ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.a
	@${LN} -s libmysqlclient.so ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so
	@${LN} -s libmysqlclient.so.22 ${STAGEDIR}${PREFIX}/lib/mysql/libmysqlclient_r.so.22

.include "${MASTERDIR}/Makefile"
