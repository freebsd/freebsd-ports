# New ports collection makefile for: adodb
# Date created:		4 May 2001
# Whom:			abgoeree@uwnet.nl
#
# $FreeBSD$
#

PORTNAME=	adodb
PORTVERSION=	1.65
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	abgoeree@wish.net

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_DIR=	www/data.default/adodb
ADODB_TEST=	share/examples/adodb
PLIST_SUB=	ADODB_DIR=${ADODB_DIR} \
		ADODB_TEST=${ADODB_TEST} \
		DOCSDIR=share/doc/adodb

DOCS=	readme.htm tute.htm readme.txt
LIBS=	adodb-access.inc.php adodb-ado.inc.php adodb-ado_access.inc.php \
	adodb-ado_mssql.inc.php adodb-borland_ibase.inc.php adodb-csv.inc.php \
	adodb-csvlib.inc.php adodb-db2.inc.php adodb-errorhandler.inc.php \
	adodb-errorpear.inc.php adodb-fbsql.inc.php adodb-firebird.inc.php \
	adodb-ibase.inc.php adodb-lib.inc.php adodb-mssql.inc.php \
	adodb-mysql.inc.php adodb-mysqlt.inc.php adodb-oci8.inc.php \
	adodb-oci8po.inc.php adodb-odbc.inc.php adodb-odbc_mssql.inc.php \
	adodb-odbc_oracle.inc.php adodb-oracle.inc.php adodb-pear.inc.php \
	adodb-postgres.inc.php adodb-postgres7.inc.php adodb-proxy.inc.php \
	adodb-sybase.inc.php adodb.inc.php adodb-vfp.inc.php crypt.inc.php \
	tohtml.inc.php
PICS=	adodb.gif adodb.png adodb2.gif adodb2.png
SAMPLES=adodb-cryptsession.php adodb-session.php server.php
TESTS=	benchmark.php client.php test.php test2.php test3.php test4.php \
	test5.php testcache.php testdatabases.inc.php testoci8.php \
	testpaging.php testpear.php testsessions.php

post-patch:
.for FILE in adodb-session.php benchmark.php client.php server.php test.php \
	test2.php test3.php test4.php test5.php testcache.php testoci8.php \
	testpaging.php testpear.php testsessions.php
	${PERL} -pi -e "s#(\./)?(adodb(-session|-pear)?|tohtml)+(\.inc)?\.php#${PREFIX}/${ADODB_DIR}/\2\4\.php#" ${WRKSRC}/${FILE}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/${ADODB_DIR}
.for FILE in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} \
		${PREFIX}/${ADODB_DIR}/${FILE}.sample
.endfor
.for FILE in ${LIBS} ${PICS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_DIR}
.endfor
	@${MKDIR} ${PREFIX}/${ADODB_TEST}
.for FILE in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_TEST}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
