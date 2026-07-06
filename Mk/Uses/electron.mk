# Provides support for Electron-based ports
#
# Feature:	electron
# Usage:	USES=electron:<version>[,arg,...]
# Valid ARGS:	<version>, build, run, test
#
# <version>:	A major version of Electron the port is based on. The port must
#		specify exactly a single major version.
# build:	Electron is needed at build time. Adds it to BUILD_DEPENDS.
# run:		Electron is needed at run time. Adds it to RUN_DEPENDS.
# test:		Electron is needed at test time. Adds it to TEST_DEPENDS.
#
# NOTE: If the port specifies none of build, run, or test, we assume the port
# requires all those dependencies.
#
# Variables, which may be set by the port:
#
# USE_ELECTRON:	A list of additional features and functionalities to enable.
#		Supported features are:
#
#	appbuilder:	An app-builder version the port uses. Supported
#			arguments are:
#
#		release: The port uses released version of app-builder and add
#			devel/app-builder to BUILD_DEPENDS.
#		devel:	The port uses development version of app-builder and add
#			devel/app-builder-devel to BUILD_DEPENDS.
#
#		NOTE: If the port specifies none of those arguments, we assume
#		release has been specified.
#
#	rebuild:	Rebuilds native node modules against nodejs or electron.
#			Supported arguments are:
#
#		nodejs:	Rebuilds native node modules against the version of
#			nodejs installed before pre-build phase so that nodejs
#			can execute the native modules during build.
#		electron: Rebuilds native node modules against the version of
#			electron the port uses before do-build phase so that
#			the native modules can be executed with electron on run
#			time.
#
#		NOTE: If the port specifies none of those arguments, we assume
#		only electron has been specified.
#
#	build:		Prepares an electron application in a distributable
#			format using the specified package builder as an
#			argument. Supported arguments are:
#
#		builder:	Uses electron-builder for packaging.
#		forge:		Uses electron-forge for packaging.
#		packager:	Uses electron-packager for packaging.
#
#		NOTE: The port must specify exactly a single argument. Multiple
#		package builders cannot be specified.
#
# UPSTREAM_ELECTRON_VER:
# UPSTREAM_CHROMEDRIVER_VER:
# UPSTREAM_MKSNAPSHOT_VER:
#		Electron, chromedriver, and mksnapshot versions the port depends
#		on. Those versions are usually specified in either
#		package-lock.json, yarn.lock, or pnpm-lock.yaml file in the
#		port's source directory.
#
#		The build process tries to automatically detect those versions
#		so the port does not usually have to specify the values.
#		Auto-detection can be overridden by manually specifying the
#		values in Makefile.
#
#		The build process will generate a zip archive and a checksum
#		file of electron/chromedriver/mksnapshot to prevent the build
#		phase from trying to download binary distribution files from
#		GitHub.
#
# ELECTRON_MAKE_FLAGS:
#		Additional command-line flags to pass to the specified package
#		builder when build feature is used. The default flags are
#		defined in this file.
#
# MAINTAINER: tagattie@FreeBSD.org

.if !defined(_INCLUDE_USES_ELECTRON_MK)
_INCLUDE_USES_ELECTRON_MK=	yes

# Electron depends on Node.js package manager
.include "${USESDIR}/npm.mk"

_VALID_ELECTRON_VERSIONS=	37 38 39 40 41 42
_VALID_ELECTRON_FEATURES=	appbuilder rebuild build
_VALID_ELECTRON_FEATURES_APPBUILDER=release devel
_VALID_ELECTRON_FEATURES_REBUILD=nodejs electron
_VALID_ELECTRON_FEATURES_BUILD=	builder forge packager

_ELECTRON_CMD_BASE=	electron
_ELECTRON_PORT_BASE=	devel/electron
_ELECTRON_DOWNLOAD_URL_BASE=	https://github.com/electron/electron/releases/download

