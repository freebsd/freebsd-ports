PORTNAME=	qtcreator
DISTVERSION=	7.0.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development

LICENSE=	QtGPL
LICENSE_GROUPS_QtGPL=	GPL
LICENSE_NAME=	GPLv3 with Qt Company GPL Exception 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL3-EXCEPT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libKF5SyntaxHighlighting.so:textproc/kf5-syntax-highlighting \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		compiler:c++14-lang pkgconfig cmake gl python qt:5 shebangfix tar:xz \
		desktop-file-utils
USE_GL=		gl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_QT=		buildtools concurrent core declarative designer gui help \
		linguist location network printsupport qdoc qmake \
		quick3d quickcontrols script serialport sql svg testlib \
		webchannel widgets xml xmlpatterns

# Workaround, KF5-5.94 moved header files to subfolder. Instead of using the bundled
# syntax-highligher, just help it find the proper files.
CFLAGS+=	-I${LOCALBASE}/include/KF5/KSyntaxHighlighting/KSyntaxHighlighting

SHEBANG_FILES=		tests/system/tools/objectsToTable.py \
			tests/system/tools/findUnusedObjects.py \
			share/qtcreator/templates/wizards/files/python/file.py \
			share/qtcreator/scripts/openTerminal.py \
			src/libs/qmljs/parser/changeLicense.py \
			src/libs/qt-breakpad/qtbreakpadsymbols \
			src/tools/icons/export.py \
			scripts/ninjawrapper.py \
			scripts/checkInstalledFiles.py \
			scripts/deployqt.py \
			scripts/dependencyinfo.py \
			scripts/uichanges.py \
			scripts/makedmg.py

# Provide library paths, default llvm first as a hint to the clang code model.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:STRING="${PREFIX}/llvm${LLVM_DEFAULT};${PREFIX}"
# Prevent accidental pickup of devel/elfutils libraries.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_elfutils
# Disable precompiled headers for now, they are missing compile flags.
CMAKE_OFF=	BUILD_WITH_PCH
# Disable Qt6 suport for now
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_Qt6

LDFLAGS+=	-lexecinfo

# be paranoid and do not extract qbs (devel/qbs) copy from source tree
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/src/shared/qbs'

PLIST_SUB=		SHLIB_VER="${PORTVERSION}"
PORTDOCS=		*

OPTIONS_DEFINE=		DOCS EXAMPLES QTWEBENGINE
OPTIONS_DEFAULT=	DOCS EXAMPLES
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_SUB=		yes

DOCS_DESC=		Install the Qt5 api documentation
EXAMPLES_DESC=		Install the Qt5 example projects
QTWEBENGINE_DESC=	Add dependency on qt5-webengine

DOCS_USE=		QT=doc_run
DOCS_CMAKE_BOOL=	WITH_DOCS

EXAMPLES_USE=		QT=examples_run

QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

.include <bsd.port.pre.mk>

# Force a modern LLVM >= 10
.if ${LLVM_DEFAULT:C/[1-5]./&0/:S,-devel,990,} > 80
LLVM_DEFAULT=	13
.endif

# Documentation is excluded from the default build targets.
do-build-DOCS-on:
	${CMAKE_BIN} --build ${BUILD_WRKSRC} --target docs

# This also means separate install steps for documentation.
do-install-DOCS-on:
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX} \
	    --component qch_docs
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX} \
	    --component html_docs

.include <bsd.port.post.mk>
