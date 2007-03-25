# New ports collection makefile for:	qt4
# Date created:		2007-01-25
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	qt4
PORTVERSION=	4.2.3
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework (metaport)

OPTIONS=	SQL_PLUGINS "Database connectivity plugins for QtSql" off

RUN_DEPENDS=	${LOCALBASE}/lib/plugins/accessible/libqtaccessiblecompatwidgets.so:${PORTSDIR}/accessibility/qt4-accessible \
		${LOCALBASE}/lib/plugins/codecs/libqcncodecs.so:${PORTSDIR}/chinese/qt4-codecs-cn \
		${LOCALBASE}/lib/plugins/codecs/libqtwcodecs.so:${PORTSDIR}/chinese/qt4-codecs-tw \
		${LOCALBASE}/lib/libQtSql.so:${PORTSDIR}/databases/qt4-sql \
		qdbus:${PORTSDIR}/devel/dbus-qt4 \
		qmake-qt4:${PORTSDIR}/devel/qmake4 \
		${LOCALBASE}/bin/assistant:${PORTSDIR}/devel/qt4-assistant \
		${LOCALBASE}/lib/libQtCore.so:${PORTSDIR}/devel/qt4-corelib \
		${LOCALBASE}/bin/designer:${PORTSDIR}/devel/qt4-designer \
		${LOCALBASE}/lib/libQtAssistantClient.so:${PORTSDIR}/devel/qt4-libqtassistantclient \
		${LOCALBASE}/bin/linguist:${PORTSDIR}/devel/qt4-linguist \
		${LOCALBASE}/bin/moc4:${PORTSDIR}/devel/qt4-moc \
		${LOCALBASE}/bin/qt3to4:${PORTSDIR}/devel/qt4-porting \
		${LOCALBASE}/lib/libQt3Support.so:${PORTSDIR}/devel/qt4-qt3support \
		${LOCALBASE}/bin/rcc:${PORTSDIR}/devel/qt4-rcc \
		${LOCALBASE}/bin/qvfb:${PORTSDIR}/devel/qt4-qvfb \
		${LOCALBASE}/bin/uic4:${PORTSDIR}/devel/qt4-uic \
		${LOCALBASE}/bin/uic3:${PORTSDIR}/devel/qt4-uic3 \
		${LOCALBASE}/lib/libQtTest.so:${PORTSDIR}/devel/qt4-qtestlib \
		${LOCALBASE}/lib/plugins/imageformats/libqgif.so:${PORTSDIR}/graphics/qt4-imageformats \
		${LOCALBASE}/lib/libQtSvg.so:${PORTSDIR}/graphics/qt4-svg \
		${LOCALBASE}/lib/plugins/iconengines/libqsvg.so:${PORTSDIR}/graphics/qt4-iconengines \
		${LOCALBASE}/bin/pixeltool:${PORTSDIR}/graphics/qt4-pixeltool \
		${LOCALBASE}/lib/plugins/codecs/libqjpcodecs.so:${PORTSDIR}/japanese/qt4-codecs-jp \
		${LOCALBASE}/lib/plugins/codecs/libqkrcodecs.so:${PORTSDIR}/korean/qt4-codecs-kr \
		${LOCALBASE}/bin/qtconfig:${PORTSDIR}/misc/qt4-qtconfig \
		${LOCALBASE}/lib/libQtNetwork.so:${PORTSDIR}/net/qt4-network \
		${LOCALBASE}/lib/libQtXml.so:${PORTSDIR}/textproc/qt4-xml \
		${LOCALBASE}/lib/libQtOpenGL.so:${PORTSDIR}/x11/qt4-opengl \
		${LOCALBASE}/lib/plugins/inputmethods/libqimsw-multi.so:${PORTSDIR}/x11/qt4-inputmethods \
		${LOCALBASE}/lib/libQtGui.so:${PORTSDIR}/x11-toolkits/qt4-gui

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_SQL_PLUGINS)
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlibase.so:${PORTSDIR}/databases/qt4-ibase-plugin \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlodbc.so:${PORTSDIR}/databases/qt4-odbc-plugin \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlpgsql.so:${PORTSDIR}/databases/qt4-pgsql-plugin \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlsqlite.so:${PORTSDIR}/databases/qt4-sqlite-plugin \
		${LOCALBASE}/lib/plugins/sqldrivers/libqsqlsqlite3.so:${PORTSDIR}/databases/qt4-sqlite3-plugin
.endif

do-install:	#empty
	${DO_NADA}

.include <bsd.port.post.mk>
