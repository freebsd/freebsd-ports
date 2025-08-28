PORTNAME=	qtcreator
DISTVERSION=	17.0.1
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
LICENSE_FILE=	${WRKSRC}/LICENSES/LICENSE.GPL3-EXCEPT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang desktop-file-utils gl \
		libarchive llvm:build,run,noexport,min=17 pkgconfig \
		python qt:6 shebangfix tar:xz
USE_GL=		gl opengl
USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
USE_QT=		5compat base declarative quick3d quicktimeline serialport \
		shadertools sqldriver-sqlite svg tools translations websockets

SHEBANG_GLOB=	*.pl *.py *.sh
SHEBANG_FILES=	src/plugins/terminal/tests/* \
		src/plugins/terminal/tests/cursor/* \
		tests/manual/distribution/elflint
python_OLD_CMD+="/usr/bin/env python3.10"

# Provide library paths, default llvm first as a hint to the clang code model.
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:STRING="${LLVM_PREFIX};${PREFIX}"
# - Prevent accidental pickup of devel/elfutils libraries.
# - Prevent accidental use of devel/googletest headers, use bundled.
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_elfutils \
		CMAKE_DISABLE_FIND_PACKAGE_Googletest
# - Disable precompiled headers for now, they are missing compile flags.
# - Disable the AppStatisticsPlugin for now, not implemented for FreeBSD.
# - Suppress installed yaml-cpp, use bundled.
CMAKE_OFF=	BUILD_WITH_PCH \
		BUILD_PLUGIN_APPSTATISTICSMONITOR \
		yaml-cpp_FOUND

LDFLAGS+=	-lexecinfo

# be paranoid and do not extract qbs (devel/qbs) copy from source tree
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/src/shared/qbs'

PLIST_SUB=		SHLIB_VER="${PORTVERSION}" \
			SHLIB_SHVER="${PORTVERSION:C/\..*//}"
.if defined(WITH_DEBUG)
PLIST_SUB+=		DEBUG=""
.else
PLIST_SUB+=		DEBUG="@comment "
.endif
PORTDOCS=		*

OPTIONS_DEFINE=		DOCS EXAMPLES LIBSECRET QTWEBENGINE
OPTIONS_DEFAULT=	DOCS EXAMPLES LIBSECRET
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_SUB=		yes

DOCS_DESC=		Install the Qt6 api documentation
EXAMPLES_DESC=		Install the Qt6 example projects
LIBSECRET_DESC=		Libsecret keychain support in qtkeychain
QTWEBENGINE_DESC=	Add dependency on qt6-webengine

DOCS_USE=		QT=doc:run
DOCS_CMAKE_BOOL=	WITH_DOCS

EXAMPLES_USE=		QT=examples:run

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_USES=		gettext-runtime gnome localbase:ldflags
LIBSECRET_USE=		GNOME=glib20
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

QTWEBENGINE_USE=	QT=positioning,webchannel,webengine
QTWEBENGINE_CMAKE_BOOL=	BUILD_HELPVIEWERBACKEND_QTWEBENGINE
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets

# Documentation is excluded from the default build targets.
do-build-DOCS-on:
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		--build ${BUILD_WRKSRC} \
		--target docs

# This also means separate install steps for documentation.
do-install-DOCS-on:
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		--install ${BUILD_WRKSRC} \
		--prefix ${STAGEDIR}${PREFIX} \
		--component qch_docs
	${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		--install ${BUILD_WRKSRC} \
		--prefix ${STAGEDIR}${PREFIX} \
		--component html_docs

.include <bsd.port.mk>
