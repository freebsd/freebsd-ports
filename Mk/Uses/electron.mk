# Provides support for Electron-based ports
#
# Feature:	electron
# Usage:	USES=electron:<version>[,ARGS]
# Valid ARGS:	<version>, build, run, test, env
#
# <version>:	A specific major version of Electron the port is based on.
#		The port must specify exactly a single major version.
# build:	Electron is needed at build time. Adds it to BUILD_DEPENDS.
# run:		Electron is needed at run time. Adds it to RUN_DEPENDS.
# test:		Electron is needed at test time. Adds it to TEST_DEPENDS.
# env:		Electron is not needed at any of build, run, or test time.
#		However, the port needs USE_ELECTRON features.
#
# NOTE 1: {build, run, test} and env are mutually exclusive. If the port
# specifies both of them, env takes precedence.
#
# NOTE 2: If the port specifies none of build, run or test, we assume the port
# requires all those dependencies.
#
# Variables, which may be set by the port:
#
# USE_ELECTRON:		A list of additional features and functionalities to
#			enable. Supported features are:
#
#	npm:		A node package manager the port uses.
#			Supported package managers are:
#
#		npm:	The port uses NPM as package manager.
#		yarn1:	The port uses Yarn (v1) as package manager.
#		yarn2:	The port uses Yarn (v2 or v3) as package manager.
#		yarn4:	The port uses Yarn (v4+) as package manager.
#		pnpm:	The port uses PNPM as package manager.
#
#		NOTE: The port must specify exactly a single package manager.
#		Multiple package managers cannot be specified.
#
#		Other valid arguments are:
#
#		fetch, extract, build, run, and test,
#
#		each of which corresponds to respective dependency. If the port
#		does not specify any of those dependencies, we assume only
#		build time dependency is required.
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
#	prefetch:	Downloads node modules the port uses according to the
#			pre-stored package.json (and package-lock.json,
#			yarn.lock, or pnpm-lock.yaml depending on the node
#			package manager used) in PKGJSONSDIR. Downloaded node
#			modules are archived into a single tarball as one of
#			the DISTFILES.
#
#		NOTE 1: If the source directory of the port has other relevant
#		files than package.json and lockfile, the relevant files must
#		also be copied into PKGJSONSDIR. (Examples of relevant files
#		includes .npmrc, .yarnrc, and pnpm-workspace.yaml.)
#
#		NOTE 2: If the source directory of the port contains multiple
#		package.json's and/or lockfiles, all files needed for generating
#		node modules archive must be copied into PKGJSONSDIR with
#		directory hierarchy preserved.
#
#	extract:	Installs the prefetched node modules into the port's
#			working source directory.
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
# NPM_VER:		A version of node package manager the port uses. If yarn
#			2 or later, or pnpm is used for the package manager, the
#			framework requires the variable to be set so that it can
#			bootstrap the correct version of package manager.
#
#			It is usually specified as the key "packageManager" in
#			package.json and the framework tries to automatically
#			detect the version. Auto-detection can be overridden by
#			manually specifying the value in Makefile.
#
# UPSTREAM_ELECTRON_VER:
# UPSTREAM_CHROMEDRIVER_VER:
# UPSTREAM_MKSNAPSHOT_VER:
#			Electron, chromedriver, and mksnapshot versions the port
#			depends on. Those versions are usually specified in
#			either package-lock.json, yarn.lock, or pnpm-lock.yaml
#			file in the port's source directory.
#
#			The build process tries to automatically detect those
#			versions so the port does not usually have to specify
#			the values. Auto-detection can be overridden by manually
#			specifying the values in Makefile.
#
#			The build process will generate a zip archive and a
#			checksum file of electron/chromedriver/mksnapshot to
#			prevent the build phase from trying to download binary
#			distribution files from GitHub.
#
# ELECTRON_MAKE_FLAGS:	Additional command-line flags to pass to the specified
#			package builder when build feature is used. The default
#			flags are defined in this file.
#
# MAINTAINER: tagattie@FreeBSD.org

.if !defined(_INCLUDE_USES_ELECTRON_MK)
_INCLUDE_USES_ELECTRON_MK=	yes