# Process USES=electron[:ARGS]
# Detect build, run, test, or env dependency
_ELECTRON_ARGS=		${electron_ARGS:S/,/ /g}
.  if ${_ELECTRON_ARGS:Mbuild}
_ELECTRON_BUILD_DEP=	yes
_ELECTRON_ARGS:=	${_ELECTRON_ARGS:Nbuild}
.  endif
.  if ${_ELECTRON_ARGS:Mrun}
_ELECTRON_RUN_DEP=	yes
_ELECTRON_ARGS:=	${_ELECTRON_ARGS:Nrun}
.  endif
.  if ${_ELECTRON_ARGS:Mtest}
_ELECTRON_TEST_DEP=	yes
_ELECTRON_ARGS:=	${_ELECTRON_ARGS:Ntest}
.  endif
# If no dependencies are specified, assume build, run, and test are required
.  if !defined(_ELECTRON_BUILD_DEP) && !defined(_ELECTRON_RUN_DEP) && \
	!defined(_ELECTRON_TEST_DEP)
_ELECTRON_BUILD_DEP=	yes
_ELECTRON_RUN_DEP=	yes
_ELECTRON_TEST_DEP=	yes
.  endif
# Now _ELECTRON_ARGS should contain a major version of electron
.  if ${_VALID_ELECTRON_VERSIONS:M${_ELECTRON_ARGS}}
_ELECTRON_VERSION=	${_ELECTRON_ARGS}
_ELECTRON_PORTDIR=	${_ELECTRON_PORT_BASE}${_ELECTRON_VERSION}
.	include "${PORTSDIR}/${_ELECTRON_PORTDIR}/Makefile.version"
.  elif empty(_ELECTRON_ARGS)
IGNORE=	does not specify a major version of electron with USES=electron
.  else
IGNORE= specifies unknown USES=electron arguments: ${_ELECTRON_ARGS}
.  endif

