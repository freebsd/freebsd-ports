# This port opens too many files during build, more than the default setting.
# Its build is known to succeed with MAX_FILES_RStudio=4096 in poudriere.conf

PORTNAME=	RStudio
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.09.2+418
PORTREVISION=	1
CATEGORIES=	devel math java
MASTER_SITES=	https://s3.amazonaws.com/rstudio-buildtools/dictionaries/:dictionaries \
		https://rstudio-buildtools.s3.amazonaws.com/rstudio-buildtools/:gin \
		https://rstudio-buildtools.s3.us-east-1.amazonaws.com/gwt/:gwt \
		https://rstudio-buildtools.s3.us-east-1.amazonaws.com/gwt/:mathjax \
		https://github.com/quarto-dev/quarto/archive/:quarto_mono
DISTFILES=	core-dictionaries.zip:dictionaries \
		gin-${GIN_VERSION}.zip:gin \
		gwt-${GWT_VERSION}.tar.gz:gwt \
		mathjax-27.zip:mathjax \
		${QUARTO_MONO_COMMIT}.tar.gz:quarto_mono

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Integrated development environment (IDE) for R
WWW=		https://www.rstudio.com/ \
		https://github.com/rstudio/rstudio

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	fails to resolve 'org.rstudio.studio.client.workbench.views.vcs.common.diff.LineActionButtonRenderer.GrayResources' via deferred binding

BUILD_DEPENDS=	ant:devel/apache-ant \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		node:www/node \
		pandoc:textproc/hs-pandoc \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		${LOCALBASE}/include/gsl/gsl-lite.hpp:devel/gsl-lite \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson \
		${LOCALBASE}/include/websocketpp/version.hpp:devel/websocketpp \
		${LOCALBASE}/include/tl/expected.hpp:devel/tl-expected
LIB_DEPENDS=	libR.so:math/R \
		libboost_thread.so:devel/boost-libs \
		libinotify.so:devel/libinotify \
		libsoci_core.so:databases/soci \
		libuuid.so:misc/libuuid \
		libyaml-cpp.so:devel/yaml-cpp \
		libfmt.so:devel/libfmt \
		libhunspell-1.7.so:textproc/hunspell
BUILD_DEPENDS+=	quarto:textproc/quarto
RUN_DEPENDS=	quarto:textproc/quarto

FLAVORS=	desktop server
FLAVOR?=	${FLAVORS:[1]}
server_PKGNAMESUFFIX=	-server
server_BROKEN=		does not build with the latest RStudio version, needs to be fixed

USES=		cmake fortran java:build localbase:ldflags pgsql pkgconfig sqlite ssl
JAVA_VERSION=	17 # Build requires Java 17 target
USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME:tl}
GH_TUPLE=	rstudio:r2d3:v0.2.0:r2d3/dependencies/common/r2d3 \
		rstudio:rmarkdown:aed26ac:rmarkdown/dependencies/common/rmarkdown \
		rstudio:rsconnect:03c379b:rsconnect/dependencies/common/rsconnect \
		trestletech:plumber:v0.4.6:plumber/dependencies/common/plumber

CMAKE_ARGS=	-DFREEBSD_RSTUDIO_VERSION:STRING=${PORTVERSION} \
		-DFREEBSD_LIBDIR:STRING=${PREFIX}/lib \
		-DRSTUDIO_DEPENDENCIES_QUARTO_DIR:STRING=${LOCALBASE}/share/quarto
