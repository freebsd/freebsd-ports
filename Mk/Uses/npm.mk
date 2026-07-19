# Provides support for ports using Node.js package manager
#
# Feature:	npm
# Usage:	USES=npm:npm-name[,arg,...]
# Valid ARGS:	<npm-name>, fetch, extract, build, run, test
#
# <npm-name>:	The name of Node.js package manager (NPM) the port depends on.
#		Supported package managers are:
#
#		npm:   The port uses NPM as package manager.
#		yarn1: The port uses Yarn (v1) as package manager.
#		yarn2: The port uses Yarn (v2 or v3) as package manager.
#		yarn4: The port uses Yarn (v4+) as package manager.
#		pnpm:  The port uses PNPM as package manager.
#
#		NOTE: The port must specify exactly a single package manager.
#		Multiple package managers cannot be specified.
#
# fetch:	NPM is needed at fetch time. Adds it to FETCH_DEPENDS.
# extract:	NPM is needed at extract time. Adds it to EXTRACT_DEPENDS.
# build:	NPM is needed at build time. Adds it to BUILD_DEPENDS.
# run:		NPM is needed at run time. Adds it to RUN_DEPENDS.
# test:		NPM is needed at test time. Adds it to TEST_DEPENDS.
#
# NOTE: If the port specifies none of fetch, extract, build, run or test, we
# assume the port requires build and test dependencies.
#
# Variables, which may be set by the port:
#
# NPM_VER:	A version of node package manager the port uses. If yarn >2, or
#		pnpm is used for the package manager, the framework requires the
#		variable to be set so that it can bootstrap the correct version
#		of package manager.
#
#		It is usually specified in package.json and the framework tries
#		to automatically detect the version. Auto-detection can be
#		overridden by manually specifying the value in Makefile.
#
# Targets, which may be used by the port (ON by default, setting the variables
# to "no" disable the targets):
#
# NPM_PREFETCH:	Downloads node modules the port uses according to the pre-stored
#		package.json (and package-lock.json, yarn.lock, or
#		pnpm-lock.yaml depending on the node package manager used) in
#		PKGJSONSDIR. Downloaded node modules are archived into a single
#		tarball as one of the DISTFILES.
#
#	NOTE 1:	If the source directory of the port has other relevant files
#	than package.json and lockfile, the relevant files must also be copied
#	into PKGJSONSDIR. (Examples of relevant files includes .npmrc, .yarnrc,
#	and pnpm-workspace.yaml.)
#
#	NOTE 2:	If the source directory of the port contains multiple
#	package.json's and/or lockfiles, all files needed for generating node
#	modules archive must be copied into PKGJSONSDIR with directory hierarchy
#	preserved.
#
# NPM_EXTRACT:	Installs the prefetched node modules into the port's working
#		source directory.
#
# MAINTAINER: tagattie@FreeBSD.org

.if !defined(_INCLUDE_USES_NPM_MK)
_INCLUDE_USES_NPM_MK=	yes

# Node.js package manager depends on Node.js
.include "${USESDIR}/nodejs.mk"
_NODEJS_PKGNAME=node${NODEJS_VERSION}
_NODEJS_PORT=	www/node${NODEJS_VERSION}

_VALID_NPM_NAMES=npm yarn1 yarn2 yarn4 pnpm

# Process USES=npm:ARG
# Detect fetch, extract, build, run, or test dependency
_NPM_ARGS=	${npm_ARGS:S/,/ /g}
.  if ${_NPM_ARGS:Mfetch}
_NPM_FETCH_DEP=	yes
_NPM_ARGS:=	${_NPM_ARGS:Nfetch}
.  endif
.  if ${_NPM_ARGS:Mextract}
_NPM_EXTRACT_DEP=yes
_NPM_ARGS:=	${_NPM_ARGS:Nextract}
.  endif
.  if ${_NPM_ARGS:Mbuild}
_NPM_BUILD_DEP=	yes
_NPM_ARGS:=	${_NPM_ARGS:Nbuild}
.  endif
.  if ${_NPM_ARGS:Mrun}
_NPM_RUN_DEP=	yes
_NPM_ARGS:=	${_NPM_ARGS:Nrun}
.  endif
.  if ${_NPM_ARGS:Mtest}
_NPM_TEST_DEP=	yes
_NPM_ARGS:=	${_NPM_ARGS:Ntest}
.  endif
# If no dependencies are specified, assume build and test are required
.  if !defined(_NPM_FETCH_DEP) && !defied(_NPM_EXTRACT_DEP) && \
	!defined(_NPM_BUILD_DEP) && !defined(_NPM_RUN_DEP) && \
	!defined(_NPM_TEST_DEP)
