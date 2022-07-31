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
#  CABAL_FLAGS		List of Cabal flags to be passed verbatim into --flags
#			argument of cabal-install utility. Used for both
#			cabal configure and cabal build.
#
#  EXECUTABLES		List of executable Cabal targets to be built and installed.
#					default: ${PORTNAME}
#
#  opt_USE_CABAL	Variant of USE_CABAL to be used with options framework.
#  opt_CABAL_FLAGS	Variant of CABAL_FLAGS to be used with options framework.
#			Note that it works a bit differently from CABAL_FLAGS:
#			it appends "${opt_CABAL_FLAGS}" when the option is enabled
#			and "-${opt_CABAL_FLAGS}" otherwise.
#  opt_EXECUTABLES	Variant of EXECUTABLES to be used with options framework.
#
#  CABAL_WRAPPER_SCRIPTS	A subset of ${EXECUTABLES} containing Haskell
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

.  if ${ARCH} == i386 && defined(USE_CABAL) && ${USE_CABAL:Mbasement-0.0.14}
# Upstream issue: https://github.com/haskell-foundation/foundation/issues/565
BROKEN=		basement-0.0.14 package doesn't compile on i386
.  endif

PKGNAMEPREFIX?=	hs-

EXECUTABLES?=	${PORTNAME}

CABAL_CMD?=	cabal
CABAL_PORT=	devel/hs-cabal-install
CABAL_HOME=	${WRKDIR}/cabal-home
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

.  if ${_hackage_is_default} == yes
MASTER_SITES=	https://hackage.haskell.org/package/${PORTNAME}-${PORTVERSION}/ \
		http://hackage.haskell.org/package/${PORTNAME}-${PORTVERSION}/
DISTFILES+=	${PORTNAME}-${PORTVERSION}${CABAL_EXTRACT_SUFX}
.  endif

_USES_extract=	701:cabal-post-extract
_USES_patch=	701:cabal-post-patch
_USES_configure=301:cabal-pre-configure
_USES_stage=	751:cabal-post-install-script

BUILD_TARGET?=	${EXECUTABLES:S/^/exe:&/}

_use_cabal=	${USE_CABAL:O:u}

