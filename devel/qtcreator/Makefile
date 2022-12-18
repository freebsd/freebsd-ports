PORTNAME=	qtcreator
DISTVERSION=	8.0.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/qtcreator/${DISTVERSION:R}/${DISTVERSION}
DISTNAME=	qt-creator-opensource-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/qtcreator

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML IDE for Qt development
WWW=		https://qt-project.org/wiki/Category:Tools::QtCreator

LICENSE=	QtGPL
LICENSE_GROUPS_QtGPL=	GPL
LICENSE_NAME=	GPLv3 with Qt Company GPL Exception 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL3-EXCEPT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libKF5SyntaxHighlighting.so:textproc/kf5-syntax-highlighting \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang pkgconfig cmake gl llvm:build,run python qt:5 shebangfix tar:xz \
		desktop-file-utils
USE_GL=		gl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_QT=		buildtools concurrent core declarative designer gui help \
		linguist location network printsupport qdoc qmake \
		quick3d quickcontrols quicktimeline script serialport sql svg testlib \
		webchannel widgets xml xmlpatterns

# Workaround, KF5-5.94 moved header files to subfolder. Instead of using the bundled
# syntax-highligher, just help it find the proper files.
CFLAGS+=	-I${LOCALBASE}/include/KF5/KSyntaxHighlighting/KSyntaxHighlighting

SHEBANG_FILES=		bin/qtcreator.sh \
			doc/fixnavi.pl \
			doc/qtcreatordev/examples/aggregation/test.sh \
			scripts/*.pl \
			scripts/*.py \
			scripts/*.sh \
			share/qtcreator/scripts/openTerminal.py \
			share/qtcreator/translations/check-ts.pl \
			share/qtcreator/translations/*.py \
			src/app/winicons/createicons.sh \
			src/libs/glsl/make-parser.sh \
			src/libs/qmljs/parser/changeLicense.py \
			src/libs/qmljs/parser/gen-parser.sh \
			src/libs/qt-breakpad/qtbreakpadsymbols \
			src/plugins/perfprofiler/tracepoints.sh \
			src/tools/icons/*.sh \
			src/tools/icons/*.py \
			tests/system/tools/findUnusedObjects.py \
			tests/system/tools/objectsToTable.py

# Provide library paths, default llvm first as a hint to the clang code model.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:STRING="${LLVM_PREFIX};${PREFIX}"
# - Prevent accidental pickup of devel/elfutils libraries.
# - Prevent accidental use of devel/googletest headers, use bundled.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_elfutils \
		CMAKE_DISABLE_FIND_PACKAGE_Googletest
# - Disable precompiled headers for now, they are missing compile flags.
# - Suppress installed yaml-cpp, use bundled.
CMAKE_OFF=	BUILD_WITH_PCH \
		yaml-cpp_FOUND
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

DOCS_USE=		QT=doc:run
DOCS_CMAKE_BOOL=	WITH_DOCS

EXAMPLES_USE=		QT=examples:run

QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

.include <bsd.port.pre.mk>

# Force a modern LLVM >= 13
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

# QmlDesigner needs Qt 6.2, remove its data for now.
post-install:
	${RM} -r ${STAGEDIR}${DATADIR}/qmldesigner

.include <bsd.port.post.mk>
