# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	qtcreator
DISTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

# depend on the split out qbs
LIB_DEPENDS=	libqbscore.so:devel/qbs

USES=		qmake compiler:c++11-lib tar:xz
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_GL=		gl
USE_QT5=	buildtools concurrent core designer gui help \
		linguist location network printsupport qdoc qmake qml quick \
		quickcontrols script script sql svg webchannel webengine \
		widgets xml xmlpatterns

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

BROKEN_aarch64=		fails to build: invokes x86 asm

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

PLIST_SUB=		SHLIB_VER="${PORTVERSION}"

.include <bsd.port.pre.mk>
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
# The detection of is_trivially_destructible fails with clang-3.4 from 10.3.
QMAKE_ARGS+=	DEFINES+=TR2_OPTIONAL_DISABLE_EMULATION_OF_TYPE_TRAITS
.endif

# Fix paths for gnuplot and ant.
post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/gnuplot|${LOCALBASE}/bin/gnuplot|' \
				${WRKSRC}/share/qtcreator/debugger/dumper.py
	${REINPLACE_CMD} -e 's|/usr/bin/ant|${LOCALBASE}/bin/ant|' \
				${WRKSRC}/src/plugins/android/androidsettingswidget.cpp

pre-configure:
# We piggyback on QMAKE_LIBDIR_FLAGS to make sure -L${WRKSRC}/lib is passed to
# the linker before -L/usr/local/lib. By default, the opposite happens, which
# is a problem when a Qt port is being upgraded, since an existing library
# would end up being picked up instead of those built in ${WRKSRC}/lib. Since
# qmake appends the value of QMAKE_LIBDIR to QMAKE_LIBDIR_FLAGS, we can use the
# latter to get the linker path order right. qmake is smart enough to strip
# occurrences of ${WRKSRC}/lib from .pc and .prl files when installing them.
# See QTBUG-40825 and ports bugs 194088, 195105 and 198720.
	${ECHO_CMD} 'QMAKE_LIBDIR_FLAGS = -L${WRKSRC}/lib' >> ${WRKSRC}/.qmake.cache

.include <bsd.port.post.mk>