_NPM_BUILD_DEP=	yes
_NPM_TEST_DEP=	yes
.  endif
# Now _NPM_ARGS should contain a name of node package manager
.  if ${_VALID_NPM_NAMES:M${_NPM_ARGS}}
_NPM_NAME=	${_NPM_ARGS}
.  elif empty(_NPM_ARGS)
IGNORE=	does not specify a name of node package manager
.  else
IGNORE=	specifies unknown USES=npm arguments: ${_NPM_ARGS}
.  endif
.  if ${_NPM_NAME} == npm
_NPM_PKGNAME=	${_NPM_NAME}${NODEJS_SUFFIX}
_NPM_PORTDIR=	www/${_NPM_NAME}${NODEJS_SUFFIX}
.  elif ${_NPM_NAME} == yarn1
_NPM_PKGNAME=	yarn${NODEJS_SUFFIX}
_NPM_PORTDIR=	www/yarn${NODEJS_SUFFIX}
.  endif

# Setup dependencies
.  for stage in FETCH EXTRACT BUILD RUN TEST
.    if defined(_NPM_${stage}_DEP)
.      if ${_NPM_NAME} == npm || ${_NPM_NAME} == yarn1
${stage}_DEPENDS+=	${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.      else
${stage}_DEPENDS+=	${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}
.      endif
.    endif
.  endfor

# Try to detect the version of package manager from the pre-stored package.json
# if it is not specified by a port. (If yarn >2 or pnpm is used, the framework
# needs to know the version for correctly boostrap the package manager.)
PKGJSONSDIR?=	${FILESDIR}/packagejsons
NPM_PKGFILE?=	package.json
NPM_VER?=

_NPM_EXISTS_PKGFILE?=	no
.  if exists(${PKGJSONSDIR}/${NPM_PKGFILE})
_NPM_EXISTS_PKGFILE=	yes
.  endif
.  if ${_NPM_NAME} == yarn2 || ${_NPM_NAME} == yarn4 || ${_NPM_NAME} == pnpm
.    if ${_NPM_EXISTS_PKGFILE} == yes && empty(NPM_VER)
NPM_VER!=	${CAT} ${PKGJSONSDIR}/${NPM_PKGFILE} | \
		${TR} -d '\n\r\t' | ${SED} -e 's/ //g; s/"//g' | \
		${SED} -E -e ' \
			/devEngines:\{packageManager:\{/ { \
				s/.*devEngines:\{packageManager:\{([^}]+)\}\}.*/\1/; \
				h; \
				s/.*name:([^,}]+).*/\1/p; \
				g; \
				s/.*version:([^+,}]+).*/@\1/p; \
				d; \
			}; \
			/packageManager:/ { \
				s/.*packageManager:([^+,}]+).*/\1/p; d; \
			}' | \
		${CUT} -f 2 -d '@'
.    endif
.    if empty(NPM_VER)
IGNORE=	does not specity version of ${NPM_CMDNAME} used for prefetching node modules
.    else
_NPM_VER_PARTS=	${NPM_VER:S/./ /g}
NPM_VER_MAJOR=	${_NPM_VER_PARTS:[1]}
NPM_VER_MINOR=	${_NPM_VER_PARTS:[2]}
.    endif
.  endif

# Define variables related to node package manager
NPM_NAME=		${_NPM_NAME}
NPM_FETCH_FLAGS?=
NPM_EXTRACT_FLAGS?=
NPM_EXTRACT_WRKSRC?=	${WRKSRC}
.  if ${_NPM_NAME} == npm
NPM_LOCKFILE?=		package-lock.json
NPM_MODULE_CACHE?=	node_modules
NPM_CMDNAME?=		npm
NPM_CACHE_SETUP_CMD?=	${DO_NADA}
NPM_FETCH_CMD?=		${NPM_CMDNAME} ci
NPM_FETCH_FLAGS+=	--ignore-scripts --no-progress --no-audit --no-fund \
			--no-update-notifier --loglevel=error
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
NPM_EXEC_FLAGS+=	--no-update-notifier
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
NPM_REBUILD_FLAGS+=	--no-update-notifier
.  elif ${_NPM_NAME:Myarn*}
NPM_LOCKFILE?=		yarn.lock
NPM_MODULE_CACHE?=	yarn-offline-cache
NPM_CMDNAME?=		yarn
NPM_FETCH_CMD?=		${NPM_CMDNAME} install
NPM_EXTRACT_CMD?=	${NPM_CMDNAME} install
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
.    if ${_NPM_NAME} == yarn1
NPM_CACHE_SETUP_CMD?=	${ECHO_CMD} 'yarn-offline-mirror "./${NPM_MODULE_CACHE}"' >> .yarnrc
NPM_FETCH_FLAGS+=	--frozen-lockfile --ignore-scripts --silent
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --offline
.    elif ${_NPM_NAME} == yarn2
NPM_CACHE_SETUP_CMD?=	${NPM_CMDNAME} config set cacheFolder "./${NPM_MODULE_CACHE}"
NPM_FETCH_FLAGS+=	--immutable --mode=skip-build --silent
NPM_EXTRACT_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableNetwork false; \
			${NPM_CMDNAME} config set enableInlineBuilds true"
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --immutable-cache
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.    elif ${_NPM_NAME} == yarn4
NPM_CACHE_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableGlobalCache false; \
			${NPM_CMDNAME} config set cacheFolder \"./${NPM_MODULE_CACHE}\""
NPM_FETCH_FLAGS+=	--immutable --mode=skip-build --silent
NPM_EXTRACT_SETUP_CMD?=	${SH} -c "${NPM_CMDNAME} config set enableNetwork false; \
			${NPM_CMDNAME} config set enableInlineBuilds true"
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --immutable-cache
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.    endif
.  elif ${_NPM_NAME} == pnpm
NPM_LOCKFILE?=		pnpm-lock.yaml
NPM_WORKSPACEFILE?=	pnpm-workspace.yaml
NPM_MODULE_CACHE?=	pnpm-store
NPM_CMDNAME?=		pnpm
NPM_CACHE_SETUP_CMD?=	${DO_NADA}
NPM_FETCH_CMD?=		${NPM_CMDNAME} fetch
NPM_FETCH_FLAGS+=	--frozen-lockfile --ignore-scripts --loglevel=error \
			--store-dir ${WRKDIR}/node-modules-cache/${NPM_MODULE_CACHE}
NPM_EXTRACT_CMD?=	${NPM_CMDNAME} install
NPM_EXTRACT_FLAGS+=	${NPM_FETCH_FLAGS} --offline
NPM_EXEC_CMD?=		${NPM_CMDNAME} exec
NPM_REBUILD_CMD?=	${NPM_CMDNAME} rebuild
.  endif

# Use utility targets?
NPM_PREFETCH?=	${_NPM_EXISTS_PKGFILE}
NPM_EXTRACT?=	${NPM_PREFETCH}

# Bootstrap node package manager for yarn >2 or pnpm
.  if ${_NPM_NAME} == yarn2 || ${_NPM_NAME} == yarn4 || ${_NPM_NAME} == pnpm
_USES_fetch+=	490:npm-fetch-node-package-manager

DISTFILES+=	${NPM_CMDNAME}-${NPM_VER}.tgz:prefetch
FETCH_DEPENDS+=	${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}

npm-fetch-node-package-manager:
	@${ECHO_MSG} "===>  Fetching and setting up ${NPM_CMDNAME} version ${NPM_VER}"
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR} ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack enable --install-directory ${WRKDIR}/.bin
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz ]; then \
		cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} corepack pack ${NPM_CMDNAME}@${NPM_VER} && \
		${TAR} -xzf corepack.tgz && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/npm-create-mtree.sh ${NPM_CMDNAME} > \
			${NPM_CMDNAME}.mtree && \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz @${NPM_CMDNAME}.mtree; \
	fi
	@${SETENV} ${MAKE_ENV} corepack install -g ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz
