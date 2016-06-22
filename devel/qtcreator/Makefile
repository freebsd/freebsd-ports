# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	qtcreator
DISTVERSION=	4.0.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

# depend on the split out qbs
BUILD_DEPENDS=	qbs:devel/qbs
RUN_DEPENDS=	qbs:devel/qbs

USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USES=		qmake compiler:c++11-lib
USE_QT5=	buildtools concurrent core declarative designer gui linguist \
		network qdoc qml quick quickcontrols script script sql svg \
		webkit widgets xml xmlpatterns

# be paranoid and do not extract qbs (devel/qbs) copy from source tree
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/src/shared/qbs'
# Set QBS_INSTALL_DIR for QBS plugin build and set config parameter to build
# the qbsprojectmanager plugin without compile error
QMAKE_ARGS+=	QBS_INSTALL_DIR=${PREFIX} CONFIG+=qbs_enable_project_file_updates

# Enforce installation to ${PREFIX}.
QMAKE_ARGS+=	QTC_PREFIX=${PREFIX}

# Required for building the port with GCC: the define below is required for
# std::to_string() to exist. More details in ports/193528.
QMAKE_ARGS+=	DEFINES+=_GLIBCXX_USE_C99

DESKTOP_ENTRIES="Qt Creator" "" "QtProject-qtcreator" \
		"${PREFIX}/bin/${PORTNAME}" "Development;Qt;" true

OPTIONS_DEFINE=		DOCS EXAMPLES
DOCS_DESC=		Install the Qt5 api documentation
DOCS_USE=		QT5=doc_run
EXAMPLES_DESC=		Install the Qt5 example projects
EXAMPLES_USE=		QT5=examples_run
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

ALL_TARGET=		all
INSTALL_TARGET=		install

DOCS_ALL_TARGET=	docs
DOCS_INSTALL_TARGET=	install_docs

# Fix paths for gnuplot and ant.
post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/gnuplot|${LOCALBASE}/bin/gnuplot|' \
				${WRKSRC}/share/qtcreator/debugger/dumper.py
	${REINPLACE_CMD} -e 's|/usr/bin/ant|${LOCALBASE}/bin/ant|' \
				${WRKSRC}/src/plugins/android/androidsettingswidget.cpp

.include <bsd.port.mk>
