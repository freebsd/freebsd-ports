# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sqlitestudio
PORTVERSION=	3.0.7
CATEGORIES=	databases
MASTER_SITES=	http://sqlitestudio.pl/files/sqlitestudio3/complete/tar/

MAINTAINER=	yuri@rawbw.com
COMMENT=	SQLite database GUI manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/guiSQLiteStudio/license.txt

OPTIONS_DEFINE=		PLUGIN_CSV_IMPORT PLUGIN_CSV_EXPORT PLUGIN_HTML_EXPORT
OPTIONS_DEFINE+=	PLUGIN_PDF_EXPORT PLUGIN_JSON_EXPORT PLUGIN_XML_EXPORT
OPTIONS_DEFINE+=	PLUGIN_SQL_EXPORT PLUGIN_REGEXP_IMPORT
OPTIONS_DEFINE+=	PLUGIN_SQL_FORMATTER_SIMPLE PLUGIN_SQL_ENTERPRISE_FORMATTER
OPTIONS_DEFINE+=	PLUGIN_PRINTING
PLUGIN_CSV_IMPORT_DESC=			Install CsvImport plugin
PLUGIN_CSV_EXPORT_DESC=			Install CsvExport plugin
PLUGIN_HTML_EXPORT_DESC=		Install HtmlExport plugin
PLUGIN_PDF_EXPORT_DESC=			Install PdfExport plugin
PLUGIN_JSON_EXPORT_DESC=		Install JsonExport plugin
PLUGIN_XML_EXPORT_DESC=			Install XmlExport plugin
PLUGIN_SQL_EXPORT_DESC=			Install SqlExport plugin
PLUGIN_REGEXP_IMPORT_DESC=		Install RegExp plugin
PLUGIN_SQL_FORMATTER_SIMPLE_DESC=	Install SqlFormatterSimple plugin
PLUGIN_SQL_ENTERPRISE_FORMATTER_DESC=	Install SqlEnterpriseFormatter plugin
PLUGIN_PRINTING_DESC=			Install Printing plugin
OPTIONS_DEFAULT=	PLUGIN_CSV_IMPORT PLUGIN_CSV_EXPORT PLUGIN_HTML_EXPORT
OPTIONS_DEFAULT+=	PLUGIN_PDF_EXPORT PLUGIN_JSON_EXPORT PLUGIN_XML_EXPORT
OPTIONS_DEFAULT+=	PLUGIN_SQL_EXPORT PLUGIN_REGEXP_IMPORT
OPTIONS_DEFAULT+=	PLUGIN_SQL_FORMATTER_SIMPLE PLUGIN_SQL_ENTERPRISE_FORMATTER
OPTIONS_DEFAULT+=	PLUGIN_PRINTING
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/SQLiteStudio3

USES=		compiler:c++11-lib gmake ncurses qmake sqlite
USE_QT5=	core gui svg sql xml network sql-sqlite3_run widgets script \
		concurrent uitools buildtools_build linguisttools_build
USE_GL=		gl
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && (${COMPILER_VERSION} < 37)
# The reason for clang37 is that previous versions fail to compile with various errors
BUILD_DEPENDS+=	clang37:lang/clang37
CPP=		clang-cpp37
CC=		clang37
CXX=		clang++37
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' \
		${WRKSRC}/dirs.pri
	@${REINPLACE_CMD} -e 's|pluginDirs += QDir(CFG->getConfigDir()).absoluteFilePath("plugins");|pluginDirs += "${LOCALBASE}/lib/sqlitestudio";|' \
		${WRKSRC}/coreSQLiteStudio/services/impl/pluginmanagerimpl.cpp

.include <bsd.port.options.mk>

PLUGIN_DIRS=
.if ${PORT_OPTIONS:MPLUGIN_CSV_IMPORT}
PLUGIN_DIRS     += CsvImport
.endif
.if ${PORT_OPTIONS:MPLUGIN_CSV_EXPORT}
PLUGIN_DIRS     += CsvExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_HTML_EXPORT}
PLUGIN_DIRS     += HtmlExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_PDF_EXPORT}
PLUGIN_DIRS     += PdfExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_JSON_EXPORT}
PLUGIN_DIRS     += JsonExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_XML_EXPORT}
PLUGIN_DIRS     += XmlExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_SQL_EXPORT}
PLUGIN_DIRS     += SqlExport
.endif
.if ${PORT_OPTIONS:MPLUGIN_REGEXP_IMPORT}
PLUGIN_DIRS     += RegExpImport
.endif
.if ${PORT_OPTIONS:MPLUGIN_SQL_FORMATTER_SIMPLE}
PLUGIN_DIRS     += SqlFormatterSimple
.endif
.if ${PORT_OPTIONS:MPLUGIN_SQL_ENTERPRISE_FORMATTER}
PLUGIN_DIRS     += SqlEnterpriseFormatter
.endif
.if ${PORT_OPTIONS:MPLUGIN_PRINTING}
PLUGIN_DIRS     += Printing
USE_QT5+=	printsupport
.endif

post-configure:
.for plugin in ${PLUGIN_DIRS}
	@cd ${WRKDIR}/Plugins/${plugin} && \
		${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${QMAKE_SOURCE_PATH}
.endfor
post-build:
.for plugin in ${PLUGIN_DIRS}
	@cd ${WRKDIR}/Plugins/${plugin} && \
		${DO_MAKE_BUILD} ${ALL_TARGET}
.endfor
post-install:
.for plugin in ${PLUGIN_DIRS}
	@cd ${WRKDIR}/Plugins/${plugin} && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.post.mk>