.  endif

.  if ${NPM_PREFETCH:tl} == yes
.    if ${_NPM_EXISTS_PKGFILE} == no
IGNORE=	does not store ${NPM_PKGFILE} in ${PKGJSONSDIR} for prefetching node modules
.    endif

_USES_fetch+=	491:npm-fetch-node-modules \
		492:npm-archive-node-modules

_DISTFILE_prefetch=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-node-modules${EXTRACT_SUFX}
DISTFILES+=		${_DISTFILE_prefetch}:prefetch

.    if ${_NPM_NAME} == npm || ${_NPM_NAME} == yarn1
FETCH_DEPENDS+= ${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.    elif ${_NPM_NAME} == pnpm
FETCH_DEPENDS+=	jq:textproc/jq
.      if ${NPM_VER_MAJOR} >= 11
FETCH_DEPENDS+=	sqlite3:databases/sqlite3
.      endif
.    endif

npm-fetch-node-modules:
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
		done; \
	fi

npm-archive-node-modules:
.    if ${_NPM_NAME} == npm
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} ] && [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Archiving prefetched node modules"; \
		for dir in `${FIND} -s ${WRKDIR}/node-modules-cache -type d -name ${NPM_MODULE_CACHE} -print | \
			${GREP} -ve '${NPM_MODULE_CACHE}/.*/${NPM_MODULE_CACHE}'`; do \
			${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
				${SH} ${SCRIPTSDIR}/npm-create-mtree.sh $${dir} >> \
				${WRKDIR}/node-modules-cache.mtree; \
		done; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} \
			-C ${WRKDIR} @node-modules-cache.mtree; \
		if [ ${TMPDIR} != ${WRKDIR} ]; then \
			${RM} -r ${WRKDIR}; \
		fi; \
	fi
