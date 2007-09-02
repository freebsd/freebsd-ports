# New ports collection makefile for:	qt4
# Date created:		2007-01-25
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	qt4
PORTVERSION=	${QT4_VERSION}
PORTREVISION=0
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multiplatform C++ application framework (metaport)

OPTIONS=	SQL_PLUGINS "Database connectivity plugins for QtSql" off

RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/accessible/libqtaccessiblecompatwidgets.so:${PORTSDIR}/accessibility/qt4-accessible \
		${LOCALBASE}/lib/qt4/plugins/codecs/libqcncodecs.so:${PORTSDIR}/chinese/qt4-codecs-cn \
		${LOCALBASE}/lib/qt4/plugins/codecs/libqtwcodecs.so:${PORTSDIR}/chinese/qt4-codecs-tw \
		${LOCALBASE}/lib/libQtSql.so:${PORTSDIR}/databases/qt4-sql \
		qdbus:${PORTSDIR}/devel/dbus-qt4 \
		qdbusviewer:${PORTSDIR}/devel/qt4-qdbusviewer \
		qmake-qt4:${PORTSDIR}/devel/qmake4 \
		assistant-qt4:${PORTSDIR}/devel/qt4-assistant \
		${LOCALBASE}/lib/libQtCore.so:${PORTSDIR}/devel/qt4-corelib \
		designer-qt4:${PORTSDIR}/devel/qt4-designer \
		${LOCALBASE}/lib/libQtAssistantClient.so:${PORTSDIR}/devel/qt4-libqtassistantclient \
		linguist-qt4:${PORTSDIR}/devel/qt4-linguist \
		makeqpf-qt4:${PORTSDIR}/devel/qt4-makeqpf \
		moc-qt4:${PORTSDIR}/devel/qt4-moc \
		qt3to4:${PORTSDIR}/devel/qt4-porting \
		${LOCALBASE}/lib/libQt3Support.so:${PORTSDIR}/devel/qt4-qt3support \
		rcc:${PORTSDIR}/devel/qt4-rcc \
		qvfb-qt4:${PORTSDIR}/devel/qt4-qvfb \
		${LOCALBASE}/lib/libQtScript.so:${PORTSDIR}/devel/qt4-script \
		uic-qt4:${PORTSDIR}/devel/qt4-uic \
		uic3:${PORTSDIR}/devel/qt4-uic3 \
		${LOCALBASE}/lib/libQtTest.so:${PORTSDIR}/devel/qt4-qtestlib \
		${LOCALBASE}/lib/qt4/plugins/imageformats/libqgif.so:${PORTSDIR}/graphics/qt4-imageformats \
		${LOCALBASE}/lib/libQtSvg.so:${PORTSDIR}/graphics/qt4-svg \
		${LOCALBASE}/lib/qt4/plugins/iconengines/libqsvg.so:${PORTSDIR}/graphics/qt4-iconengines \
		pixeltool:${PORTSDIR}/graphics/qt4-pixeltool \
		${LOCALBASE}/lib/qt4/plugins/codecs/libqjpcodecs.so:${PORTSDIR}/japanese/qt4-codecs-jp \
		${LOCALBASE}/lib/qt4/plugins/codecs/libqkrcodecs.so:${PORTSDIR}/korean/qt4-codecs-kr \
		qtconfig-qt4:${PORTSDIR}/misc/qt4-qtconfig \
		${LOCALBASE}/lib/libQtNetwork.so:${PORTSDIR}/net/qt4-network \
		${LOCALBASE}/lib/libQtXml.so:${PORTSDIR}/textproc/qt4-xml \
		${LOCALBASE}/lib/libQtOpenGL.so:${PORTSDIR}/x11/qt4-opengl \
		${LOCALBASE}/lib/qt4/plugins/inputmethods/libqimsw-multi.so:${PORTSDIR}/x11/qt4-inputmethods \
		${LOCALBASE}/lib/libQtGui.so:${PORTSDIR}/x11-toolkits/qt4-gui

NO_BUILD=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../Mk/bsd.qt.mk"

.if defined(WITH_SQL_PLUGINS)
RUN_DEPENDS+=	${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlibase.so:${PORTSDIR}/databases/qt4-ibase-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt4-mysql-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlodbc.so:${PORTSDIR}/databases/qt4-odbc-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt4-pgsql-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlsqlite2.so:${PORTSDIR}/databases/qt4-sqlite-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlsqlite.so:${PORTSDIR}/databases/qt4-sqlite3-plugin
.endif

do-install:	#empty
	${DO_NADA}

.include <bsd.port.post.mk>
