# Provide support for building Haskell packages using Cabal.
#
# Feature:	cabal
# Usage:	USES=cabal or USES=cabal:ARGS
# Valid ARGS:	hpack, nodefault
#
# hpack:	The port doesn't have a .cabal file and needs devel/hs-hpack to
#		generate it from package.yaml file
# nodefault:	Do not fetch the default distribution file from Hackage. If
#		USE_GITHUB or USE_GITLAB is specified in the port, this argument
#		is implied.
#
# Variables, which can be set by the port:
#
#  USE_CABAL		List of Haskell packages required to build a port.
#			Should be listed along with version, like profunctors-5.3
#			Package revision can be specified too with
#			usual "_" syntax: invariant-0.5.1_1
#			When creating a new port, the initial list can be built
#			using make-use-cabal auxiliary target.
#
#  CABAL_REVISION	Specifies a Haskell package revision. Set this to an
#			integer to pull in revised .cabal file from Hackage.
#
#  CABAL_FLAGS		List of Cabal flags to be passed verbatim into --flags
#			argument of cabal-install utility. Used for both
#			cabal configure and cabal build.
#
#  CABAL_EXECUTABLES	List of executable Cabal targets to be built and installed.
#			Consult the .cabal file of the project being ported to find
#			out possible values for this variable.
#					default: ${PORTNAME}
#
#  HACKAGE_DISTNAME	Use this knob if PORTNAME or PORTVERSION doesn't match
#			with package name and version on Hackage.
#					default: ${PORTNAME}-${PORTVERSION}
#
#  opt_USE_CABAL	Variant of USE_CABAL to be used with options framework.
#  opt_CABAL_FLAGS	Variant of CABAL_FLAGS to be used with options framework.
#			Note that it works a bit differently from CABAL_FLAGS:
#			it appends "${opt_CABAL_FLAGS}" when the option is enabled
#			and "-${opt_CABAL_FLAGS}" otherwise.
#  opt_CABAL_EXECUTABLES	Variant of CABAL_EXECUTABLES to be used with
#			options framework.
#
#  CABAL_WRAPPER_SCRIPTS	A subset of ${CABAL_EXECUTABLES} containing Haskell
#			programs to be wrapped into a shell script that sets
#			*_datadir environment variables before running the program.
#			This is needed for Haskell programs that install their
#			data files under share/ directory.
#
#  FOO_DATADIR_VARS     Additional environment vars to add to FOO executable's
#                       wrapper script.
#
#  CABAL_PROJECT	Sets how to treat existing cabal.project file. Possible
#			values are "remove" and "append".
#
#  SKIP_CABAL_PLIST	Set to "yes" to prevent Haskell executables from being
#			added to the pkg-plist automatically.
#
# MAINTAINER: haskell@FreeBSD.org

.if !defined(_INCLUDE_USES_CABAL_MK)
_INCLUDE_USES_CABAL_MK=    yes

_valid_ARGS=			hpack nodefault
_cabal_project_valid_VALUES=	append remove

.  for arg in ${cabal_ARGS}
.    if !${_valid_ARGS:M${arg}}
IGNORE=		USES=cabal: invalid arguments: ${arg}
.    endif
.  endfor

.  if defined(CABAL_PROJECT) && !${_cabal_project_valid_VALUES:M${CABAL_PROJECT}}
IGNORE=		CABAL_PROJECT: invalid value: ${CABAL_PROJECT}
.  endif

.  if ${ARCH} == i386 && defined(USE_CABAL) && ${USE_CABAL:Mbasement-0.0.1[4-5]}
# Upstream issue: https://github.com/haskell-foundation/foundation/issues/565
BROKEN=		${USE_CABAL:Mbasement-0.0.1[4-5]} package doesn't compile on i386
.  endif

PKGNAMEPREFIX?=	hs-

CABAL_EXECUTABLES?=	${PORTNAME}