CMAKE_ARGS+=	-DQT_QMAKE_EXECUTABLE:STRING=${QMAKE}
CMAKE_ARGS+=	-DRSTUDIO_BOOST_SIGNALS_VERSION=2
CMAKE_ARGS+=	-DFREEBSD_PORT_VERSION:STRING=${DISTVERSION}
CMAKE_ARGS+=	-DFREEBSD_LOCALBASE:STRING=${LOCALBASE} # SOCI package is looked up here, see patch patch-src_cpp_CMakeLists.txt
#CMAKE_ON=	RSTUDIO_USE_SYSTEM_DEPENDENCIES
CMAKE_ON=	RSTUDIO_USE_SYSTEM_YAML_CPP \
		RSTUDIO_USE_SYSTEM_BOOST \
		RSTUDIO_USE_SYSTEM_HUNSPELL \
		RSTUDIO_USE_SYSTEM_SOCI \
		RSTUDIO_USE_SYSTEM_FMT \
		RSTUDIO_USE_SYSTEM_GSL_LITE \
		RSTUDIO_USE_SYSTEM_RAPIDJSON \
		RSTUDIO_USE_SYSTEM_WEBSOCKETPP \
		RSTUDIO_USE_SYSTEM_TL_EXPECTED \
		RSTUDIO_INSTALL_FREEDESKTOP
CMAKE_OFF=	BUILD_TESTING \
		RSTUDIO_UNIT_TESTS_ENABLED
MAKE_ENV=	HOME=${WRKDIR} \
		JAVA_HOME=${JAVA_HOME} \
		PATH=${JAVA_HOME}/bin:${PATH} \
		ANT_OPTS="-Duser.home=${WRKDIR}"
LDFLAGS+=	-lexecinfo

GWT_VERSION=	2.12.2 # GWT_VER in src/gwt/tools/build-gwt
GIN_VERSION=	2.1.2
QUARTO_VERSION=	1.7.32 # Version expected by RStudio for panmirror build
QUARTO_MONO_COMMIT=	591b3520eafbb4da7b26b9f31aac6948801f19d8 # Commit from quarto monorepo with panmirror

.if ${FLAVOR:U} == desktop
COMMENT+=	(desktop UI version)
USES+=		desktop-file-utils shared-mime-info
FETCH_DEPENDS+=	npm:www/npm \
		yarn:www/yarn
BUILD_DEPENDS+=	npm:www/npm \
		yarn:www/yarn \
		electron37:devel/electron37 \
		zip:archivers/zip
RUN_DEPENDS+=	electron37:devel/electron37
CMAKE_ARGS+=	-DRSTUDIO_TARGET=Electron
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		npm_config_nodedir=${WRKDIR}/.electron-headers \
		ELECTRON_ZIP_DIR=${WRKDIR}/.electron-zip
LDFLAGS+=	-linotify
INSTALL_SUBDIR=	${PORTNAME:tl}
EXECUTABLE=	${PORTNAME:tl}
# npm dependencies are pre-fetched during post-fetch phase
NPM_DISTDIR=	${DISTDIR}/${PORTNAME}
NPM_TARBALL=	${PORTNAME}-desktop-node_modules-${DISTVERSION}${EXTRACT_SUFX}
# quarto/panmirror dependencies (uses yarn workspaces)
QUARTO_TARBALL=	${PORTNAME}-quarto-node_modules-${DISTVERSION}${EXTRACT_SUFX}
# Add npm tarballs to DISTFILES for checksum verification
DISTFILES+=	${PORTNAME}/${NPM_TARBALL}:prefetch \
		${PORTNAME}/${QUARTO_TARBALL}:prefetch
.endif

.if ${FLAVOR:U} == server
COMMENT+=	(web UI version)
CMAKE_ARGS+=	-DRSTUDIO_TARGET=Server
LDFLAGS+=	-linotify
INSTALL_SUBDIR=	${PORTNAME:tl}-server
EXECUTABLE=	rserver
USER=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME:tl}-server
.endif

OPTIONS_DEFINE=		COPILOT WITH_QUARTO
OPTIONS_DEFAULT=	COPILOT WITH_QUARTO

COPILOT_DESC=		Build with Copilot support
COPILOT_CMAKE_BOOL=	RSTUDIO_ENABLE_COPILOT
COPILOT_RUN_DEPENDS=	copilot-language-server:misc/github-copilot-language-server

WITH_QUARTO_DESC=	Build with support for Quarto
WITH_QUARTO_CMAKE_BOOL=	QUARTO_ENABLED

