# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	sqlitestudio
DISTVERSION=	3.3.0
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite database GUI manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

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

USES=		compiler:c++17-lang gl gmake ncurses qmake qt:5 readline sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	pawelsalawa
USE_QT=		core concurrent gui network script sql sql-sqlite3_run svg widgets xml \
		uitools buildtools_build linguisttools_build
USE_GL=		gl

WRKSRC_SUBDIR=	SQLiteStudio3

CXXFLAGS+=	-I${WRKSRC}/coreSQLiteStudio

DESKTOP_ENTRIES=	"SQLite database manager" \
			"Advanced SQLite database manager" \
			"SQLiteStudio" \
			"SQLiteStudio" \
			"Database;Viewer;DataVisualization;Development;Qt;" \
			""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|' \
		${WRKSRC}/dirs.pri
	@${REINPLACE_CMD} -e 's|pluginDirs += QDir(CFG->getConfigDir()).absoluteFilePath("plugins");|pluginDirs += "${LOCALBASE}/lib/sqlitestudio";|' \
		${WRKSRC}/coreSQLiteStudio/services/impl/pluginmanagerimpl.cpp

post-configure:
	# Fix for a suspected bug in qmake: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=210418
	@${REINPLACE_CMD} -E 's|SUBLIBS) -L[^ ]+|SUBLIBS) |' ${WRKSRC}/sqlitestudio/Makefile
	@${REINPLACE_CMD} -E 's|LIBS)$$|LIBS) -L${PREFIX}/lib|' ${WRKSRC}/sqlitestudio/Makefile
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKSRC}/../Plugins/$$plugin && \
	  ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${QMAKE_SOURCE_PATH}; \
	done;

post-build:
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKSRC}/../Plugins/$$plugin && \
	  ${DO_MAKE_BUILD} ${ALL_TARGET}; \
	done;

post-install:
	@for plugin in ${PLUGIN_DIRS}; do \
	  cd ${WRKSRC}/../Plugins/$$plugin && \
	  ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}; \
	done;
	# install icons for the .desktop file to work
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} \
		${WRKSRC}/guiSQLiteStudio/img/sqlitestudio.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/SQLiteStudio.svg
	# add the lowercase link to the executable for convenience
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s SQLiteStudio sqlitestudio

.include <bsd.port.mk>
