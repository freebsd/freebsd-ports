# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	qtcreator
DISTVERSION=	4.11.1
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

# depend on the split out qbs
LIB_DEPENDS=	libqbscore.so:devel/qbs
BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		compiler:c++14-lang gl python qmake qt:5 shebangfix tar:xz
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_GL=		gl
USE_QT=		buildtools concurrent core declarative designer gui help \
		linguist location network printsupport qdoc qmake \
		quickcontrols script script serialport sql svg webchannel \
		widgets xml xmlpatterns

CXXFLAGS_powerpc=	-maltivec
CXXFLAGS_powerpc64=	-maltivec

# be paranoid and do not extract qbs (devel/qbs) copy from source tree
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/src/shared/qbs'
# Set QBS_INSTALL_DIR for QBS plugin build and set config parameter to build
# the qbsprojectmanager plugin without compile error
QMAKE_ARGS+=	QBS_INSTALL_DIR=${PREFIX} CONFIG+=qbs_enable_project_file_updates

# Enforce installation to ${PREFIX}.
QMAKE_ARGS+=	QTC_PREFIX=${PREFIX} LLVM_INSTALL_DIR=${PREFIX}/llvm${LLVM_DEFAULT}

DESKTOP_ENTRIES="Qt Creator" "" "QtProject-qtcreator" \
		"${PREFIX}/bin/${PORTNAME}" "Development;Qt;" true

PORTDOCS=		*

OPTIONS_DEFINE=		DOCS EXAMPLES QTWEBENGINE
OPTIONS_SUB=		yes
DOCS_DESC=		Install the Qt5 api documentation
DOCS_USE=		QT=doc_run
EXAMPLES_DESC=		Install the Qt5 example projects
EXAMPLES_USE=		QT=examples_run
OPTIONS_DEFAULT=	DOCS EXAMPLES
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	QTWEBENGINE

QTWEBENGINE_DESC=	Add dependency on qt5-webengine
QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

ALL_TARGET=		all
INSTALL_TARGET=		install

DOCS_ALL_TARGET=	docs
DOCS_INSTALL_TARGET=	install_docs

PLIST_SUB=		SHLIB_VER="${PORTVERSION}"

SHEBANG_FILES=		tests/system/tools/objectsToTable.py \
			tests/system/tools/findUnusedObjects.py \
			share/qtcreator/templates/wizards/files/python/file.py \
			share/qtcreator/scripts/openTerminal.py \
			src/libs/qmljs/parser/changeLicense.py \
			src/libs/qt-breakpad/qtbreakpadsymbols \
			src/tools/icons/export.py \
			scripts/packagePlugins.py \
			scripts/ninjawrapper.py \
			scripts/checkInstalledFiles.py \
			scripts/generateClangTidyChecks.py \
			scripts/createDistPackage.py \
			scripts/createDevPackage.py \
			scripts/deployqt.py \
			scripts/dependencyinfo.py \
			scripts/createSourcePackages.py \
			scripts/uichanges.py \
			scripts/makedmg.py

.include <bsd.port.pre.mk>

.if ${LLVM_DEFAULT:C/[1-5]./&0/:S,-devel,990,} >= 90
LLVM_DEFAULT=	80
.endif

post-patch:
# Fix paths for gnuplot and ant.
	${REINPLACE_CMD} -e 's|/usr/bin/gnuplot|${LOCALBASE}/bin/gnuplot|' \
				${WRKSRC}/share/qtcreator/debugger/dumper.py
	${REINPLACE_CMD} -e 's|/usr/bin/ant|${LOCALBASE}/bin/ant|' \
				${WRKSRC}/src/plugins/android/androidsettingswidget.cpp
# Fix python binary in pro file.
	${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|g' \
				${WRKSRC}/qtcreator.pro

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