# Electron uses Node.js (actually a node package manager) for build
.include "${USESDIR}/nodejs.mk"

_VALID_ELECTRON_VERSIONS=	36 37 38 39
_VALID_ELECTRON_FEATURES=	npm appbuilder prefetch extract rebuild build
_VALID_ELECTRON_FEATURES_NPM=	npm yarn1 yarn2 yarn4 pnpm
_VALID_ELECTRON_FEATURES_APPBUILDER=release devel
_VALID_ELECTRON_FEATURES_REBUILD=nodejs electron
_VALID_ELECTRON_FEATURES_BUILD=	builder forge packager

_ELECTRON_CMD_BASE=	electron
_ELECTRON_PORT_BASE=	devel/electron
_ELECTRON_DOWNLOAD_URL_BASE=	https://github.com/electron/electron/releases/download
_NODEJS_PKGNAME=	node${NODEJS_VERSION}
_NODEJS_PORT=		www/node${NODEJS_VERSION}

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
.  if ${_ELECTRON_ARGS:Menv}
_ELECTRON_NO_DEP=	yes
_ELECTRON_ARGS:=	${_ELECTRON_ARGS:Nenv}
.  endif
# If no dependencies are specified, assume build, run, and test are required
.  if !defined(_ELECTRON_BUILD_DEP) && !defined(_ELECTRON_RUN_DEP) && \
       !defined(_ELECTRON_TEST_DEP) && !defined(_ELECTRON_NO_DEP)
_ELECTRON_BUILD_DEP=	yes
_ELECTRON_RUN_DEP=	yes
_ELECTRON_TEST_DEP=	yes
.  endif
# Now _ELECTRON_ARGS should contain a single major version unless env is set
.  if !defined(_ELECTRON_NO_DEP)
.    if ${_VALID_ELECTRON_VERSIONS:M${_ELECTRON_ARGS}}
_ELECTRON_VERSION=	${_ELECTRON_ARGS}
_ELECTRON_PORTDIR=	${_ELECTRON_PORT_BASE}${_ELECTRON_VERSION}
.	include "${PORTSDIR}/${_ELECTRON_PORTDIR}/Makefile.version"
.    elif empty(_ELECTRON_ARGS)
IGNORE=	does not specify a major version of electron with USES=electron
.    else
IGNORE= specifies unknown USES=electron arguments: ${_ELECTRON_ARGS}
.    endif
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
.  if !defined(_ELECTRON_FEATURE_NPM)
IGNORE=	does not specify a single node package manager with USE_ELECTRON=npm
.  endif

# Process USE_ELECTRON=npm[:ARGS]
# Detect fetch, extract, build, run, or test dependency
_NODEJS_NPM?=
.  if defined(_ELECTRON_FEATURE_NPM)
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:S/,/ /g}
.    if ${_ELECTRON_FEATURE_NPM:Mfetch}
_ELECTRON_FEATURE_NPM_FETCH=	yes
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:Nfetch}
.    endif
.    if ${_ELECTRON_FEATURE_NPM:Mextract}
_ELECTRON_FEATURE_NPM_EXTRACT=	yes
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:Nextract}
.    endif
.    if ${_ELECTRON_FEATURE_NPM:Mbuild}
_ELECTRON_FEATURE_NPM_BUILD=	yes
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:Nbuild}
.    endif
.    if ${_ELECTRON_FEATURE_NPM:Mrun}
_ELECTRON_FEATURE_NPM_RUN=	yes
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:Nrun}
.    endif
.    if ${_ELECTRON_FEATURE_NPM:Mtest}
_ELECTRON_FEATURE_NPM_TEST=	yes
_ELECTRON_FEATURE_NPM:=		${_ELECTRON_FEATURE_NPM:Ntest}
.    endif
# If no dependencies are specified, we assume only build dep is required
.    if !defined(_ELECTRON_FEATURE_NPM_FETCH) && !defined(_ELECTRON_FEATURE_NPM_EXTRACT) && \
	   !defined(_ELECTRON_FEATURE_NPM_BUILD) && !defined(_ELECTRON_FEATURE_NPM_RUN) && \
	   !defined(_ELECTRON_FEATURE_NPM_TEST)
