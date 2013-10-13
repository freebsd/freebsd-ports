# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD$

PORTNAME=	qt4
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework (metaport)

USE_QT4=	accessible clucene corelib dbus declarative designer \
		graphicssystems-opengl gui help iconengines \
		imageformats inputmethods multimedia network opengl \
		phonon phonon-gst qt3support qtestlib script \
		scripttools sql svg webkit xml xmlpatterns

NO_BUILD=	yes

OPTIONS_DEFINE=	CODECS DOCS EXAMPLES NLS SQL_PLUGINS TOOLS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

CODECS_DESC=	CN, JP, KR, TW codecs support
SQL_PLUGINS_DESC=	Install database plugins for QtSql
TOOLS_DESC=	Install Qt tools (qmake, moc, etc.)

NO_MTREE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCODECS}
USE_QT4+=	codecs-cn codecs-jp codecs-kr codecs-tw
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_QT4+=	doc
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
USE_QT4+=	demo
.endif

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	l10n
.endif

.if ${PORT_OPTIONS:MSQL_PLUGINS}
USE_QT4+=	sql-ibase sql-mysql sql-odbc sql-pgsql sql-sqlite2 \
		sql-sqlite3
.endif

.if ${PORT_OPTIONS:MTOOLS}
USE_QT4+=	assistant help-tools linguist makeqpf moc pixeltool \
		porting qdbusviewer qdoc3 qmake qmlviewer qtconfig \
		qvfb rcc uic uic3 xmlpatterns-tool
.endif

USE_QT4:=	${USE_QT4:C/$/_run/}

do-patch:
	@${DO_NADA}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
