# $FreeBSD$

PORTNAME=	qt5
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)

USE_QT5=	clucene concurrent core dbus declarative designer \
		graphicaleffects gui help imageformats multimedia \
		network opengl printsupport qml quick script \
		scripttools serialport sql svg testlib webkit widgets x11extras \
		xml xmlpatterns

NO_BUILD=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	SQL_PLUGINS TOOLS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

SQL_PLUGINS_DESC=	Install database plugins for QtSql
SQL_PLUGINS_USE=sql-ibase sql-mysql sql-odbc sql-pgsql sql-sqlite2 \
		sql-sqlite3

TOOLS_DESC=	Install Qt tools (qmake, moc, etc.)
TOOLS_USE=	assistant buildtools linguist linguisttools \
		pixeltool qdbus qdbusviewer qdoc qev qmake

.for opt in ${OPTIONS_DEFINE}
${opt}_USE:=	${${opt}_USE:S/^/QT5=/}
.endfor

.include <bsd.port.options.mk>

USE_QT5:=	${USE_QT5:S/$/_run/}

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