_ELECTRON_FEATURE_NPM_BUILD=	yes
.    endif
# Now _ELECTRON_FEATURE_NPM should contain a single package manager
.    if ${_VALID_ELECTRON_FEATURES_NPM:M${_ELECTRON_FEATURE_NPM:C/^[^\:]*(\:|\$)//}}
_NODEJS_NPM=		${_ELECTRON_FEATURE_NPM:C/^[^\:]*(\:|\$)//}
.      if ${_NODEJS_NPM} == npm
_NPM_PKGNAME=	${_NODEJS_NPM}${NODEJS_SUFFIX}
_NPM_PORTDIR=	www/${_NODEJS_NPM}${NODEJS_SUFFIX}
.      elif ${_NODEJS_NPM} == yarn1
_NPM_PKGNAME=	yarn${NODEJS_SUFFIX}
_NPM_PORTDIR=	www/yarn${NODEJS_SUFFIX}
.      endif
.    elif empty(_ELECTRON_FEATURES_NPM)
IGNORE=	does not specify a single node package manager with USE_ELECTRON=npm
.    else
IGNORE=	specifies unknown USE_ELECTRON=npm arguments: ${_ELECTRON_FEATURE_NPM}
.    endif
.  endif

# Process USE_ELECTRON=appbuilder[:ARGS]
# Detect stable or devel argument of appbuilder feature
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
.    if defined(_ELECTRON_${stage}_DEP) && ${_ELECTRON_${stage}_DEP} == yes
${stage}_DEPENDS+=	${_ELECTRON_CMD_BASE}${ELECTRON_VER_MAJOR}:${_ELECTRON_PORTDIR}
.    endif
.  endfor
.  for stage in FETCH EXTRACT BUILD RUN TEST
.    if defined(_ELECTRON_FEATURE_NPM_${stage}) && ${_ELECTRON_FEATURE_NPM_${stage}} == yes
.      if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == yarn1
${stage}_DEPENDS+=	${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.      elif ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
${stage}_DEPENDS+=	${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}
.      endif
.    endif
.  endfor
.  if defined(_ELECTRON_FEATURE_APPBUILDER_RELEASE) && ${_ELECTRON_FEATURE_APPBUILDER_RELEASE} == yes
BUILD_DEPENDS+=	app-builder:devel/app-builder
.  elif defined(_ELECTRON_FEATURE_APPBUILDER_DEVEL) && ${_ELECTRON_FEATURE_APPBUILDER_DEVEL} == yes
BUILD_DEPENDS+=	app-builder:devel/app-builder-devel
.  endif

# Define variables related to node package manager
NPM_FETCH_FLAGS?=
NPM_EXTRACT_FLAGS?=
NPM_EXEC_FLAGS?=
NPM_REBUILD_FLAGS?=

NPM_PKGFILE?=		package.json
.  if ${_NODEJS_NPM} == npm
NPM_LOCKFILE?=		package-lock.json
NPM_MODULE_CACHE?=	node_modules
NPM_CMDNAME?=		npm
NPM_CACHE_SETUP_CMD?=	${DO_NADA}
NPM_FETCH_CMD?=		${NPM_CMDNAME} ci
NPM_FETCH_FLAGS+=	--ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
NPM_EXEC_FLAGS+=	--no-update-notifier
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
NPM_REBUILD_FLAGS+=	--no-update-notifier
.  elif ${_NODEJS_NPM:Myarn*}
NPM_LOCKFILE?=		yarn.lock
NPM_MODULE_CACHE?=	yarn-offline-cache
NPM_CMDNAME?=		yarn
NPM_FETCH_CMD?=		${NPM_CMDNAME} install
NPM_EXTRACT_CMD?=	${NPM_CMDNAME} install
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
.    if ${_NODEJS_NPM} == yarn1
NPM_CACHE_SETUP_CMD?=	${ECHO_CMD} 'yarn-offline-mirror "./${NPM_MODULE_CACHE}"' >> .yarnrc
NPM_FETCH_FLAGS+=	--frozen-lockfile --ignore-scripts --silent
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --offline
.    elif ${_NODEJS_NPM} == yarn2
NPM_CACHE_SETUP_CMD?=	${NPM_CMDNAME} config set cacheFolder "./${NPM_MODULE_CACHE}"
NPM_FETCH_FLAGS+=	--immutable --mode=skip-build --silent
NPM_EXTRACT_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableNetwork false; \
			${NPM_CMDNAME} config set enableInlineBuilds true"
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --immutable-cache
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.    elif ${_NODEJS_NPM} == yarn4
NPM_CACHE_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableGlobalCache false; \
			${NPM_CMDNAME} config set cacheFolder \"./${NPM_MODULE_CACHE}\""
NPM_FETCH_FLAGS+=	--immutable --mode=skip-build --silent
NPM_EXTRACT_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableNetwork false; \
			${NPM_CMDNAME} config set enableInlineBuilds true"
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --immutable-cache
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.    endif
.  elif ${_NODEJS_NPM} == pnpm
NPM_LOCKFILE?=		pnpm-lock.yaml
NPM_MODULE_CACHE?=	node_modules
NPM_CMDNAME?=		pnpm
NPM_CACHE_SETUP_CMD?=	${NPM_CMDNAME} set extendNodePath false
NPM_FETCH_CMD?=		${NPM_CMDNAME} install
NPM_FETCH_FLAGS+=	--frozen-lockfile --ignore-scripts --loglevel=error
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.  endif

# Define user-accessible variables
JQ_CMD?=		${LOCALBASE}/bin/jq
YQ_CMD?=		${LOCALBASE}/bin/yq
APP_BUILDER_CMD?=	${LOCALBASE}/bin/app-builder

ELECTRON_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

PKGJSONSDIR?=		${FILESDIR}/packagejsons
NPM_VER?=
NPM_EXTRACT_WRKSRC?=		${WRKSRC}
NPM_REBUILD_WRKSRC_NODEJS?=	${WRKSRC}
NPM_REBUILD_WRKSRC_ELECTRON?=	${WRKSRC}

# Check existence of package.json
_EXISTS_NPM_PKGFILE?=
.  if exists(${PKGJSONSDIR}/${NPM_PKGFILE})
_EXISTS_NPM_PKGFILE=	1
.  endif

# If yarn 2+ or pnpm is used, we need to know the version of node package
# manager. It is usually specified as the key "packageManager", so try to
# automatically detect the version.
.  if ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
.    if ${_EXISTS_NPM_PKGFILE} == 1 && empty(NPM_VER)
NPM_VER!=	${GREP} packageManager ${PKGJSONSDIR}/${NPM_PKGFILE} | \
		${AWK} -F ':' '{print $$NF}' | \
		${SED} -e 's/[",]//g' | \
		${CUT} -f 2 -d '@' | \
		${CUT} -f 1 -d '+'
.    endif
.    if empty(NPM_VER)
IGNORE=	does not specity version of ${NPM_CMDNAME} used for prefetching node modules
.    endif

_USES_fetch+=	490:electron-fetch-node-package-manager

DISTFILES+=	${NPM_CMDNAME}-${NPM_VER}.tgz:prefetch
FETCH_DEPENDS+=	${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}

electron-fetch-node-package-manager:
	@${ECHO_MSG} "===>  Fetching and setting up ${NPM_CMDNAME} version ${NPM_VER}"
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR} ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack enable --install-directory ${WRKDIR}/.bin
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz ]; then \
		cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} corepack pack ${NPM_CMDNAME}@${NPM_VER} && \
		${TAR} -xzf corepack.tgz && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/electron-create-mtree.sh ${NPM_CMDNAME} > \
			${NPM_CMDNAME}.mtree && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz @${NPM_CMDNAME}.mtree; \
	fi
	@${SETENV} ${MAKE_ENV} corepack install -g ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz
.  endif

# When prefetch feature is used, downloads node modules the port uses according
# to the pre-stored package.json.
.  if defined(_ELECTRON_FEATURE_PREFETCH)
.    if empty(_EXISTS_NPM_PKGFILE)
IGNORE=	does not store ${NPM_PKGFILE} in ${PKGJSONSDIR} for prefetching node modules
.    endif

_USES_fetch+=	491:electron-fetch-node-modules \
		492:electron-archive-node-modules

_DISTFILE_prefetch=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-node-modules${EXTRACT_SUFX}
DISTFILES+=		${_DISTFILE_prefetch}:prefetch

.    if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == yarn1
FETCH_DEPENDS+= ${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.    elif ${_NODEJS_NPM} == pnpm
FETCH_DEPENDS+=	${YQ_CMD}:textproc/yq
.    endif

electron-fetch-node-modules:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} ]; then \
		${ECHO_MSG} "===>  Setting up node modules cache directory"; \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${TAR} -cf - -C ${PKGJSONSDIR} . | ${TAR} -xf - -C ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && ${SETENV} ${MAKE_ENV} ${NPM_CACHE_SETUP_CMD}; \
		${ECHO_MSG} "===>  Prefetching node modules"; \
		for dir in `${FIND} ${WRKDIR}/node-modules-cache -type f -name ${NPM_LOCKFILE} -exec ${DIRNAME} {} ';'`; do \
			cd $${dir} && \
			${SETENV} ${MAKE_ENV} ${NPM_FETCH_CMD} ${NPM_FETCH_FLAGS}; \
			${RM} $${dir}/${NPM_MODULE_CACHE}/.gitignore; \
			if [ -f $${dir}/${NPM_MODULE_CACHE}/.modules.yaml ]; then \
				${YQ_CMD} -yi 'del(.prunedAt, .storeDir)' \
					$${dir}/${NPM_MODULE_CACHE}/.modules.yaml; \
			fi; \
			${RM} $${dir}/${NPM_MODULE_CACHE}/.pnpm-workspace-state*.json; \
		done; \
	fi