.  for package in ${_use_cabal}
_PKG_GROUP=		${package:C/[\.-]//g}
_PKG_WITHOUT_REV=	${package:C/_[0-9]+//}
_REV=			${package:C/[^_]*//:S/_//}

MASTER_SITES+=	https://hackage.haskell.org/package/:${package:C/[\.-]//g} \
		http://hackage.haskell.org/package/:${package:C/[\.-]//g}
DISTFILES+=	${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${CABAL_EXTRACT_SUFX}:${package:C/[\.-]//g}

.    if ${package:C/[^_]*//:S/_//} != ""
DISTFILES+=	${package:C/_[0-9]+//}/revision/${package:C/[^_]*//:S/_//}.cabal:${package:C/[\.-]//g}
.    endif

_CABAL_EXTRACT_ONLY+=	${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${CABAL_EXTRACT_SUFX}
.  endfor

.  if !defined(EXTRACT_ONLY)
EXTRACT_ONLY=	${_DISTFILES:N*\.cabal}
.  else
.    if !defined(SKIP_CABAL_EXTRACT)
EXTRACT_ONLY+= ${_CABAL_EXTRACT_ONLY}
.    endif
.  endif


# Auxiliary targets used during port creation/updating.

# Populates Haskell package list from Hackage.
# Fetches and unpacks package source from Hackage using only PORTNAME and PORTVERSION.
# If Hackage isn't a default MASTER_SITE (for instance, when USE_GITHUB is present)
# this target requires distinfo to be present too.
cabal-extract: check-cabal
.  if ${_hackage_is_default} == no
	@${ECHO_MSG} "===> Recursing down to make extract"
	@${MAKE} -C ${.CURDIR} extract SKIP_CABAL_EXTRACT=yes
	${RM} -rf ${CABAL_HOME}
.  endif
	@${ECHO_MSG} "===> Fetching Cabal package index into ${CABAL_HOME}/.cabal"
	@${SETENV} HOME=${CABAL_HOME} ${CABAL_CMD} update
.  if ${_hackage_is_default} == yes
	@cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} ${CABAL_CMD} get ${PORTNAME}-${PORTVERSION}
.  else
.    if ${cabal_ARGS:Mhpack}
	@${ECHO_MSG} "===> Running ${HPACK_CMD} to generate .cabal file"
	@cd ${WRKSRC} && ${SETENV} HOME=${CABAL_HOME} ${HPACK_CMD}
.    endif
.  endif
	@${RM} -r ${WRKSRC}/dist-newstyle
	@${TOUCH} ${EXTRACT_COOKIE} ${CABAL_COOKIE}

# Calls cabal configure on the Haskell package located in ${WRKSRC}
cabal-configure: check-cabal
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} ${CABAL_CMD} configure --disable-benchmarks --disable-tests --flags="${CABAL_FLAGS}" ${CABAL_WITH_ARGS} ${CONFIGURE_ARGS}

# Calls cabal build on the Haskell package located in ${WRKSRC}
cabal-build: check-cabal
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} ${CABAL_CMD} build --disable-benchmarks --disable-tests ${CABAL_WITH_ARGS} ${BUILD_ARGS} ${BUILD_TARGET}

# Generates USE_CABAL= ... line ready to be pasted into the port based on the plan.json file generated by cabal configure.
make-use-cabal: check-cabal2tuple
	@${ECHO_MSG} "===> Processing plan.json"
	@${_CABAL2TUPLE_CMD} ${WRKSRC} || (${ECHO_CMD} "Did you forget to make cabal-configure ?" ; exit 1)

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
# Remove the project file as requested
.    if "${CABAL_PROJECT}" == "remove"
	${RM} ${WRKSRC}/cabal.project
.    endif
# Save the original project file so that users can patch them
.    if "${CABAL_PROJECT}" == "append"
	${MV} ${WRKSRC}/cabal.project ${WRKSRC}/cabal.project.${PORTNAME}
.    endif

	@${TEST} ! -f ${WRKSRC}/cabal.project || \
		(${ECHO_CMD} "cabal.project file is already present in WRKSRC! Set CABAL_PROJECT variable." && false)

# Move extracted dependencies into ${CABAL_DEPSDIR} directory
	${MKDIR} ${CABAL_DEPSDIR}
.    for package in ${_use_cabal}
# Copy revised .cabal file if present
.      if ${package:C/[^_]*//:S/_//} != ""
		cp ${DISTDIR}/${DIST_SUBDIR}/${package:C/_[0-9]+//}/revision/${package:C/[^_]*//:S/_//}.cabal `find ${WRKDIR}/${package:C/_[0-9]+//} -name '*.cabal' -depth 1`
.      endif
# Move the dependency source itself
	cd ${WRKDIR} && \
		mv ${package:C/_[0-9]+//} ${CABAL_DEPSDIR}/
.    endfor
# Create the cabal-install config
	${MKDIR} ${CABAL_HOME}/.cabal
	${ECHO_CMD} "jobs: ${MAKE_JOBS_NUMBER}" > ${CABAL_HOME}/.cabal/config
.  endif # SKIP_CABAL_EXTRACT

cabal-post-patch:
.  if !defined(SKIP_CABAL_EXTRACT)
	@${TEST} ! -f ${CABAL_COOKIE} || \
		(${ECHO_CMD} "===> Patching done, skipping cabal-post-patch" && false)
# Create our own cabal.project
	${ECHO_CMD} "packages:" > ${WRKSRC}/cabal.project
.    if "${CABAL_PROJECT}" != "append"
	${ECHO_CMD} "        ." >> ${WRKSRC}/cabal.project
.    endif
.    for package in ${_use_cabal}
	${ECHO_CMD} "        ${CABAL_DEPS_SUBDIR}/${package:C/_[0-9]+//}" >> ${WRKSRC}/cabal.project
.    endfor
# Append the (possibly patched) original cabal.project, if requested
.    if "${CABAL_PROJECT}" == "append"
	${CAT} ${WRKSRC}/cabal.project.${PORTNAME} >> ${WRKSRC}/cabal.project
.    endif
.  endif # SKIP_CABAL_EXTRACT && !CABAL_COOKIE

cabal-pre-configure:
# Generate .cabal file with hpack if requested
.  if ${cabal_ARGS:Mhpack}
	cd ${WRKSRC} && ${SETENV} HOME=${CABAL_HOME} hpack
.  endif

.  if !target(do-build)
do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} ${CABAL_CMD} new-build --offline --disable-benchmarks --disable-tests ${CABAL_WITH_ARGS} --flags "${CABAL_FLAGS}" ${BUILD_ARGS} ${BUILD_TARGET}
.  endif

.  if !target(do-install)
do-install:
.    if defined(CABAL_WRAPPER_SCRIPTS) && !empty(CABAL_WRAPPER_SCRIPTS)
	${MKDIR} ${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}
.    endif
.    for exe in ${EXECUTABLES}
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
.      for exe in ${EXECUTABLES}
		${ECHO_CMD} 'bin/${exe}' >> ${TMPPLIST}
.        if defined(CABAL_WRAPPER_SCRIPTS) && ${CABAL_WRAPPER_SCRIPTS:M${exe}}
		${ECHO_CMD} '${CABAL_LIBEXEC}/${exe}' >> ${TMPPLIST}
.        endif
.    endfor
.  endif

.endif
