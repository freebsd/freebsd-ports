# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	qtcreator
DISTVERSION=	3.4.0
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USES=		qmake:outsource compiler:c++11-lib shebangfix
USE_QT5=	buildtools concurrent core declarative designer gui linguist network\
		qml quick quickcontrols script script sql svg webkit widgets xml\
		xmlpatterns

# Enforce installation to ${PREFIX}.
QMAKE_ARGS+=	QTC_PREFIX=${PREFIX}

# Required for building the port with GCC: the define below is required for
# std::to_string() to exist. More details in ports/193528.
QMAKE_ARGS+=	DEFINES+=_GLIBCXX_USE_C99

DESKTOP_ENTRIES="Qt Creator" "" "QtProject-qtcreator" \
		"${PREFIX}/bin/${PORTNAME}" "Development;Qt;" true

# There seems to be only one file needing a shebangfix (all the others
# do not get installed).
SHEBANG_FILES= share/qtcreator/templates/wizards/scriptgeneratedproject/generate.pl

# Fix paths for gnuplot and ant.
post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/gnuplot|${LOCALBASE}/bin/gnuplot|' \
				${WRKSRC}/share/qtcreator/debugger/dumper.py
	${REINPLACE_CMD} -e 's|/usr/bin/ant|${LOCALBASE}/bin/ant|' \
				${WRKSRC}/src/plugins/android/androidsettingswidget.cpp

.include <bsd.port.mk>