.    elif ${_NPM_NAME:Myarn*} || ${_NPM_NAME} == pnpm
.      if ${_NPM_NAME} == pnpm
.        if ${NPM_VER_MAJOR} >= 11
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} ] && [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Normalizing timestamps and permissions of prefetched node modules"; \
		tmpdir=${WRKDIR}/pnpm_tmp; \
		storedir=${WRKDIR}/node-modules-cache/${NPM_MODULE_CACHE}/v11; \
		input_db=$${storedir}/index.db; \
		output_db=$${tmpdir}/index.db; \
		output_db_dump=$${storedir}/index_dump.sql; \
		${MKDIR} $${tmpdir}; \
		cd $${tmpdir} && ${SETENV} ${MAKE_ENV} ${NPM_CMDNAME} add --ignore-scripts --silent msgpackr; \
		sqlite3 $${input_db} \
			"SELECT writefile('$${tmpdir}/' || row_number() OVER (ORDER BY key ASC) || '.msgpack', data) FROM package_index;" > /dev/null; \
		sqlite3 $${input_db} \
			"SELECT key FROM package_index ORDER BY key ASC;" > $${tmpdir}/keys_list.txt; \
		counter=1; \
		while IFS= read -r key; do \
			${PRINTF} "%s" "$${key}" > $${tmpdir}/$${counter}.key; \
			counter=$$((counter + 1)); \
		done < $${tmpdir}/keys_list.txt; \
		for file in $${tmpdir}/*.msgpack; do \
			base=$${file%.msgpack}; \
			node -e " \
				const fs = require('fs'); \
				const { Unpackr } = require('msgpackr'); \
				const unpackr = new Unpackr({}); \
				const buf = fs.readFileSync(0); \
				const data = unpackr.unpack(buf); \
				console.log(JSON.stringify(data, (key, value) => { \
					if (value instanceof Map) { \
						return { __type: 'Map', data: Array.from(value.entries()) }; \
					} \
					return value; \
				})); \
			" < $${file} > $${base}.msgpack.json; \
			jq -S ' \
				walk( \
					if type == "object" then \
						if has("checkedAt") then .checkedAt = 0 else . end | \
						if has("mode") then \
							if (.mode / 16 | floor) % 2 == 1 then .mode = .mode - 16 else . end \
						else \
							. \
						end \
					else \
						. \
					end \
				) \
			' $${base}.msgpack.json > $${base}.normalized.json; \
			node -e " \
				const fs = require('fs'); \
				const { Packr } = require('msgpackr'); \
				const packr = new Packr({ structuredClone: true }); \
				const rawJson = JSON.parse(fs.readFileSync(0, 'utf-8')); \
				const restoreMaps = (obj) => { \
					if (obj && typeof obj === 'object') { \
						if (obj.__type === 'Map') { \
							return new Map(obj.data.map(([k, v]) => [k, restoreMaps(v)])); \
						} \
						for (let k in obj) { \
							obj[k] = restoreMaps(obj[k]); \
						} \
					} \
					return obj; \
				}; \
				const restoredData = restoreMaps(rawJson); \
				process.stdout.write(packr.pack(restoredData)); \
			" < $${base}.normalized.json > $${base}.normalized.msgpack; \
		done; \
		sqlite3 $${output_db} \
			"CREATE TABLE package_index (key TEXT PRIMARY KEY, data BLOB) WITHOUT ROWID;" > /dev/null 2>&1; \
		sqlite3 $${output_db} \
			"PRAGMA page_size = 4096; PRAGMA journal_mode = DELETE; PRAGMA auto_vacuum = NONE; PRAGMA secure_delete = ON;" > /dev/null 2>&1; \
		total_files=$$((counter - 1)); \
		i=1; \
		while [ $${i} -le $${total_files} ]; do \
			real_key=`${CAT} $${tmpdir}/$${i}.key`; \
			{ \
				${PRINTF} "INSERT INTO package_index (key, data) VALUES ('%s', x'" "$${real_key}"; \
				hexdump -v -e '/1 "%02x"' $${tmpdir}/$${i}.normalized.msgpack; \
				${PRINTF} "');\n"; \
			} | sqlite3 $${output_db}; \
			i=$$((i + 1)); \
		done; \
		sqlite3 $${output_db} "REINDEX; VACUUM;"; \
		sqlite3 $${output_db} ".dump" > $${output_db_dump}; \
		${RM} -r $${input_db} $${storedir}/tmp; \
	fi
.        else
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} ] && [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Normalizing timestamps and permissions of prefetched node modules"; \
		${FIND} ${WRKDIR}/node-modules-cache/${NPM_MODULE_CACHE} \
			-type f -name '*.json' -exec ${SH} -c ' \
			for f do \
				jq -c "walk(if type == \"object\" and has(\"checkedAt\") then .checkedAt = 0 else . end)" $${f} > $${f}.tmp && mv $${f}.tmp $${f}; \
			done \
			' ${SH} {} ';'; \
		for dir in projects tmp; do \
			${RM} -r ${WRKDIR}/node-modules-cache/${NPM_MODULE_CACHE}/*/$${dir}; \
		done; \
	fi
.        endif
.      endif
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} ] && [ -d ${WRKDIR}/node-modules-cache ]; then \
		${ECHO_MSG} "===>  Archiving prefetched node modules"; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/npm-create-mtree.sh ${NPM_MODULE_CACHE} > \
			node-modules-cache.mtree && \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DIST_SUBDIR}/${_DISTFILE_prefetch} @node-modules-cache.mtree; \
		if [ ${TMPDIR} != ${WRKDIR} ]; then \
			${RM} -r ${WRKDIR}; \
		fi; \
	fi