# Detect features used with USE_ELECTRON
.  for var in ${USE_ELECTRON}
.    if empty(_VALID_ELECTRON_FEATURES:M${var:C/\:.*//})
_INVALID_ELECTRON_FEATURES+=	${var}
.    endif
.  endfor
.  if !empty(_INVALID_ELECTRON_FEATURES)
IGNORE=	uses unknown USE_ELECTRON features: ${_INVALID_ELECTRON_FEATURES}
.  endif
# Make each individual feature available as _ELECTRON_FEATURE_<FEATURENAME>
.  for var in ${USE_ELECTRON}
_ELECTRON_FEATURE_${var:C/\:.*//:tu}=	${var}
.  endfor

# Process USE_ELECTRON=appbuilder[:ARGS]
# Detect release or devel argument of appbuilder feature
.  if defined(_ELECTRON_FEATURE_APPBUILDER)
_ELECTRON_FEATURE_APPBUILDER:=	${_ELECTRON_FEATURE_APPBUILDER:C/^[^\:]*(\:|\$)//}
.    if ${_ELECTRON_FEATURE_APPBUILDER:Mrelease}
_ELECTRON_FEATURE_APPBUILDER_RELEASE=	yes
_ELECTRON_FEATURE_APPBUILDER:=	${_ELECTRON_FEATURE_APPBUILDER:Nrelease}
.    endif
.    if ${_ELECTRON_FEATURE_APPBUILDER:Mdevel}
_ELECTRON_FEATURE_APPBUILDER_DEVEL=	yes
_ELECTRON_FEATURE_APPBUILDER:=	${_ELECTRON_FEATURE_APPBUILDER:Ndevel}
.    endif
# If no arguments are specified, we assume release is specified
.    if !defined(_ELECTRON_FEATURE_APPBUILDER_RELEASE) && \
           !defined(_ELECTRON_FEATURE_APPBUILDER_DEVEL)
_ELECTRON_FEATURE_APPBUILDER_RELEASE=	yes
.    endif
.    if !empty(_ELECTRON_FEATURE_APPBUILDER)
IGNORE=	specifies unknown USE_ELECTRON=appbuilder arguments: ${_ELECTRON_FEATURE_APPBUILDER}
.    endif
.  endif

# Process USE_ELECTRON=rebuild[:ARGS]
# Detect nodejs or electron argument of rebuild feature
.  if defined(_ELECTRON_FEATURE_REBUILD)
_ELECTRON_FEATURE_REBUILD:=	${_ELECTRON_FEATURE_REBUILD:C/^[^\:]*(\:|\$)//:S/,/ /g}
.    if ${_ELECTRON_FEATURE_REBUILD:Mnodejs}
_ELECTRON_FEATURE_REBUILD_NODEJS=	yes
_ELECTRON_FEATURE_REBUILD:=	${_ELECTRON_FEATURE_REBUILD:Nnodejs}
.    endif
.    if ${_ELECTRON_FEATURE_REBUILD:Melectron}
_ELECTRON_FEATURE_REBUILD_ELECTRON=	yes
_ELECTRON_FEATURE_REBUILD:=	${_ELECTRON_FEATURE_REBUILD:Nelectron}
.    endif
# If no arguments are specified, we assume electron is specified
.    if !defined(_ELECTRON_FEATURE_REBUILD_NODEJS) && \
	   !defined(_ELECTRON_FEATURE_REBUILD_ELECTRON)
_ELECTRON_FEATURE_REBUILD_ELECTRON=	yes
.    endif
.    if !empty(_ELECTRON_FEATURE_REBUILD)
IGNORE=	specifies unknown USE_ELECTRON=rebuild arguments: ${_ELECTRON_FEATURE_REBUILD}
.    endif
.  endif

# Process USE_ELECTRON=build:ARG
# Detect builder used with USE_ELECTRON=builder
.  if defined(_ELECTRON_FEATURE_BUILD)
.    if ${_VALID_ELECTRON_FEATURES_BUILD:M${_ELECTRON_FEATURE_BUILD:C/^[^\:]*(\:|\$)//}}
_ELECTRON_FEATURE_BUILD:=	${_ELECTRON_FEATURE_BUILD:C/^[^\:]*(\:|\$)//}
.    else
IGNORE=	specifies unknown USE_ELECTRON=build arguments: ${_ELECTRON_FEATURE_BUILD}
.    endif
.  endif

# Setup dependencies
.  for stage in BUILD RUN TEST
.    if defined(_ELECTRON_${stage}_DEP)
${stage}_DEPENDS+=	${_ELECTRON_CMD_BASE}${ELECTRON_VER_MAJOR}:${_ELECTRON_PORTDIR}
.    endif
.  endfor
.  if defined(_ELECTRON_FEATURE_APPBUILDER_RELEASE) && ${_ELECTRON_FEATURE_APPBUILDER_RELEASE} == yes
BUILD_DEPENDS+=	app-builder:devel/app-builder
.  elif defined(_ELECTRON_FEATURE_APPBUILDER_DEVEL) && ${_ELECTRON_FEATURE_APPBUILDER_DEVEL} == yes
BUILD_DEPENDS+=	app-builder:devel/app-builder-devel
.  endif

ELECTRON_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}
ELECTRON_REBUILD_WRKSRC_NODEJS?=	${WRKSRC}
ELECTRON_REBUILD_WRKSRC_ELECTRON?=	${WRKSRC}

# Always generate distribution zip files from installed electron package
# directory. This is necessary to prevent the build phase from downloading
# binary distribution files from GitHub.
_USES_build+=	290:electron-generate-electron-zip

BUILD_DEPENDS+=	zip:archivers/zip
.  if ${NPM_NAME} == npm
BUILD_DEPENDS+=	jq:textproc/jq
.  elif ${NPM_NAME} == yarn2 || ${NPM_NAME} == yarn4 || ${NPM_NAME} == pnpm
BUILD_DEPENDS+=	yq:textproc/yq
.  endif

.  if !defined(UPSTREAM_ELECTRON_VER)
.    if ${_NPM_EXISTS_PKGFILE} == yes
.      if ${NPM_NAME} == npm && exists(${LOCALBASE}/bin/jq)
UPSTREAM_ELECTRON_VER!=	jq -r \
				'.packages | \
				to_entries | \
				map(if(.key | test("electron$$")) then .value.version else empty end) | \
				.[]' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif ${NPM_NAME} == yarn1
UPSTREAM_ELECTRON_VER!=	${GREP} -e 'resolved.*/electron/' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${AWK} -F- '{print $$NF}' | \
			${SED} -E 's/\.[a-z]+.*$$//' | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif (${NPM_NAME} == yarn2 || ${NPM_NAME} == yarn4) && exists(${LOCALBASE}/bin/yq)
UPSTREAM_ELECTRON_VER!=	yq -r \
				'. | \
				to_entries | \
				map(if(.key | test("^electron@")) then .value.version else empty end) | \
				.[]' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif ${NPM_NAME} == pnpm && exists(${LOCALBASE}/bin/yq)
UPSTREAM_ELECTRON_VER!=	yq -r \
				'.packages | \
				to_entries | \
				map(if(.key | test("^electron@")) then .key else empty end) | \
				.[]' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${CUT} -f 2 -d '@' | \
			${SORT} -n | \
			${TAIL} -n 1
.      endif
.    endif
.  endif
ELECTRON_DOWNLOAD_URL=		${_ELECTRON_DOWNLOAD_URL_BASE}/v${UPSTREAM_ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	${SHA256} -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_DOWNLOAD_CACHE_DIR=	.cache/electron/${ELECTRON_DOWNLOAD_URL_HASH}

.  if !defined(UPSTREAM_CHROMEDRIVER_VER)
.    if ${_NPM_EXISTS_PKGFILE} == yes
UPSTREAM_CHROMEDRIVER_VER!=	${GREP} -e 'resolved.*/electron-chromedriver/' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
				${HEAD} -n 1 | ${AWK} -F- '{print $$NF}' | ${SED} -E 's/\.[a-z]+.*$$//'
.    endif
.  endif
CHROMEDRIVER_DOWNLOAD_URL=	${_ELECTRON_DOWNLOAD_URL_BASE}/v${UPSTREAM_CHROMEDRIVER_VER}
CHROMEDRIVER_DOWNLOAD_URL_HASH!=${SHA256} -q -s ${CHROMEDRIVER_DOWNLOAD_URL}
CHROMEDRIVER_DOWNLOAD_CACHE_DIR=.cache/electron/${CHROMEDRIVER_DOWNLOAD_URL_HASH}

.  if !defined(UPSTREAM_MKSNAPSHOT_VER)
.    if ${_NPM_EXISTS_PKGFILE} == yes
UPSTREAM_MKSNAPSHOT_VER!=	${GREP} -e 'resolved.*/electron-mksnapshot/' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
				${HEAD} -n 1 | ${AWK} -F- '{print $$NF}' | ${SED} -E 's/\.[a-z]+.*$$//'
.    endif
.  endif
MKSNAPSHOT_DOWNLOAD_URL=	${_ELECTRON_DOWNLOAD_URL_BASE}/v${UPSTREAM_MKSNAPSHOT_VER}
MKSNAPSHOT_DOWNLOAD_URL_HASH!=	${SHA256} -q -s ${MKSNAPSHOT_DOWNLOAD_URL}
MKSNAPSHOT_DOWNLOAD_CACHE_DIR=	.cache/electron/${MKSNAPSHOT_DOWNLOAD_URL_HASH}

electron-generate-electron-zip:
	@if [ -d ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ]; then \
		${ECHO_MSG} "===>  Preparing distribution files of electron/chromedriver/mksnapshot"; \
		${RM} -r ${WRKDIR}/electron-dist; \
		${MKDIR} ${WRKDIR}/electron-dist; \
		${TAR} -cf - -C ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} . | \
			${TAR} -xf - -C ${WRKDIR}/electron-dist; \
		cd ${WRKDIR}/electron-dist && \
		${FIND} . -type f -perm ${BINMODE} -exec ${CHMOD} 755 {} ';'; \
		${MKDIR} ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR}; \
		cd ${WRKDIR}/electron-dist && \
		zip -q -r ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR}/electron-v${UPSTREAM_ELECTRON_VER}-linux-${ELECTRON_ARCH}.zip .; \
		cd ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt-${UPSTREAM_ELECTRON_VER}; \
		cd ${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt; \
	fi
.  if defined(UPSTREAM_CHROMEDRIVER_VER) && !empty(UPSTREAM_CHROMEDRIVER_VER)
	@if [ -d ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ]; then \
		${MKDIR} ${WRKDIR}/${CHROMEDRIVER_DOWNLOAD_CACHE_DIR}; \
		cd ${WRKDIR}/electron-dist && \
		zip -q -r ${WRKDIR}/${CHROMEDRIVER_DOWNLOAD_CACHE_DIR}/chromedriver-v${UPSTREAM_CHROMEDRIVER_VER}-freebsd-${ELECTRON_ARCH}.zip .; \
		cd ${WRKDIR}/${CHROMEDRIVER_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt-${UPSTREAM_CHROMEDRIVER_VER}; \
		cd ${WRKDIR}/${CHROMEDRIVER_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt; \
	fi
.  endif
.  if defined(UPSTREAM_MKSNAPSHOT_VER) && !empty(UPSTREAM_MKSNAPSHOT_VER)
	@if [ -d ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ]; then \
		${MKDIR} ${WRKDIR}/${MKSNAPSHOT_DOWNLOAD_CACHE_DIR}; \
		cd ${WRKDIR}/electron-dist && \
		zip -q -r ${WRKDIR}/${MKSNAPSHOT_DOWNLOAD_CACHE_DIR}/mksnapshot-v${UPSTREAM_MKSNAPSHOT_VER}-freebsd-${ELECTRON_ARCH}.zip .; \
		cd ${WRKDIR}/${MKSNAPSHOT_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt-${UPSTREAM_MKSNAPSHOT_VER}; \
		cd ${WRKDIR}/${MKSNAPSHOT_DOWNLOAD_CACHE_DIR} && \
		${SHA256} -r *.zip | \
			${SED} -e 's/ / */' > SHASUMS256.txt; \
	fi
.  endif

# When rebuild feature is used, rebuilds native node modules against nodejs or
# electron.
.  if defined(_ELECTRON_FEATURE_REBUILD)
_USES_build+=	291:electron-rebuild-native-node-modules-for-node \
		490:electron-rebuild-native-node-modules-for-electron

.    if ${NPM_NAME} == yarn1
# jq is needed for detecting native node modules needing build
BUILD_DEPENDS+=	jq:textproc/jq
# npm is needed for executing "npm rebuild" command
BUILD_DEPENDS+=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
.    endif

electron-rebuild-native-node-modules-for-node:
.    if defined(_ELECTRON_FEATURE_REBUILD_NODEJS) && \
           ${_ELECTRON_FEATURE_REBUILD_NODEJS} == yes
	@${ECHO_MSG} "===>  Rebuilding native node modules for nodejs"
.      if ${NPM_NAME} == yarn1
		@cd ${ELECTRON_REBUILD_WRKSRC_NODEJS} && \
		${SETENV} ${MAKE_ENV} ${NODEJS_REBUILD_ENV} npm rebuild
.      else
		@cd ${ELECTRON_REBUILD_WRKSRC_NODEJS} && \
		${SETENV} ${MAKE_ENV} ${NODEJS_REBUILD_ENV} ${NPM_CMDNAME} rebuild
.      endif
.    else
	@${DO_NADA}
.    endif

electron-rebuild-native-node-modules-for-electron:
.    if defined(_ELECTRON_FEATURE_REBUILD_ELECTRON) && \
       ${_ELECTRON_FEATURE_REBUILD_ELECTRON} == yes
.      if ${NPM_NAME} == pnpm
	@for dir in `app-builder node-dep-tree --dir ${ELECTRON_REBUILD_WRKSRC_ELECTRON} | jq -r '.[] | { dir: .dir, name: .deps[].name } | .dir + "/" + .name'`; do \
		for subdir in `${FIND} $${dir} -type f -name binding.gyp -exec ${DIRNAME} {} ';' 2> /dev/null`; do \
			cd $${subdir} && \
			${ECHO_MSG} "===>  Rebuilding native node modules for electron in $${subdir}" && \
			${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} ${NPM_REBUILD_CMD} ${NPM_REBUILD_FLAGS}; \
		done \
	done
.      else
	@for dir in `app-builder node-dep-tree --dir ${ELECTRON_REBUILD_WRKSRC_ELECTRON} | jq -r '.[] | { dir: .dir, name: .deps[].name } | .dir + "/" + .name'`; do \
		for subdir in `${FIND} $${dir} -type f -name binding.gyp -exec ${DIRNAME} {} ';' 2> /dev/null`; do \
			cd $${subdir} && \
			${ECHO_MSG} "===>  Rebuilding native node modules for electron in $${subdir}" && \
			${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} ${NPM_EXEC_CMD} ${NPM_EXEC_FLAGS} node-gyp rebuild; \
		done \
	done
.      endif
.    else
	@${DO_NADA}
.    endif
.  endif # _ELECTRON_FEATURE_REBUILD

_USES_build+=	499:clean-up-backup-files

clean-up-backup-files:
	@${ECHO_MSG} "===>  Cleaning up backup files in ${WRKSRC}"
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -o -name '*.orig' \) -delete

# When build feature is used, prepares an electron application in a
# distributable format using the specified package builder.
.  if defined(_ELECTRON_FEATURE_BUILD)
ELECTRON_MAKE_FLAGS?=

.    if ${_ELECTRON_FEATURE_BUILD} == builder
ELECTRON_MAKE_CMD?=	${NPM_EXEC_CMD} ${NPM_EXEC_FLAGS} electron-builder
ELECTRON_MAKE_FLAGS+=	--linux \
			--dir \
			--publish never \
			--config.npmRebuild=false \
			--config.electronVersion=${ELECTRON_VER} \
			--config.electronDist=${WRKDIR}/electron-dist
DO_MAKE_BUILD=		${SETENV} ${MAKE_ENV} ${ELECTRON_MAKE_CMD} ${ELECTRON_MAKE_FLAGS}
ELECTRON_BUILDER_APP_OUT_DIR=	linux-${ARCH:S/aarch64/arm64-/:S/amd64//:S/i386/ia32-/}unpacked
.    elif ${_ELECTRON_FEATURE_BUILD} == packager
ELECTRON_MAKE_CMD?=	${NPM_EXEC_CMD} ${NPM_EXEC_FLAGS} electron-packager
ELECTRON_MAKE_FLAGS+=	--platform=linux \
			--no-download \
			--electron-version=${ELECTRON_VER} \
			--electron-zip-dir=${WRKDIR}/${ELECTRON_DOWNLOAD_CACHE_DIR} \
			--prune \
			--overwrite
DO_MAKE_BUILD=		${SETENV} ${MAKE_ENV} ${ELECTRON_MAKE_CMD} . ${ELECTRON_MAKE_FLAGS}
.    elif ${_ELECTRON_FEATURE_BUILD} == forge
ELECTRON_MAKE_CMD?=	${NPM_EXEC_CMD} ${NPM_EXEC_FLAGS} electron-forge package
ELECTRON_MAKE_FLAGS+=	--platform=linux
DO_MAKE_BUILD=		${SETENV} ${MAKE_ENV} ${ELECTRON_MAKE_CMD} ${ELECTRON_MAKE_FLAGS}
.    endif
.    if ${NPM_NAME} == npm || ${NPM_NAME} == yarn1
ELECTRON_MAKE_CMD+=	--
.    endif
ALL_TARGET=	# empty
.  endif

NODEJS_REBUILD_ENV+=	npm_config_nodedir=${LOCALBASE}
ELECTRON_REBUILD_ENV+=	npm_config_runtime=electron
ELECTRON_REBUILD_ENV+=	npm_config_target=${ELECTRON_VER}
ELECTRON_REBUILD_ENV+=	npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers

MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${WRKDIR}/electron-dist
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 	# don't download electron binary distribution
MAKE_ENV+=	PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1	# don't download browser for playwright
MAKE_ENV+=	PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=1	# don't download chromium for puppeteer
MAKE_ENV+=	SASS_FORCE_BUILD=true			# always rebuild native node-sass module
MAKE_ENV+=	USE_SYSTEM_APP_BUILDER=true		# always use system app-builder for electron-builder
MAKE_ENV+=	npm_config_build_from_source=true
SUB_LIST+=	ELECTRON_VER_MAJOR=${ELECTRON_VER_MAJOR}

.endif # _INCLUDE_USES_ELECTRON_MK