# Custom fetch for desktop npm dependencies
.if ${FLAVOR:U} == desktop
post-fetch:
	@if ! [ -f ${NPM_DISTDIR}/${NPM_TARBALL} ]; then \
		${MKDIR} ${NPM_DISTDIR} && \
		${ECHO_MSG} "====> Fetching npm dependencies for desktop..." && \
		${MKDIR} ${WRKDIR}/tmp/rstudio-npm-fetch && \
		${FETCH_CMD} -q "https://raw.githubusercontent.com/rstudio/rstudio/v${DISTVERSION}/src/node/desktop/package.json" -o ${WRKDIR}/tmp/rstudio-npm-fetch/package.json && \
		${FETCH_CMD} -q "https://raw.githubusercontent.com/rstudio/rstudio/v${DISTVERSION}/src/node/desktop/package-lock.json" -o ${WRKDIR}/tmp/rstudio-npm-fetch/package-lock.json && \
		cd ${WRKDIR}/tmp/rstudio-npm-fetch && \
		HOME=${WRKDIR}/tmp/rstudio-npm-fetch npm ci --ignore-scripts && \
		${FIND} node_modules -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; 2>/dev/null; \
		${TAR} -czf ${NPM_DISTDIR}/${NPM_TARBALL} node_modules && \
		${RM} -rf ${WRKDIR}/tmp/rstudio-npm-fetch && \
		${ECHO_MSG} "====> Created npm dependencies tarball ${NPM_DISTDIR}/${NPM_TARBALL}"; \
	fi
	@if ! [ -f ${NPM_DISTDIR}/${QUARTO_TARBALL} ]; then \
		${MKDIR} ${NPM_DISTDIR} && \
		${ECHO_MSG} "====> Fetching quarto/panmirror npm dependencies..." && \
		${MKDIR} ${WRKDIR}/tmp/rstudio-quarto-fetch && \
		cd ${WRKDIR}/tmp/rstudio-quarto-fetch && \
		${FETCH_CMD} -q "https://github.com/quarto-dev/quarto/archive/${QUARTO_MONO_COMMIT}.tar.gz" -o quarto.tar.gz && \
		${TAR} -xzf quarto.tar.gz && \
		cd quarto-${QUARTO_MONO_COMMIT} && \
		HOME=${WRKDIR}/tmp/rstudio-quarto-fetch yarn install --ignore-scripts --network-timeout 240000 && \
		cd apps/panmirror && PANMIRROR_OUTDIR=dist-rstudio yarn build --minify true --sourcemap true && cd ../.. && \
		${FIND} node_modules apps/*/node_modules packages/*/node_modules apps/panmirror/dist-rstudio -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; 2>/dev/null; \
		${TAR} -czf ${NPM_DISTDIR}/${QUARTO_TARBALL} node_modules apps/*/node_modules packages/*/node_modules apps/panmirror/dist-rstudio && \
		${RM} -rf ${WRKDIR}/tmp/rstudio-quarto-fetch && \
		${ECHO_MSG} "====> Created quarto npm dependencies tarball"; \
	fi
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/dependencies/dictionaries && ${MV} ${WRKDIR}/en_* ${WRKSRC}/dependencies/dictionaries/
	@${MV} ${WRKDIR}/mathjax-* ${WRKSRC}/dependencies/
	# GWT libraries go into dependencies/common/gwtproject
	@${MKDIR} ${WRKSRC}/dependencies/common/gwtproject/gwt && ${MV} ${WRKDIR}/gwt/gwt-rstudio ${WRKSRC}/dependencies/common/gwtproject/gwt/
	@${MKDIR} ${WRKSRC}/dependencies/common/gwtproject/gin/${GIN_VERSION}
	@${MV} ${WRKDIR}/gin-${GIN_VERSION}.jar ${WRKSRC}/dependencies/common/gwtproject/gin/${GIN_VERSION}/
	@${MV} ${WRKDIR}/aopalliance.jar ${WRKSRC}/dependencies/common/gwtproject/gin/${GIN_VERSION}/
	@${MV} ${WRKDIR}/guice-*.jar ${WRKSRC}/dependencies/common/gwtproject/gin/${GIN_VERSION}/
	@${MV} ${WRKDIR}/javax.inject.jar ${WRKSRC}/dependencies/common/gwtproject/gin/${GIN_VERSION}/
	# Copy other gwtproject dependencies from extracted gwt tarball
	@${MV} ${WRKDIR}/elemental2 ${WRKSRC}/dependencies/common/gwtproject/
	@${MV} ${WRKDIR}/jsinterop ${WRKSRC}/dependencies/common/gwtproject/
	@${MV} ${WRKDIR}/jspecify ${WRKSRC}/dependencies/common/gwtproject/
	# Setup quarto monorepo for panmirror build
	# Copy entire quarto monorepo structure (needed for yarn workspaces)
	@${MV} ${WRKDIR}/quarto-${QUARTO_MONO_COMMIT} ${WRKSRC}/src/gwt/lib/quarto
	# add hunspell discovery module
	@${CP} ${FILESDIR}/Findhunspell.cmake ${WRKSRC}/cmake/modules
