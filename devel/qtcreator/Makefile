# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	qtcreator
DISTVERSION=	3.6.1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

LICENSE=	GPLv3 LGPL21 LGPL3
LICENSE_COMB=	dual

# depend on the split out qbs
BUILD_DEPENDS=	qbs:devel/qbs
RUN_DEPENDS=	qbs:devel/qbs

USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USES=		qmake compiler:c++11-lib
INSTALLS_ICONS=	yes
USE_QT5=	buildtools concurrent core declarative designer gui linguist network\
		qml quick quickcontrols script script sql svg webkit widgets xml\
		xmlpatterns

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

# Fix paths for gnuplot and ant.
post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/gnuplot|${LOCALBASE}/bin/gnuplot|' \
				${WRKSRC}/share/qtcreator/debugger/dumper.py
	${REINPLACE_CMD} -e 's|/usr/bin/ant|${LOCALBASE}/bin/ant|' \
				${WRKSRC}/src/plugins/android/androidsettingswidget.cpp
	${REINPLACE_CMD} -e '/unix:!openbsd: LIBS += -ldl/d' \
				${WRKSRC}/src/libs/sqlite/sqlite-lib.pri

.include <bsd.port.mk>
