# New ports collection makefile for:	qt4
# Date created:		2007-01-25
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	qt4
DISTVERSION=	${QT4_VERSION}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework (metaport)

OPTIONS=	CODECS "Enable support for CN, JP, KR, TW" off \
		SQL_PLUGINS "Database connectivity plugins for QtSql" off \
		TOOLS "Install Qt tools (qmake, moc, etc.)" off \
		DEMO "Install demonstration and example programs" off

USE_QT4=	accessible assistant clucene corelib \
		dbus declarative designer doc \
		graphicssystems-opengl gui help \
		iconengines imageformats inputmethods \
		multimedia network opengl phonon phonon-gst \
		qdbusviewer qt3support qtconfig qtestlib qvfb \
		script scripttools sql svg webkit \
		xml xmlpatterns xmlpatterns-tool

NO_BUILD=	yes

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_QT4+=	l10n
.endif

.if defined(WITH_TOOLS)
USE_QT4+=	help-tools linguist makeqpf moc pixeltool \
		porting qmake qmlviewer rcc uic uic3 qdoc3
.endif

.if defined(WITH_CODECS)
USE_QT4+=	codecs-cn codecs-jp codecs-kr codecs-tw
.endif

.if defined(WITH_SQL_PLUGINS)
USE_QT4+=	sql-mysql sql-odbc sql-pgsql sql-sqlite2 sql-sqlite3
.endif

.if defined(WITH_DEMO)
USE_QT4+=	demo
.endif

do-patch:	#empty
	${DO_NADA}

do-install:	#empty
	${DO_NADA}

.include <bsd.port.mk>