electron-archive-node-modules:
.    if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == pnpm
	@if [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Archiving prefetched node modules"; \
		for dir in `${FIND} -s ${WRKDIR}/node-modules-cache -type d -name ${NPM_MODULE_CACHE} -print | \
			${GREP} -ve '${NPM_MODULE_CACHE}/.*/${NPM_MODULE_CACHE}'`; do \
			${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
				${SH} ${SCRIPTSDIR}/electron-create-mtree.sh $${dir} >> \
				${WRKDIR}/node-modules-cache.mtree; \
		done; \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} \
			-C ${WRKDIR} @node-modules-cache.mtree; \
		if [ ${TMPDIR} != ${WRKDIR} ]; then \
			${RM} -r ${WRKDIR}; \
		fi; \
	fi
.    elif ${_NODEJS_NPM:Myarn*}
	@if [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Archiving prefetched node modules"; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/electron-create-mtree.sh ${NPM_MODULE_CACHE} > \
			node-modules-cache.mtree && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
			${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} @node-modules-cache.mtree; \
		if [ ${TMPDIR} != ${WRKDIR} ]; then \
			${RM} -r ${WRKDIR}; \
		fi; \
	fi
.    endif
.  endif # _FEATURE_ELECTRON_PREFETCH

# When extract feature is used, installs the prefetched node modules into the
# port's working source directory.
.  if defined(_ELECTRON_FEATURE_EXTRACT)
_USES_extract+=	600:electron-extract-node-package-manager \
		601:electron-copy-package-file \
		602:electron-install-node-modules

.    if ${_NODEJS_NPM} == yarn1
EXTRACT_DEPENDS+= ${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.    elif ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
EXTRACT_DEPENDS+= ${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}
.    endif

electron-extract-node-package-manager:
.    if ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
	@${ECHO_MSG} "===>  Setting up ${NPM_CMDNAME} version ${NPM_VER}"
	@${MKDIR}  ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack enable --install-directory ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack install -g ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz
.    else
	@${DO_NADA}
.    endif

electron-copy-package-file:
.    if ${_EXISTS_NPM_PKGFILE} == 1
	@${ECHO_MSG} "===>  Copying ${NPM_PKGFILE} and ${NPM_LOCKFILE} to ${NPM_EXTRACT_WRKSRC}"
	@for f in `${FIND} ${PKGJSONSDIR} -type f \( -name ${NPM_PKGFILE} -o -name ${NPM_LOCKFILE} \) -print | ${SED} -e 's|${PKGJSONSDIR}/||'`; do \
		${MKDIR} -p `${DIRNAME} ${NPM_EXTRACT_WRKSRC}/$${f}`; \
		if [ -f ${NPM_EXTRACT_WRKSRC}/$${f} ]; then \
			${MV} -f ${NPM_EXTRACT_WRKSRC}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}.bak; \
		fi; \
		${CP} ${PKGJSONSDIR}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}; \
	done
