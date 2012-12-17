# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	DB_Table
PORTVERSION=	1.5.6
PORTEPOCH=	1
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR object-oriented interface to a database table

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

LATEST_LINK=	pear-DB_Table
OPTIONS_DEFINE=	PEAR_HTML_QUICKFORM PEAR_DB PEAR_MDB2
PEAR_HTML_QUICKFORM_DESC=	PEAR::HTML_QuickForm support
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

CATEGORY=	DB
FILES=		Table.php Table/Manager/ibase.php Table/Manager/mysql.php \
		Table/Manager/mysqli.php Table/Manager/oci8.php \
		Table/Manager/pgsql.php Table/Manager/sqlite.php \
		Table/Date.php Table/Manager.php Table/QuickForm.php \
		Table/Valid.php \
		Table/Base.php Table/XML.php \
		Table/Generator.php Table/Database.php
DOCS=		_sources.txt all-words.txt mssql-words.txt mysql-words.txt \
		oci8-words.txt pgsql-words.txt sql92-words.txt sql99-words.txt \
		sqlite-words.txt
TESTS=		bogotest.php setup.ini-dist \
		config.php-dist DataTestCase.php \
		database/AutoJoinTest.php database/DatabaseTest.php \
		database/DeleteTest.php database/GetTest.php \
		database/ModifyTest.php database/README \
		database/SelectTest.php database/SerialTest.php \
		database/SQLTest.php database/XMLTest.php \
		database/db1/create.php database/db1/data.php \
		database/db1/define.php database/db1/insert.php \
		database/db1/PersonPhone_Table.php \
		database/ModifyTest/testDeleteCascade1.php \
		database/ModifyTest/testDeleteCascade2.php \
		database/ModifyTest/testDeleteDefault1.php \
		database/ModifyTest/testDeleteDefault2.php \
		database/ModifyTest/testDeleteNullify1.php \
		database/ModifyTest/testDeleteNullify2.php \
		database/ModifyTest/testUpdate.php \
		database/ModifyTest/testUpdateCascade1.php \
		database/ModifyTest/testUpdateCascade2.php \
		database/ModifyTest/testUpdateDefault1.php \
		database/ModifyTest/testUpdateDefault2.php \
		database/ModifyTest/testUpdateNullify1.php \
		database/ModifyTest/testUpdateNullify2.php \
		database/out/AutoJoinTest.out database/out/DeleteTest.out \
		database/out/GetTest.out database/out/ModifyTest.out \
		database/out/SelectTest.out database/out/SerialTest.out \
		database/out/SQLTest.out database/out/XMLTest.out \
		database/SelectTest/testSelect1.php \
		database/SelectTest/testSelect2.php \
		database/SelectTest/testSelect3.php \
		database/SelectTest/testSelectResult1.php \
		database/SelectTest/testSelectResult2.php \
		generator/README generator/test.php

_DOCSDIR=	docs/reserved_words

post-extract:
	@${MV} ${WRKSRC}/DB/* ${WRKSRC}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|" \
		${WRKSRC}/Table.php

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_HTML_QUICKFORM}
RUN_DEPENDS+=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
.endif

.if ${PORT_OPTIONS:MPEAR_DB}
RUN_DEPENDS+=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MPEAR_MDB2}
RUN_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