.if ${FLAVOR:U} == desktop
	# Extract pre-fetched npm node_modules for desktop electron build
	@${ECHO_MSG} "====> Extracting pre-fetched npm dependencies..."
	@cd ${WRKSRC}/src/node/desktop && ${TAR} -xzf ${NPM_DISTDIR}/${NPM_TARBALL}
	# Extract pre-fetched quarto/panmirror npm dependencies
	@${ECHO_MSG} "====> Extracting pre-fetched quarto npm dependencies..."
	@cd ${WRKSRC}/src/gwt/lib/quarto && ${TAR} -xzf ${NPM_DISTDIR}/${QUARTO_TARBALL}
	# Patch native modules binding.gyp to support FreeBSD (treat as Linux)
	@${REINPLACE_CMD} "s/'OS==\"linux\"'/'OS==\"linux\" or OS==\"freebsd\"'/" \
		${WRKSRC}/src/node/desktop/node_modules/node-system-fonts/binding.gyp
	# For msgpackr-extract: add FreeBSD support and set compiler to cc
	@${REINPLACE_CMD} -e "s/\"OS=='linux'\"/\"OS=='linux' or OS=='freebsd'\"/" \
		-e 's/"os_linux_compiler%": "gcc"/"os_linux_compiler%": "cc"/' \
		${WRKSRC}/src/node/desktop/node_modules/msgpackr-extract/binding.gyp
.endif

post-patch:
	# quarto node_modules are pre-fetched and extracted
	# Add Java 17+ compatibility args for GWT/Guice reflection
	@${REINPLACE_CMD} -e ' \
		s|</java>|<jvmarg value="-Duser.home=${WRKDIR}"/><jvmarg value="--add-opens=java.base/java.lang=ALL-UNNAMED"/></java>|' \
		${WRKSRC}/src/gwt/build.xml
	@${REINPLACE_CMD} -e ' \
		s|rHomePaths.push_back|//rHomePaths.push_back|; \
		s|//rHomePaths.push_back(FilePath("/usr/local/lib/|rHomePaths.push_back(FilePath("${PREFIX}/lib/|' \
		${WRKSRC}/src/cpp/core/r_util/RVersionsPosix.cpp
	@${REINPLACE_CMD} -e ' \
		s|<condition property="node.bin" value="../../../$${node.dir}/bin/node">|<condition property="node.bin" value="${LOCALBASE}/bin/node">|' \
		${WRKSRC}/src/gwt/build.xml
	# quarto dependency
	${LN} -s ${LOCALBASE}/share/quarto ${WRKSRC}/dependencies/quarto
	# add $PREFIX/bin to PATH for the server daemon
.if ${FLAVOR:U} == server
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/cpp/session/modules/SessionGit.cpp
.endif
	# substitute LOCALBASE for copilot-language-server path
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/cpp/session/include/session/SessionConstants.hpp
	# correct for boost-1.87+ class replacement
	@${FIND} ${WRKSRC} -name "*.cpp" -o -name "*.hpp" | ${XARGS} ${REINPLACE_CMD} -i "" -e 's/io_service/io_context/g'