.    endif

electron-install-node-modules:
.    if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == pnpm
	@${ECHO_MSG} "===>  Moving prefetched node modules to ${NPM_EXTRACT_WRKSRC}"
	@if [ -d ${EXTRACT_WRKDIR}/node-modules-cache ]; then \
		for dir in `${FIND} -s ${EXTRACT_WRKDIR}/node-modules-cache -type d -name ${NPM_MODULE_CACHE} -print | \
			${GREP} -ve '${NPM_MODULE_CACHE}/.*/${NPM_MODULE_CACHE}'`; do \
			${MV} $${dir} `${ECHO_CMD} $${dir} | sed -e 's|${EXTRACT_WRKDIR}/node-modules-cache|${NPM_EXTRACT_WRKSRC}|'`; \
		done; \
	fi
.    elif ${_NODEJS_NPM:Myarn*}
	@${ECHO_MSG} "===>  Installing node modules from prefetched cache"
	@if [ -d ${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE} ]; then \
		${MV} ${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE} ${NPM_EXTRACT_WRKSRC}; \
	fi
	@cd ${NPM_EXTRACT_WRKSRC} && ${SETENV} ${MAKE_ENV} ${NPM_CACHE_SETUP_CMD}
.      if defined(NPM_EXTRACT_SETUP_CMD) && !empty(NPM_EXTRACT_SETUP_CMD)
	@${ECHO_MSG} "===>  Setting up ${NPM_CMDNAME} command options"
	@cd ${NPM_EXTRACT_WRKSRC} && ${SETENV} ${MAKE_ENV} ${NPM_EXTRACT_SETUP_CMD}