.    endif
.  endif

.  if ${NPM_EXTRACT:tl} == yes
_USES_extract+=	600:npm-extract-node-package-manager \
		601:npm-copy-package-file \
		602:npm-install-node-modules

.    if ${_NPM_NAME} == yarn1
EXTRACT_DEPENDS+= ${_NPM_PKGNAME}>0:${_NPM_PORTDIR}
.    elif ${_NPM_NAME} == yarn2 || ${_NPM_NAME} == yarn4 || ${_NPM_NAME} == pnpm
EXTRACT_DEPENDS+= ${_NODEJS_PKGNAME}>0:${_NODEJS_PORT}
.      if ${_NPM_NAME} == pnpm && ${NPM_VER_MAJOR} >= 11
EXTRACT_DEPENDS+= sqlite3:databases/sqlite3
.        if (${NPM_VER_MAJOR} == 11 && ${NPM_VER_MINOR} >= 3) || \
	     ${NPM_VER_MAJOR} >= 12
NPM_EXTRACT_FLAGS+=	--trust-lockfile
.        endif
.      endif
.    endif

npm-extract-node-package-manager:
.    if ${_NPM_NAME} == yarn2 || ${_NPM_NAME} == yarn4 || ${_NPM_NAME} == pnpm
	@${ECHO_MSG} "===>  Setting up ${NPM_CMDNAME} version ${NPM_VER}"
	@${MKDIR}  ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack enable --install-directory ${WRKDIR}/.bin
	@${SETENV} ${MAKE_ENV} corepack install -g ${DISTDIR}/${DIST_SUBDIR}/${NPM_CMDNAME}-${NPM_VER}.tgz
