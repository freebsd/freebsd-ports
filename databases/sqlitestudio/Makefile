# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sqlitestudio
PORTVERSION=	3.1.1
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	http://sqlitestudio.pl/files/sqlitestudio3/complete/tar/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite database GUI manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/guiSQLiteStudio/license.txt

OPTIONS_DEFINE=		PLUGIN_CSV_IMPORT PLUGIN_CSV_EXPORT PLUGIN_DB_SQLITE_CIPHER PLUGIN_HTML_EXPORT
OPTIONS_DEFINE+=	PLUGIN_JSON_EXPORT PLUGIN_PDF_EXPORT PLUGIN_PRINTING PLUGIN_REGEXP_IMPORT
OPTIONS_DEFINE+=	PLUGIN_SQL_FORMATTER_SIMPLE PLUGIN_SQL_EXPORT PLUGIN_SQL_ENTERPRISE_FORMATTER
OPTIONS_DEFINE+=	PLUGIN_XML_EXPORT
PLUGIN_CSV_IMPORT_DESC=			Install CsvImport plugin
PLUGIN_CSV_EXPORT_DESC=			Install CsvExport plugin
PLUGIN_DB_SQLITE_CIPHER_DESC=		Install DbSqliteCipher plugin
PLUGIN_HTML_EXPORT_DESC=		Install HtmlExport plugin
PLUGIN_JSON_EXPORT_DESC=		Install JsonExport plugin
PLUGIN_PDF_EXPORT_DESC=			Install PdfExport plugin
PLUGIN_PRINTING_DESC=			Install Printing plugin
PLUGIN_REGEXP_IMPORT_DESC=		Install RegExp plugin
PLUGIN_SQL_FORMATTER_SIMPLE_DESC=	Install SqlFormatterSimple plugin
PLUGIN_SQL_EXPORT_DESC=			Install SqlExport plugin
PLUGIN_SQL_ENTERPRISE_FORMATTER_DESC=	Install SqlEnterpriseFormatter plugin
PLUGIN_XML_EXPORT_DESC=			Install XmlExport plugin

OPTIONS_DEFAULT=	PLUGIN_CSV_IMPORT PLUGIN_CSV_EXPORT PLUGIN_HTML_EXPORT
OPTIONS_DEFAULT+=	PLUGIN_JSON_EXPORT PLUGIN_PDF_EXPORT PLUGIN_PRINTING PLUGIN_REGEXP_IMPORT
OPTIONS_DEFAULT+=	PLUGIN_SQL_FORMATTER_SIMPLE PLUGIN_SQL_EXPORT PLUGIN_SQL_ENTERPRISE_FORMATTER
OPTIONS_DEFAULT+=	PLUGIN_XML_EXPORT
OPTIONS_SUB=		yes

WRKSRC=		${WRKDIR}/SQLiteStudio3

USES=		compiler:c++11-lib gmake ncurses qmake readline sqlite
USE_CXXSTD=	c++11
USE_QT5=	core concurrent gui network script sql sql-sqlite3_run svg widgets xml \
		uitools buildtools_build linguisttools_build
USE_GL=		gl
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${WRKSRC}/coreSQLiteStudio

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' \
		${WRKSRC}/dirs.pri
	@${REINPLACE_CMD} -e 's|pluginDirs += QDir(CFG->getConfigDir()).absoluteFilePath("plugins");|pluginDirs += "${LOCALBASE}/lib/sqlitestudio";|' \
		${WRKSRC}/coreSQLiteStudio/services/impl/pluginmanagerimpl.cpp
	# Patch from http://bugs.sqlitestudio.pl/index.rvt?id=3102
	@${REINPLACE_CMD} -e 's|^include(.*|include($$$$PWD/../../SQLiteStudio3/plugins.pri)|' \
		${WRKDIR}/Plugins/DbSqliteCipher/DbSqliteCipher.pro

PLUGIN_DIRS=
PLUGIN_CSV_IMPORT_VARS=			PLUGIN_DIRS+=CsvImport
PLUGIN_CSV_EXPORT_VARS=			PLUGIN_DIRS+=CsvExport
PLUGIN_DB_SQLITE_CIPHER_USES=		ssl
PLUGIN_DB_SQLITE_CIPHER_VARS=		PLUGIN_DIRS+=DbSqliteCipher
PLUGIN_HTML_EXPORT_VARS=		PLUGIN_DIRS+=HtmlExport
PLUGIN_JSON_EXPORT_VARS=		PLUGIN_DIRS+=JsonExport
PLUGIN_PDF_EXPORT_VARS=			PLUGIN_DIRS+=PdfExport
PLUGIN_PRINTING_VARS=			PLUGIN_DIRS+=Printing USE_QT5+=printsupport
PLUGIN_REGEXP_IMPORT_VARS=		PLUGIN_DIRS+=RegExpImport
PLUGIN_SQL_ENTERPRISE_FORMATTER_VARS=	PLUGIN_DIRS+=SqlEnterpriseFormatter
PLUGIN_SQL_EXPORT_VARS=			PLUGIN_DIRS+=SqlExport
PLUGIN_SQL_FORMATTER_SIMPLE_VARS=	PLUGIN_DIRS+=SqlFormatterSimple
PLUGIN_XML_EXPORT_VARS=			PLUGIN_DIRS+=XmlExport

post-configure:
	# Fix for a suspected bug in qmake: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=210418
	@${REINPLACE_CMD} -E 's|SUBLIBS) -L[^ ]+|SUBLIBS) |' ${WRKSRC}/sqlitestudio/Makefile
	@${REINPLACE_CMD} -E 's|LIBS)$$|LIBS) -L${PREFIX}/lib|' ${WRKSRC}/sqlitestudio/Makefile
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKDIR}/Plugins/$$plugin && \
	  ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${QMAKE_SOURCE_PATH}; \
	done;
post-build:
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKDIR}/Plugins/$$plugin && \
	  ${DO_MAKE_BUILD} ${ALL_TARGET}; \
	done;
post-install:
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKDIR}/Plugins/$$plugin && \
	  ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}; \
	done;

.include <bsd.port.mk>
