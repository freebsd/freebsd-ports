# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD$

PORTNAME=	qt4
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USE_QT=		accessible clucene corelib dbus declarative designer \
		graphicssystems-opengl gui help iconengines \
		imageformats inputmethods multimedia network opengl \
		phonon qt3support qtestlib script scripttools sql \
		svg webkit xml xmlpatterns
USE_QT:=	${USE_QT:S/$/_run/}
USES=		metaport qt:4

OPTIONS_DEFINE=	CODECS DOCS EXAMPLES GSTREAMER NLS SQL_PLUGINS TOOLS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

CODECS_DESC=	CN, JP, KR, TW codecs support
CODECS_USE=	codecs-cn codecs-jp codecs-kr codecs-tw

DOCS_USE=	doc

EXAMPLES_USE=	demo

GSTREAMER_USE=	phonon-gst

NLS_USE=	l10n

SQL_PLUGINS_DESC=	Install database plugins for QtSql
SQL_PLUGINS_USE=sql-mysql sql-odbc sql-pgsql sql-sqlite2 \
		sql-sqlite3

TOOLS_DESC=	Install Qt tools (qmake, moc, etc.)
TOOLS_USE=	assistant help-tools linguist linguisttools makeqpf \
		moc pixeltool \
		porting qdbusviewer qdoc3 qmake qmlviewer qtconfig \
		qvfb rcc uic uic3 xmlpatterns-tool

.for opt in ${OPTIONS_DEFINE}
${opt}_USE:=	${${opt}_USE:S/^/QT=/:S/$/_run/}
.endfor

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
SQL_PLUGINS_USE+=	sql-ibase
.endif

.include <bsd.port.mk>
