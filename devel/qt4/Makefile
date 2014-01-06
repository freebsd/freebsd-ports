# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD$

PORTNAME=	qt4
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)

USE_QT4=	accessible clucene corelib dbus declarative designer \
		graphicssystems-opengl gui help iconengines \
		imageformats inputmethods multimedia network opengl \
		phonon qt3support qtestlib script scripttools sql \
		svg webkit xml xmlpatterns

NO_BUILD=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	CODECS DOCS EXAMPLES GSTREAMER NLS SQL_PLUGINS TOOLS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

CODECS_DESC=	CN, JP, KR, TW codecs support
CODECS_USE=	codecs-cn codecs-jp codecs-kr codecs-tw

DOCS_USE=	doc

EXAMPLES_USE=	demo

GSTREAMER_USE=	phonon-gst

NLS_USE=	l10n

SQL_PLUGINS_DESC=	Install database plugins for QtSql
SQL_PLUGINS_USE=sql-ibase sql-mysql sql-odbc sql-pgsql sql-sqlite2 \
		sql-sqlite3

TOOLS_DESC=	Install Qt tools (qmake, moc, etc.)
TOOLS_USE=	assistant help-tools linguist makeqpf moc pixeltool \
		porting qdbusviewer qdoc3 qmake qmlviewer qtconfig \
		qvfb rcc uic uic3 xmlpatterns-tool

.for opt in ${OPTIONS_DEFINE}
${opt}_USE:=	${${opt}_USE:S/^/QT4=/}
.endfor

.include <bsd.port.options.mk>

USE_QT4:=	${USE_QT4:S/$/_run/}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
