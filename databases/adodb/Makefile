# New ports collection makefile for: adodb
# Date created:		4 May 2001
# Whom:			abgoeree@uwnet.nl
#
# $FreeBSD$
#

PORTNAME=	adodb
PORTVERSION=	2.50
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	abgoeree@wish.net

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_DIR=	www/data.default/php/adodb
ADODB_DRIVERS=	${ADODB_DIR}/drivers
ADODB_TESTS=	${ADODB_DIR}/tests
PLIST_SUB=	ADODB_DIR=${ADODB_DIR} \
		ADODB_DRIVERS=${ADODB_DRIVERS} \
		ADODB_TESTS=${ADODB_TESTS} \
		DOCSDIR=share/doc/adodb

DOCS=		readme.htm tute.htm readme.txt

DRIVERS= 	drivers/adodb-access.inc.php \
		drivers/adodb-ado.inc.php \
		drivers/adodb-ado_access.inc.php \
		drivers/adodb-ado_mssql.inc.php \
		drivers/adodb-borland_ibase.inc.php \
		drivers/adodb-csv.inc.php \
		drivers/adodb-db2.inc.php \
		drivers/adodb-fbsql.inc.php \
		drivers/adodb-firebird.inc.php \
		drivers/adodb-ibase.inc.php \
		drivers/adodb-informix.inc.php \
		drivers/adodb-mssql.inc.php \
		drivers/adodb-mysql.inc.php \
		drivers/adodb-mysqlt.inc.php \
		drivers/adodb-oci8.inc.php \
		drivers/adodb-oci8po.inc.php \
		drivers/adodb-odbc.inc.php \
		drivers/adodb-odbc_mssql.inc.php \
		drivers/adodb-odbc_oracle.inc.php \
		drivers/adodb-oracle.inc.php \
		drivers/adodb-postgres.inc.php \
		drivers/adodb-postgres7.inc.php \
		drivers/adodb-proxy.inc.php \
		drivers/adodb-sqlanywhere.inc.php \
		drivers/adodb-sybase.inc.php \
		drivers/adodb-vfp.inc.php \

INCLUDES=	adodb-csvlib.inc.php \
		adodb-errorhandler.inc.php \
		adodb-errorpear.inc.php \
		adodb.inc.php \
		adodb-lib.inc.php \
		adodb-pear.inc.php \
		crypt.inc.php \
		tohtml.inc.php

PICS=		cute_icons_for_site/adodb.gif \
		cute_icons_for_site/adodb.png \
		cute_icons_for_site/adodb2.gif \
		cute_icons_for_site/adodb2.png

SAMPLES=	adodb-cryptsession.php \
		adodb-session.php \
		server.php

TESTS=		tests/benchmark.php \
		tests/client.php \
		tests/test.php \
		tests/test2.php \
		tests/test3.php \
		tests/test4.php \
		tests/test5.php \
		tests/testcache.php \
		tests/testdatabases.inc.php \
		tests/testoci8.php \
		tests/testpaging.php \
		tests/testpear.php \
		tests/testsessions.php

do-install:
	@${MKDIR} ${PREFIX}/${ADODB_DRIVERS}
	@${MKDIR} ${PREFIX}/${ADODB_TESTS}
.for FILE in ${DRIVERS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_DRIVERS}
.endfor
.for FILE in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_DIR}/${FILE}
.endfor
.for FILE in ${PICS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_DIR}
.endfor
.for FILE in ${SAMPLES}
	if [ ! -f ${PREFIX}/${ADODB_DIR}/${FILE} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${FILE} \
		${PREFIX}/${ADODB_DIR}/${FILE};\
	fi
	${INSTALL_DATA} ${WRKSRC}/${FILE} \
		${PREFIX}/${ADODB_DIR}/${FILE}.sample
.endfor
.for FILE in ${TESTS}
	if [ ! -f ${PREFIX}/${ADODB_DIR}/${FILE} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${FILE} \
		${PREFIX}/${ADODB_DIR}/${FILE};\
	fi
	${INSTALL_DATA} ${WRKSRC}/${FILE} \
	${PREFIX}/${ADODB_DIR}/${FILE}.sample
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
