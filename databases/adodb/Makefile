# New ports collection makefile for: adodb
# Date created:		4 May 2001
# Whom:			abgoeree@uwnet.nl
#
# $FreeBSD$
#

PORTNAME=	adodb
PORTVERSION=	4.50
CATEGORIES=	databases www
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	adodb
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	martin@tradex.sk
COMMENT=	Database library for PHP4

USE_PHP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_DIR=	share/adodb
PLIST_SUB=	ADODB_DIR=${ADODB_DIR}

.if defined(WITH_TESTS)
PLIST_SUB+=	TESTS=
.else
PLIST_SUB+=	TESTS="@comment "
.endif

DOCS=	docs-adodb.htm docs-datadict.htm docs-perf.htm docs-session.htm \
	old-changelog.htm readme.htm tips_portable_sql.htm \
	tute.htm

TXTDOCS=license.txt readme.txt

ICONS=	adodb.gif adodb2.gif

BASE=	adodb-csvlib.inc.php adodb-datadict.inc.php adodb-error.inc.php \
	adodb-errorhandler.inc.php adodb-errorpear.inc.php adodb-exceptions.inc.php \
	adodb-iterator.inc.php adodb-lib.inc.php adodb-pager.inc.php \
	adodb-pear.inc.php adodb-perf.inc.php adodb-php4.inc.php adodb-time.inc.php \
	adodb-time.zip adodb-xmlschema.inc.php adodb.inc.php \
	pivottable.inc.php rsfilter.inc.php server.php toexport.inc.php tohtml.inc.php \
	xmlschema.dtd

CONTRIB=toxmlrpc.inc.php

DATADICT=datadict-access.inc.php datadict-db2.inc.php datadict-firebird.inc.php \
	datadict-generic.inc.php datadict-ibase.inc.php datadict-informix.inc.php \
	datadict-mssql.inc.php datadict-mysql.inc.php datadict-oci8.inc.php \
	datadict-postgres.inc.php datadict-sybase.inc.php

DRIVERS=adodb-access.inc.php adodb-ado.inc.php adodb-ado_access.inc.php \
	adodb-ado_mssql.inc.php adodb-borland_ibase.inc.php adodb-csv.inc.php \
	adodb-db2.inc.php adodb-fbsql.inc.php adodb-firebird.inc.php \
	adodb-ibase.inc.php adodb-informix.inc.php adodb-informix72.inc.php \
	adodb-ldap.inc.php adodb-mssql.inc.php adodb-mssqlpo.inc.php \
	adodb-mysql.inc.php adodb-mysqli.inc.php adodb-mysqlt.inc.php \
	adodb-netezza.inc.php adodb-oci8.inc.php \
	adodb-oci805.inc.php adodb-oci8po.inc.php adodb-odbc.inc.php \
	adodb-odbc_mssql.inc.php \
	adodb-odbc_oracle.inc.php adodb-oracle.inc.php \
	adodb-odbtp.inc.php adodb-odbtp_unicode.inc.php adodb-pdo.inc.php \
	adodb-postgres.inc.php adodb-postgres64.inc.php \
	adodb-postgres7.inc.php \
	adodb-proxy.inc.php adodb-sapdb.inc.php adodb-sqlanywhere.inc.php \
	adodb-sqlite.inc.php adodb-sqlitepo.inc.php adodb-sybase.inc.php \
	adodb-vfp.inc.php adodb-odbtp.inc.php

LANG=	adodb-bg.inc.php adodb-bgutf8.inc.php \
	adodb-ca.inc.php adodb-cn.inc.php adodb-cz.inc.php \
	adodb-de.inc.php adodb-en.inc.php adodb-es.inc.php \
	adodb-fr.inc.php adodb-it.inc.php adodb-nl.inc.php \
	adodb-pl.inc.php adodb-pt-br.inc.php adodb-ro.inc.php \
	adodb-ru1251.inc.php adodb-sv.inc.php

PERF=	perf-db2.inc.php perf-informix.inc.php perf-mssql.inc.php \
	perf-mysql.inc.php perf-oci8.inc.php perf-postgres.inc.php

SESSION=adodb-compress-bzip2.php adodb-compress-gzip.php \
	adodb-cryptsession.php adodb-encrypt-mcrypt.php adodb-encrypt-md5.php \
	adodb-encrypt-secret.php adodb-sess.txt adodb-session-clob.php \
	adodb-session.php adodb-sessions.mysql.sql crypt.inc.php \
	adodb-sessions.oracle.clob.sql adodb-sessions.oracle.sql \
	old/adodb-cryptsession.php old/adodb-session-clob.php \
	old/adodb-session.php old/crypt.inc.php

XSL=	convert-0.1-0.2.xsl convert-0.2-0.1.xsl

TESTS=	benchmark.php client.php test-datadict.php test.php test2.php \
	test3.php test4.php test5.php test_rs_array.php testcache.php \
	testdatabases.inc.php testgenid.php testmssql.php testoci8.php \
	testoci8cursor.php testpaging.php testpear.php testsessions.php \
	time.php tmssql.php xmlschema.xml

do-install:
	@${MKDIR} ${PREFIX}/${ADODB_DIR} ${PREFIX}/${ADODB_DIR}/contrib \
		${PREFIX}/${ADODB_DIR}/datadict ${PREFIX}/${ADODB_DIR}/drivers \
		${PREFIX}/${ADODB_DIR}/lang ${PREFIX}/${ADODB_DIR}/perf \
		${PREFIX}/${ADODB_DIR}/session/old ${PREFIX}/${ADODB_DIR}/xsl
.for FILE in ${BASE}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${ADODB_DIR}/${FILE}
.endfor
.for FILE in ${CONTRIB}
	${INSTALL_DATA} ${WRKSRC}/contrib/${FILE} ${PREFIX}/${ADODB_DIR}/contrib/${FILE}
.endfor
.for FILE in ${DATADICT}
	${INSTALL_DATA} ${WRKSRC}/datadict/${FILE} ${PREFIX}/${ADODB_DIR}/datadict/${FILE}
.endfor
.for FILE in ${DRIVERS}
	${INSTALL_DATA} ${WRKSRC}/drivers/${FILE} ${PREFIX}/${ADODB_DIR}/drivers/${FILE}
.endfor
.for FILE in ${LANG}
	${INSTALL_DATA} ${WRKSRC}/lang/${FILE} ${PREFIX}/${ADODB_DIR}/lang/${FILE}
.endfor
.for FILE in ${PERF}
	${INSTALL_DATA} ${WRKSRC}/perf/${FILE} ${PREFIX}/${ADODB_DIR}/perf/${FILE}
.endfor
.for FILE in ${SESSION}
	${INSTALL_DATA} ${WRKSRC}/session/${FILE} ${PREFIX}/${ADODB_DIR}/session/${FILE}
.endfor
.for FILE in ${XSL}
	${INSTALL_DATA} ${WRKSRC}/xsl/${FILE} ${PREFIX}/${ADODB_DIR}/xsl/${FILE}
.endfor

.if defined(WITH_TESTS)
	@${MKDIR} ${PREFIX}/${ADODB_DIR}/tests
.for FILE in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/tests/${FILE} ${PREFIX}/${ADODB_DIR}/tests
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/cute_icons_for_site
.for FILE in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/docs/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${TXTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${ICONS}
	${INSTALL_MAN} ${WRKSRC}/cute_icons_for_site/${FILE} ${DOCSDIR}/cute_icons_for_site/${FILE}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
