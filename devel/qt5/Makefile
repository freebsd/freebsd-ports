# $FreeBSD$

PORTNAME=	qt5
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)

USE_QT5=	clucene concurrent core dbus declarative designer \
		graphicaleffects gui help imageformats multimedia \
		network opengl paths printsupport qml quick quickcontrols \
		script scripttools serialport sql svg testlib webchannel \
		webkit widgets x11extras xml xmlpatterns
USE_QT5:=	${USE_QT5:S/$/_run/}
USES=		metaport

OPTIONS_DEFINE=	SQL_PLUGINS TOOLS
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

SQL_PLUGINS_DESC=	Install database plugins for QtSql
SQL_PLUGINS_USE=sql-ibase sql-mysql sql-odbc sql-pgsql sql-sqlite2 \
		sql-sqlite3

TOOLS_DESC=	Install Qt tools (qmake, moc, etc.)
TOOLS_USE=	assistant buildtools linguist linguisttools \
		pixeltool qdbus qdbusviewer qdoc qev qmake

.for opt in ${OPTIONS_DEFINE}
${opt}_USE:=	${${opt}_USE:S/^/QT5=/:S/$/_run/}
.endfor

.include <bsd.port.mk>
