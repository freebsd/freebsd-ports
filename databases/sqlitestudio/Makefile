# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sqlitestudio
DISTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://sqlitestudio.pl/files/sqlitestudio3/complete/tar/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite database GUI manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/coreSQLiteStudio/licenses/sqlitestudio_license.txt

OPTIONS_GROUP=		PLUGINS
OPTIONS_DEFAULT=	${OPTIONS_GROUP_PLUGINS}
OPTIONS_SUB=		yes
PLUGINS_DESC=			Install plugins:

ALL_PLUGINS=		CsvImport CsvExport DbSqliteCipher HtmlExport JsonExport MultiEditorImage PdfExport Printing \
			RegExpImport SqlFormatterSimple SqlExport SqlEnterpriseFormatter XmlExport
.for p in ${ALL_PLUGINS}
OPTIONS_GROUP_PLUGINS+=		PLUGIN${p:C/([A-Z])/_\1/g:tu}
PLUGIN${p:C/([A-Z])/_\1/g:tu}_DESC=		${p} plugin
PLUGIN${p:C/([A-Z])/_\1/g:tu}_VARS=	PLUGIN_DIRS+=${p}
.endfor

PLUGIN_DB_SQLITE_CIPHER_USES=		ssl
PLUGIN_PRINTING_USE=			QT=printsupport

WRKSRC=		${WRKDIR}/SQLiteStudio3

USES=		compiler:c++11-lib gmake ncurses qmake qt:5 readline sqlite
USE_CXXSTD=	c++11
USE_QT=		core concurrent gui network script sql sql-sqlite3_run svg widgets xml \
		uitools buildtools_build linguisttools_build
USE_GL=		gl

CXXFLAGS+=	-I${WRKSRC}/coreSQLiteStudio

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' \
		${WRKSRC}/dirs.pri
	@${REINPLACE_CMD} -e 's|pluginDirs += QDir(CFG->getConfigDir()).absoluteFilePath("plugins");|pluginDirs += "${LOCALBASE}/lib/sqlitestudio";|' \
		${WRKSRC}/coreSQLiteStudio/services/impl/pluginmanagerimpl.cpp
	# Patch from http://bugs.sqlitestudio.pl/index.rvt?id=3102
	@${REINPLACE_CMD} -e 's|^include(.*|include($$$$PWD/../../SQLiteStudio3/plugins.pri)|' \
		${WRKDIR}/Plugins/DbSqliteCipher/DbSqliteCipher.pro

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