pre-build:
	#@${CP} ${FILESDIR}/global-setenv.h ${WRKSRC}/src/cpp/desktop/
	#@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/cpp/desktop/global-setenv.h
.if ${FLAVOR:U} == desktop
	# Create proper electron headers structure for node-gyp
	# node-gyp expects common.gypi at root and headers at include/node
	@${MKDIR} ${WRKDIR}/.electron-headers
	@${LN} -sf ${LOCALBASE}/share/electron37/node_headers/include ${WRKDIR}/.electron-headers/include
	@${LN} -sf ${LOCALBASE}/share/electron37/node_headers/include/node/common.gypi ${WRKDIR}/.electron-headers/common.gypi
	# Create electron ZIP for electron-packager (expects electron-v{VERSION}-linux-x64.zip)
	@${MKDIR} ${WRKDIR}/.electron-zip
	@cd ${LOCALBASE}/share/electron37 && zip -rq ${WRKDIR}/.electron-zip/electron-v37.6.1-linux-x64.zip \
		electron chromedriver *.so *.pak *.bin *.json locales resources version LICENSE LICENSES.chromium.html
.endif

post-install:
.if ${FLAVOR:U} == desktop
	# Desktop flavor: create launcher script that uses electron37
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "if ! [ -d /proc/curproc ]; then"; \
	  echo "  echo \"${PORTNAME} needs /proc to be mounted as procfs\" >&2"; \
	  echo "  exit 1"; \
	  echo "fi"; \
	  echo ""; \
	  echo "# Environment setup"; \
	  echo "export LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so"; \
	  echo "export JAVA_HOME=${JAVA_HOME}"; \
	  echo "export ELECTRON_IS_DEV=0"; \
	  echo "export ELECTRON_FORCE_IS_PACKAGED=true"; \
	  echo ""; \
	  echo "exec ${PREFIX}/bin/electron37 ${PREFIX}/resources/app \"\$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
	-${REINPLACE_CMD} -i '' -e 's|^Exec=.*/rstudio|Exec=${PREFIX}/bin/${EXECUTABLE}|' ${STAGEDIR}${PREFIX}/share/applications/${EXECUTABLE}.desktop 2>/dev/null || true
.else
	# Server flavor: create launcher script for rserver
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "if ! [ -d /proc/curproc ]; then"; \
	  echo "  echo \"${PORTNAME} needs /proc to be mounted as procfs\" >&2"; \
	  echo "  exit 1"; \
	  echo "fi"; \
	  echo ""; \
	  echo "# workaround for the problem that RStudio passes /lib with LD_LIBRARY_PATH that causes the /lib/libgcc_s.so.1 conflict with gcc"; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so JAVA_HOME=${JAVA_HOME} ${PREFIX}/lib/${INSTALL_SUBDIR}/bin/${EXECUTABLE} \"\$$@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${EXECUTABLE}
.endif
.if ${FLAVOR:U} == server
	${RM} ${STAGEDIR}${LOCALBASE}/lib/${INSTALL_SUBDIR}/bin/rstudio-server # not compatible with FreeBSD
.endif
	# Remove quarto files since quarto is installed by the quarto port
	${RM} -rf ${STAGEDIR}${PREFIX}/bin/quarto
	# Some functions expect the pandoc symlink.
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${INSTALL_SUBDIR}/bin/pandoc
	@cd ${STAGEDIR}${PREFIX}/lib/${INSTALL_SUBDIR}/bin/pandoc && ${LN} -s ../../../../bin/pandoc
	# There is a variability in .js file names due to use of random numbers, so we use the automatic plist.
	@${SETENV} ${CO_ENV} ${SH} ${SCRIPTSDIR}/check-stagedir.sh makeplist | ${GREP} -v ^\/ | ${SED} -e 's|%%WWWDIR%%|www/rstudio| ; s|%%CMAKE_BUILD_TYPE%%|${CMAKE_BUILD_TYPE:tl}|' > ${TMPPLIST}

DISTINFO_FILE=	${.CURDIR}/distinfo.${FLAVOR}

.include <bsd.port.mk>