.      endif
	@if [ -d ${PKGJSONSDIR} ]; then \
		cd ${PKGJSONSDIR} && \
		for dir in `${FIND} . -type f -name ${NPM_LOCKFILE} -exec ${DIRNAME} {} ';'`; do \
			cd ${NPM_EXTRACT_WRKSRC}/$${dir} && \
			${SETENV} ${MAKE_ENV} ${NPM_EXTRACT_CMD} ${NPM_EXTRACT_FLAGS}; \
		done; \
	else \
		cd ${NPM_EXTRACT_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${NPM_EXTRACT_CMD} ${NPM_EXTRACT_FLAGS}; \
	fi
.    endif
.  endif # _ELECTRON_FEATURE_EXTRACT

# Always generate distribution zip files from installed electron package
# directory. This is necessary to prevent the build phase from downloading
# binary distribution files from GitHub.
_USES_build+=	290:electron-generate-electron-zip

BUILD_DEPENDS+=	zip:archivers/zip
.  if ${_NODEJS_NPM} == npm
BUILD_DEPENDS+=	${JQ_CMD}:textproc/jq
.  elif ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
BUILD_DEPENDS+=	${YQ_CMD}:textproc/yq
.  endif

.  if !defined(UPSTREAM_ELECTRON_VER)
.    if ${_EXISTS_NPM_PKGFILE} == 1
.      if ${_NODEJS_NPM} == npm && exists(${JQ_CMD})
UPSTREAM_ELECTRON_VER!=	${JQ_CMD} -r \
				'.packages | \
				to_entries | \
				map(if(.key | test("electron$$")) then .value.version else empty end) | \
				.[]' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif ${_NODEJS_NPM} == yarn1
UPSTREAM_ELECTRON_VER!=	${GREP} -e 'resolved.*/electron/' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${AWK} -F- '{print $$NF}' | \
			${SED} -E 's/\.[a-z]+.*$$//' | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif (${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4) && exists(${YQ_CMD})
UPSTREAM_ELECTRON_VER!=	${YQ_CMD} -r \
				'. | \
				to_entries | \
				map(if(.key | test("^electron@")) then .value.version else empty end) | \
				.[]' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
			${SORT} -n | \
			${TAIL} -n 1
.      elif ${_NODEJS_NPM} == pnpm && exists(${YQ_CMD})
UPSTREAM_ELECTRON_VER!=	${YQ_CMD} -r \
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
.    if ${_EXISTS_NPM_PKGFILE} == 1
UPSTREAM_CHROMEDRIVER_VER!=	${GREP} -e 'resolved.*/electron-chromedriver/' ${PKGJSONSDIR}/${NPM_LOCKFILE} | \
				${HEAD} -n 1 | ${AWK} -F- '{print $$NF}' | ${SED} -E 's/\.[a-z]+.*$$//'
.    endif
.  endif
CHROMEDRIVER_DOWNLOAD_URL=	${_ELECTRON_DOWNLOAD_URL_BASE}/v${UPSTREAM_CHROMEDRIVER_VER}
CHROMEDRIVER_DOWNLOAD_URL_HASH!=${SHA256} -q -s ${CHROMEDRIVER_DOWNLOAD_URL}
CHROMEDRIVER_DOWNLOAD_CACHE_DIR=.cache/electron/${CHROMEDRIVER_DOWNLOAD_URL_HASH}

.  if !defined(UPSTREAM_MKSNAPSHOT_VER)
.    if ${_EXISTS_NPM_PKGFILE} == 1
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

.    if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == yarn1
BUILD_DEPENDS+= ${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.    elif ${_NODEJS_NPM} == yarn2 || ${_NODEJS_NPM} == yarn4 || ${_NODEJS_NPM} == pnpm
BUILD_DEPENDS+=	${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}
.    endif
.    if ${_NODEJS_NPM} == yarn1
# jq is needed for detecting native node modules needing build
BUILD_DEPENDS+=	${JQ_CMD}:textproc/jq
# npm is needed for executing "npm rebuild" command
BUILD_DEPENDS+=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
.    endif

electron-rebuild-native-node-modules-for-node:
.    if defined(_ELECTRON_FEATURE_REBUILD_NODEJS) && \
           ${_ELECTRON_FEATURE_REBUILD_NODEJS} == yes
	@${ECHO_MSG} "===>  Rebuilding native node modules for nodejs"
.      if ${_NODEJS_NPM} == yarn1
		@cd ${NPM_REBUILD_WRKSRC_NODEJS} && \
		${SETENV} ${MAKE_ENV} ${NODEJS_REBUILD_ENV} npm rebuild
.      else
		@cd ${NPM_REBUILD_WRKSRC_NODEJS} && \
		${SETENV} ${MAKE_ENV} ${NODEJS_REBUILD_ENV} ${NPM_CMDNAME} rebuild
.      endif
.    else
	@${DO_NADA}
.    endif

electron-rebuild-native-node-modules-for-electron:
.    if defined(_ELECTRON_FEATURE_REBUILD_ELECTRON) && \
       ${_ELECTRON_FEATURE_REBUILD_ELECTRON} == yes
.      if ${_NODEJS_NPM} == pnpm
	@for dir in `${APP_BUILDER_CMD} node-dep-tree --dir ${NPM_REBUILD_WRKSRC_ELECTRON} | ${JQ_CMD} -r '.[] | { dir: .dir, name: .deps[].name } | .dir + "/" + .name'`; do \
		for subdir in `${FIND} $${dir} -type f -name binding.gyp -exec ${DIRNAME} {} ';' 2> /dev/null`; do \
			cd $${subdir} && \
			${ECHO_MSG} "===>  Rebuilding native node modules for electron in $${subdir}" && \
			${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} ${NPM_REBUILD_CMD} ${NPM_REBUILD_FLAGS}; \
		done \
	done
.      else
	@for dir in `${APP_BUILDER_CMD} node-dep-tree --dir ${NPM_REBUILD_WRKSRC_ELECTRON} | ${JQ_CMD} -r '.[] | { dir: .dir, name: .deps[].name } | .dir + "/" + .name'`; do \
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
.    if ${_NODEJS_NPM} == npm || ${_NODEJS_NPM} == yarn1
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
