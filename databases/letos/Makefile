PORTNAME=	letos
DISTVERSION=	4.0.1
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite database GUI manager
WWW=		https://letos.org/ \
		https://github.com/pawelsalawa/letos

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake compiler:c++20-lang desktop-file-utils gl ncurses qt:6 sqlite
USE_LDCONFIG=	yes
USE_QT=		base declarative svg tools languageserver:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	pawelsalawa

OPTIONS_GROUP=		PLUGINS
OPTIONS_SUB=		yes
PLUGINS_DESC=		Install plugins:

ALL_PLUGINS=	\
	CellRendererImage CsvExport CsvImport DbAndroid DbSQLite3MC \
	ErdEditor FusionDarkStyle HtmlExport JsonExport MultiEditorImage \
	MultiEditorJson PdfExport Printing PythonSyntaxHighlighter RegExpImport \
	ScriptingPython ScriptingTcl SqlEnterpriseFormatter SqlExport SqlFormatterSimple \
	TclSyntaxHighlighter TipOfTheDay XmlExport

.for p in ${ALL_PLUGINS}
P_UPPER=			${p:S/SQLite/Sqlite/:S/3MC/3mc/:C/([A-Z3])/_\1/g:tu}
WITH_PLUGIN_ARGS_OFF+=		-DWITH_${p}=OFF
OPTIONS_GROUP_PLUGINS:=		${OPTIONS_GROUP_PLUGINS} PLUGIN${P_UPPER}
PLUGIN${P_UPPER}_DESC=		${p} plugin
PLUGIN${P_UPPER}_VARS=		WITH_PLUGIN_ARGS_ON+=-DWITH_${p}=ON
.endfor

PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_USES=		python
PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_CXXFLAGS=	-I${PYTHON_INCLUDEDIR}
PLUGIN_PYTHON_SYNTAX_HIGHLIGHTER_BROKEN=	https://github.com/pawelsalawa/sqlitestudio/issues/4995

PLUGIN_SCRIPTING_PYTHON_USES=			python
PLUGIN_SCRIPTING_PYTHON_CXXFLAGS=		-I${PYTHON_INCLUDEDIR}
PLUGIN_SCRIPTING_PYTHON_BROKEN=			https://github.com/pawelsalawa/sqlitestudio/issues/4995

PLUGIN_SCRIPTING_TCL_USES=			tcl:87
PLUGIN_SCRIPTING_TCL_CXXFLAGS=			-I${TCL_INCLUDEDIR}

.for opt in ${OPTIONS_GROUP_PLUGINS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
.endfor

WRKSRC_SUBDIR=	Letos

post-patch:
	@${REINPLACE_CMD} -e 's|pluginDirs += QDir(CFG->getConfigDir()).absoluteFilePath("plugins");|pluginDirs += "${LOCALBASE}/lib/${PORTNAME}";|' \
		${WRKSRC}/core/services/impl/pluginmanagerimpl.cpp

post-build:
	@${ECHO} "===> Building plugins" && \
	${MKDIR} ${WRKSRC}/../Plugins/build && \
	cd ${WRKSRC}/../Plugins/build && \
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} .. -GNinja ${WITH_PLUGIN_ARGS_OFF} ${WITH_PLUGIN_ARGS_ON} && \
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${ALL_TARGET}

post-install:
	@cd ${WRKSRC}/../Plugins/build && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	# add the links to old names for convenience of users
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s letos SQLiteStudio
	@cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s letos sqlitestudio

.include <bsd.port.mk>