CABAL_CMD?=	cabal
CABAL_PORT=	devel/hs-cabal-install
CABAL_HOME=	${WRKDIR}/cabal-home
CABAL_HOME_ENV=XDG_DATA_HOME=${CABAL_HOME} XDG_CONFIG_HOME=${CABAL_HOME} XDG_CACHE_HOME=${CABAL_HOME} HOME=${CABAL_HOME}
CABAL_LIBEXEC=	libexec/cabal
CABAL_EXTRACT_SUFX=	.tar.gz
CABAL_ARCH=	${ARCH:S/amd64/x86_64/:C/armv.*/arm/:S/powerpc64/ppc64/}
CABAL_DEPSDIR=	${WRKSRC}/${CABAL_DEPS_SUBDIR}
CABAL_DEPS_SUBDIR=	_cabal_deps
# A special cookie used to signify that the user is a maintainer updating the port
# using cabal-* targets. The presense of this cookie disables cabal-post-patch.
CABAL_COOKIE=	${WRKDIR}/.cabal_update_done.${PORTNAME}.${PREFIX:S/\//_/g}

HPACK_CMD?=		hpack
_CABAL2TUPLE_CMD=	cabal2tuple

.  if defined(BUILD_DEPENDS) && ${BUILD_DEPENDS:Mghc?*\:lang/ghc?*}
CABAL_WITH_ARGS=	--with-compiler=${BUILD_DEPENDS:Mghc?*\:lang/ghc?*:C/\:.*//} \
			--with-hsc2hs=${LOCALBASE}/bin/hsc2hs-${BUILD_DEPENDS:Mghc?*\:lang/ghc?*:C/\:.*//}
.  else
BUILD_DEPENDS+=	ghc:lang/ghc
.  endif

.  if "${PORTNAME}" != "cabal-install"
BUILD_DEPENDS+=	cabal:${CABAL_PORT}
.  endif

.  if ${cabal_ARGS:Mhpack}
EXTRACT_DEPENDS+=	hpack:devel/hs-hpack
.  endif

# Inherited via lang/ghc we need to depend on libffi.so and libgmp.so (stage q/a)
LIB_DEPENDS+=	libgmp.so:math/gmp \
		libffi.so:devel/libffi

DIST_SUBDIR?=	cabal

.  if !defined(USE_GITHUB) && !defined(USE_GITLAB) && !${cabal_ARGS:Mnodefault}
_hackage_is_default=	yes
.  else
_hackage_is_default=	no
.  endif

.  if defined(HACKAGE_DISTNAME) && ${_hackage_is_default} == no
IGNORE=		HACKAGE_DISTNAME is set, but it makes no sense if the default MASTER_SITES isn't HACKAGE
.  endif

MASTER_SITES+=		HACKAGE/${_hackage_group}
.  if defined(HACKAGE_DISTNAME)
WRKSRC?=		${WRKDIR}/${HACKAGE_DISTNAME}
.  endif
HACKAGE_DISTNAME?=	${PORTNAME}-${PORTVERSION}

.  if ${_hackage_is_default} == yes
DISTFILES+=	${HACKAGE_DISTNAME}/${HACKAGE_DISTNAME}${CABAL_EXTRACT_SUFX}
.    ifdef CABAL_REVISION
DISTFILES+=	${HACKAGE_DISTNAME}/revision/${CABAL_REVISION}.cabal
.    endif
.  else
_hackage_group=	:cabal_mk_hackage
.  endif

_USES_extract=	701:cabal-post-extract
_USES_patch=	701:cabal-post-patch
_USES_configure=301:cabal-pre-configure
_USES_stage=	751:cabal-post-install-script

BUILD_TARGET?=	${CABAL_EXECUTABLES:S/^/exe:&/}

_use_cabal=	${USE_CABAL:O:u}

.  for package in ${_use_cabal}
.    for pkg_without_group xgroup in ${package:C/:.*$$//} x${package:S/${package:C/:.*$$//}//:C/^.*://}
.      for pkg_name xrev in ${pkg_without_group:C/_[0-9]+//} x${pkg_without_group:C/[^_]*//:S/_//}
.        if ${xgroup} == "x"
DISTFILES+=	${pkg_name}/${pkg_name}${CABAL_EXTRACT_SUFX}${_hackage_group}
.          if ${xrev} != "x"
DISTFILES+=	${pkg_name}/revision/${xrev:S/^x//}.cabal${_hackage_group}
.          endif
.        else
DISTFILES+=	${pkg_name}${CABAL_EXTRACT_SUFX}:${xgroup:S/^x//}
.          if ${xrev} != "x"
DISTFILES+=	${pkg_name}/revision/${xrev:S/^x//}.cabal:${xgroup:S/^x//}
.          endif
.        endif # ${xgroup} == "x"
_CABAL_EXTRACT_ONLY+=	${pkg_name}/${pkg_name}${CABAL_EXTRACT_SUFX}
.      endfor
.    endfor
.  endfor

.  if !defined(EXTRACT_ONLY)
EXTRACT_ONLY=	${_DISTFILES:N*\.cabal}
.  else
.    if !defined(SKIP_CABAL_EXTRACT)
EXTRACT_ONLY+= ${_CABAL_EXTRACT_ONLY}
.    endif
.  endif

.  if defined(CABAL_REPOSITORIES) && !empty(CABAL_REPOSITORIES)
.    for r in ${CABAL_REPOSITORIES}
CABAL2TUPLE_ARGS+=	--group=${r} --master-site=${MASTER_SITES:M*\:${r}:[1]:S/:${r}//:S|/package/||}
.    endfor
.  endif

# Auxiliary targets used during port creation/updating.

# Populates Haskell package list from Hackage.
# Fetches and unpacks package source from Hackage using only PORTNAME and PORTVERSION.
# If Hackage isn't a default MASTER_SITE (for instance, when USE_GITHUB is present)
# this target requires distinfo to be present too.
cabal-extract: check-cabal
.  if ${_hackage_is_default} == no
	@${ECHO_MSG} "===> Recursing down to make extract"
	@${MAKE} -C ${.CURDIR} extract SKIP_CABAL_EXTRACT=yes USE_CABAL=
	${RM} -r ${CABAL_HOME}
.  endif
	@${ECHO_MSG} "===> Fetching Hackage index into ${CABAL_HOME}/.cabal"
	${SETENV} ${CABAL_HOME_ENV} ${CABAL_CMD} update
.  if ${_hackage_is_default} == yes
	cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} get ${HACKAGE_DISTNAME}
.  else
.    if ${cabal_ARGS:Mhpack}
	@${ECHO_MSG} "===> Running ${HPACK_CMD} to generate .cabal file"
	cd ${WRKSRC} && ${SETENV} ${CABAL_HOME_ENV} ${HPACK_CMD}
.    endif
.  endif
# Remove Haskell dependencies that come from GH_TUPLE
	@${RM} -r ${WRKSRC}/dist-newstyle
.  ifdef CABAL_REPOSITORIES
	@${ECHO_MSG} "===> Fetching additional Cabal repositories index into ${CABAL_HOME}/.cabal"
	@cd ${WRKSRC} && \
		${SETENV} ${CABAL_HOME_ENV} ${CABAL_CMD} update
.  endif
# Create a cookie for cabal-post-patch
	@${TOUCH} ${EXTRACT_COOKIE} ${CABAL_COOKIE}

# Calls cabal build --dry-run on the Haskell package located in ${WRKSRC}
# This is a Cabal way of doing configure step of the building process
# This pulls in all source dependencies, resolves them and generates build plan
cabal-configure: check-cabal
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} build --dry-run --disable-benchmarks --disable-tests --flags="${CABAL_FLAGS}" ${CABAL_WITH_ARGS} ${CABAL_LTO_ARGS} ${BUILD_ARGS} ${BUILD_TARGET}

# Calls cabal build on the Haskell package located in ${WRKSRC}
cabal-build: check-cabal
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} build --disable-benchmarks --disable-tests ${CABAL_WITH_ARGS} ${CABAL_LTO_ARGS} ${BUILD_ARGS} ${BUILD_TARGET}

# Generates USE_CABAL= ... line ready to be pasted into the port based on the plan.json file generated by cabal configure.
make-use-cabal: check-cabal2tuple
	@${ECHO_MSG} "===> Processing plan.json"
	@${_CABAL2TUPLE_CMD} ${CABAL2TUPLE_ARGS} ${WRKSRC} || (${ECHO_CMD} "Did you forget to make cabal-configure ?" ; exit 1)
.  if ${_hackage_is_default} == yes
	@if ${GREP} -q 'x-revision' ${WRKSRC}/*.cabal; then \
		${ECHO_MSG} "Downloaded .cabal file contains x-revision, make sure to add CABAL_REVISION=" `${GREP} 'x-revision' ${WRKSRC}/*.cabal | ${SED} -e s/x-revision://`; \
	fi
.  endif

check-cabal:
	@if ! type ${CABAL_CMD} > /dev/null 2>&1; then \
		${ECHO_MSG} "===> cabal executable not found, install ${CABAL_PORT} or set CABAL_CMD"; exit 1; \
	fi; \

check-cabal2tuple:
	@if ! type ${_CABAL2TUPLE_CMD} > /dev/null 2>&1; then \
		${ECHO_MSG} "===> cabal2tuple executable not found, install \"ports-mgmt/hs-cabal2tuple\""; exit 1; \
	fi


# Main targets implementation.

cabal-post-extract:
.  if !defined(SKIP_CABAL_EXTRACT)
.    if "${CABAL_PROJECT}" == "remove"
# Remove the project file if requested
	${RM} ${WRKSRC}/cabal.project
.    endif
.    ifndef(CABAL_PROJECT)
	@${TEST} ! -f ${WRKSRC}/cabal.project || \
		(${ECHO_CMD} "cabal.project file is already present in WRKSRC! Set CABAL_PROJECT variable." && false)
.    endif
# Copy revised .cabal file if present
.    if defined(CABAL_REVISION) && ${_hackage_is_default} == yes
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${HACKAGE_DISTNAME}/revision/${CABAL_REVISION}.cabal `find ${WRKSRC} -name '*.cabal' -depth 1`
.    endif

# Move extracted dependencies into ${CABAL_DEPSDIR} directory
	${MKDIR} ${CABAL_DEPSDIR}
.    for package in ${_use_cabal}
.      for pkg_without_group in ${package:C/:.*$$//}
.        for pkg_name xrev in ${pkg_without_group:C/_[0-9]+//} x${pkg_without_group:C/[^_]*//:S/_//}
# Copy revised .cabal file if present
.          if ${xrev} != "x"
		${CP} ${DISTDIR}/${DIST_SUBDIR}/${pkg_name}/revision/${xrev:S/^x//}.cabal `find ${WRKDIR}/${pkg_name} -name '*.cabal' -depth 1`
.          endif
# Move the dependency source itself
	cd ${WRKDIR} && \
		${MV} ${pkg_name} ${CABAL_DEPSDIR}/
.        endfor
.      endfor
.    endfor
# Create the cabal-install config
	${MKDIR} ${CABAL_HOME}/.cabal
	${ECHO_CMD} "jobs: ${MAKE_JOBS_NUMBER}" > ${CABAL_HOME}/.cabal/config
.  endif # SKIP_CABAL_EXTRACT

cabal-post-patch:
.  if !defined(SKIP_CABAL_EXTRACT)
	@${TEST} ! -f ${CABAL_COOKIE} || \
		(${ECHO_CMD} "===> Patching done, skipping cabal-post-patch" && false)
# Append our stuff to possibly existing cabal.project.local
	${ECHO_CMD} "" >> ${WRKSRC}/cabal.project.local
	${ECHO_CMD} "-- added by USES=cabal" >> ${WRKSRC}/cabal.project.local
	${ECHO_CMD} "packages:" >> ${WRKSRC}/cabal.project.local
.    for package in ${_use_cabal}
.      for pkg_without_group in ${package:C/:.*$$//}
.        for pkg_name in ${pkg_without_group:C/_[0-9]+//}
	${ECHO_CMD} "        ${CABAL_DEPS_SUBDIR}/${pkg_name}" >> ${WRKSRC}/cabal.project.local
.        endfor
.      endfor
.    endfor
.  endif # SKIP_CABAL_EXTRACT && !CABAL_COOKIE

cabal-pre-configure:
# Generate .cabal file with hpack if requested
.  if ${cabal_ARGS:Mhpack}
	cd ${WRKSRC} && ${SETENV} ${CABAL_HOME_ENV} hpack
.  endif

.  if !target(do-build)
do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CABAL_HOME_ENV} ${CABAL_CMD} build --offline --disable-benchmarks --disable-tests ${CABAL_WITH_ARGS} ${CABAL_LTO_ARGS} --flags "${CABAL_FLAGS}" ${BUILD_ARGS} ${BUILD_TARGET}
.  endif

.  if !target(do-install)
do-install:
.    if defined(CABAL_WRAPPER_SCRIPTS) && !empty(CABAL_WRAPPER_SCRIPTS)
	${MKDIR} ${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}
.    endif
.    for exe in ${CABAL_EXECUTABLES}
.      if defined(CABAL_WRAPPER_SCRIPTS) && ${CABAL_WRAPPER_SCRIPTS:M${exe}}
	${INSTALL_PROGRAM} \
		$$(find ${WRKSRC}/dist-newstyle -name ${exe} -type f -perm +111) \
		${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}/${exe}
	${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO_CMD} '' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO_CMD} 'export ${exe:S/-/_/g}_datadir=${DATADIR}' >> ${STAGEDIR}${PREFIX}/bin/${exe}
.        for dep in ${${exe}_DATADIR_VARS}
	${ECHO_CMD} 'export ${dep:S/-/_/g}_datadir=${DATADIR}' >> ${STAGEDIR}${PREFIX}/bin/${exe}
.        endfor
	${ECHO_CMD} '' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO_CMD} 'exec ${PREFIX}/${CABAL_LIBEXEC}/${exe} "$$@"' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${exe}
.      else
	${INSTALL_PROGRAM} \
		$$(find ${WRKSRC}/dist-newstyle -name ${exe} -type f -perm +111) \
		${STAGEDIR}${PREFIX}/bin/${exe}
.      endif
.    endfor
.  endif

.  if !defined(SKIP_CABAL_PLIST)
cabal-post-install-script:
.    for exe in ${CABAL_EXECUTABLES}
		${ECHO_CMD} 'bin/${exe}' >> ${TMPPLIST}
.      if defined(CABAL_WRAPPER_SCRIPTS) && ${CABAL_WRAPPER_SCRIPTS:M${exe}}
		${ECHO_CMD} '${CABAL_LIBEXEC}/${exe}' >> ${TMPPLIST}
.      endif
.    endfor
.  endif

.endif
