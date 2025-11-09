PORTNAME=	sqlitestudio
DISTVERSION=	3.4.17
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite database GUI manager
WWW=		https://sqlitestudio.pl/ \
		https://github.com/pawelsalawa/sqlitestudio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler:c++17-lang gl gmake ncurses qmake qt:5 readline sqlite
USE_LDCONFIG=	yes
USE_QT=		core concurrent declarative gui network script sql sql-sqlite3:run svg widgets xml \
		uitools buildtools:build linguisttools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	pawelsalawa

OPTIONS_GROUP=		PLUGINS
OPTIONS_SUB=		yes
PLUGINS_DESC=			Install plugins:

ALL_PLUGINS=		ConfigMigration CsvExport CsvImport DbAndroid DbSqliteCipher \
			DbSqliteWx FusionDarkStyle HtmlExport JsonExport MultiEditorImage \
			PdfExport Printing PythonSyntaxHighlighter RegExpImport ScriptingPython \
			ScriptingTcl SqlEnterpriseFormatter SqlExport SqlFormatterSimple XmlExport

.for p in ${ALL_PLUGINS}
OPTIONS_GROUP_PLUGINS+=		PLUGIN${p:C/([A-Z])/_\1/g:tu}
PLUGIN${p:C/([A-Z])/_\1/g:tu}_DESC=		${p} plugin
PLUGIN${p:C/([A-Z])/_\1/g:tu}_VARS=	PLUGIN_DIRS+=${p}
.endfor

PLUGIN_DB_SQLITE_CIPHER_USES=			ssl
PLUGIN_PRINTING_USE=				QT=printsupport

PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_USES=		python
PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_CXXFLAGS=	-I${PYTHON_INCLUDEDIR}
PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_BROKEN=	https://github.com/pawelsalawa/sqlitestudio/issues/4995

PLUGIN_SCRIPTING_PYTHON_USES=			python
PLUGIN_SCRIPTING_PYTHON_CXXFLAGS=		-I${PYTHON_INCLUDEDIR}
PLUGIN_SCRIPTING_PYTHON_BROKEN=			https://github.com/pawelsalawa/sqlitestudio/issues/4995

PLUGIN_SCRIPTING_TCL_USES=			tcl:87
PLUGIN_SCRIPTING_TCL_CXXFLAGS=			-I${TCL_INCLUDEDIR}

# workaround for https://github.com/pawelsalawa/sqlitestudio/issues/4999
ARCH!=						uname -p
.if ${ARCH} != "amd64" && ${ARCH} != "i386"
PLUGIN_DB_SQLITE_WX_BROKEN=			Impossible to build on ${ARCH}: it uses SSE SIMD
.endif

.for opt in ${OPTIONS_GROUP_PLUGINS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
.endfor

WRKSRC_SUBDIR=	SQLiteStudio3

CXXFLAGS+=	-I${WRKSRC}/coreSQLiteStudio

DESKTOP_ENTRIES=	"SQLite database manager" \
			"Advanced SQLite database manager" \
			"SQLiteStudio" \
			"SQLiteStudio" \
			"Viewer;DataVisualization;Development;Qt;" \
			""

post-patch:
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