.    else
	@${DO_NADA}
.    endif

npm-copy-package-file:
.    if ${_NPM_EXISTS_PKGFILE} == yes
	@${ECHO_MSG} "===>  Copying ${NPM_PKGFILE} and ${NPM_LOCKFILE} to ${NPM_EXTRACT_WRKSRC}"
	@for f in `${FIND} ${PKGJSONSDIR} -type f \( -name ${NPM_PKGFILE} -o -name ${NPM_LOCKFILE} \) -print | ${SED} -e 's|${PKGJSONSDIR}/||'`; do \
		${MKDIR} -p `${DIRNAME} ${NPM_EXTRACT_WRKSRC}/$${f}`; \
		if [ -f ${NPM_EXTRACT_WRKSRC}/$${f} ]; then \
			${MV} -f ${NPM_EXTRACT_WRKSRC}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}.bak; \
		fi; \
		${CP} ${PKGJSONSDIR}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}; \
	done
.      if defined(NPM_WORKSPACEFILE) && !empty(NPM_WORKSPACEFILE)
	@for f in `${FIND} ${PKGJSONSDIR} -type f -name ${NPM_WORKSPACEFILE} -print | ${SED} -e 's|${PKGJSONSDIR}/||'`; do \
		${MKDIR} -p `${DIRNAME} ${NPM_EXTRACT_WRKSRC}/$${f}`; \
		if [ -f ${NPM_EXTRACT_WRKSRC}/$${f} ]; then \
			${MV} -f ${NPM_EXTRACT_WRKSRC}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}.bak; \
		fi; \
		${CP} ${PKGJSONSDIR}/$${f} ${NPM_EXTRACT_WRKSRC}/$${f}; \
	done
.      endif
.    endif

npm-install-node-modules:
.    if ${_NPM_NAME} == npm
	@${ECHO_MSG} "===>  Moving prefetched node modules to ${NPM_EXTRACT_WRKSRC}"
	@if [ -d ${EXTRACT_WRKDIR}/node-modules-cache ]; then \
		for dir in `${FIND} -s ${EXTRACT_WRKDIR}/node-modules-cache -type d -name ${NPM_MODULE_CACHE} -print | \
			${GREP} -ve '${NPM_MODULE_CACHE}/.*/${NPM_MODULE_CACHE}'`; do \
			${MV} $${dir} `${ECHO_CMD} $${dir} | sed -e 's|${EXTRACT_WRKDIR}/node-modules-cache|${NPM_EXTRACT_WRKSRC}|'`; \
		done; \
	fi
.    elif ${_NPM_NAME:Myarn*}
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
.    elif ${_NPM_NAME} == pnpm
	@${ECHO_MSG} "===>  Installing node modules from prefetched cache"
.      if ${NPM_VER_MAJOR} >= 11
	@if [ -d ${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE} ]; then \
		normalized_db_dump=${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE}/v11/index_dump.sql; \
		index_db=${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE}/v11/index.db; \
		sqlite3 $${index_db} < $${normalized_db_dump}; \
	fi
.      endif
	@if [ -d ${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${MV} ${EXTRACT_WRKDIR}/${NPM_MODULE_CACHE} ${WRKDIR}/node-modules-cache; \
	fi
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
.  endif

.endif # _INCLUDE_USES_NPM_MK
