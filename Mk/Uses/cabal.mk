# $FreeBSD$
#
# Provide support for building Haskell packages using Cabal.
#
# Feature:	cabal
# Usage:	USES=cabal or USES=cabal:ARGS
# Valid ARGS:	hpack
#
# hpack:	The port doesn't have a .cabal file and needs devel/hs-hpack to
#		generate it from package.yaml file
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
#  FOO_DATADIR_VARS     Additional environment vars to add to FOO executable's
#                       wrapper script.
#
# MAINTAINER: haskell@FreeBSD.org

.if !defined(_INCLUDE_USES_CABAL_MK)
_INCLUDE_USES_CABAL_MK=    yes

_valid_ARGS=	hpack

.  for arg in ${cabal_ARGS}
.    if !${_valid_ARGS:M${arg}}
IGNORE=		USES=cabal: invalid arguments: ${arg}
.    endif
.  endfor

PKGNAMEPREFIX?=	hs-

EXECUTABLES?=	${PORTNAME}

CABAL_HOME=	${WRKDIR}/cabal-home
CABAL_LIBEXEC=	libexec/cabal
CABAL_EXTRACT_SUFX=	.tar.gz
CABAL_ARCH=	${ARCH:S/amd64/x86_64/:C/armv.*/arm/:S/powerpc64/ppc64/}

.  if !defined(CABAL_BOOTSTRAP)
BUILD_DEPENDS+=	cabal:devel/hs-cabal-install \
		ghc:lang/ghc
.  endif

.  if ${cabal_ARGS:Mhpack}
EXTRACT_DEPENDS+=	hpack:devel/hs-hpack
.  endif

# Inherited via lang/ghc we need to depend on iconv and libgmp.so (stage q/a)
iconv_ARGS=	translit
.include "${USESDIR}/iconv.mk"
LIB_DEPENDS+=	libgmp.so:math/gmp \
		libffi.so:devel/libffi

DIST_SUBDIR?=	cabal

.  if !defined(USE_GITHUB) && !defined(USE_GITLAB)
MASTER_SITES?=	https://hackage.haskell.org/package/${PORTNAME}-${PORTVERSION}/ \
		http://hackage.haskell.org/package/${PORTNAME}-${PORTVERSION}/
DISTFILES?=	${PORTNAME}-${PORTVERSION}${CABAL_EXTRACT_SUFX}
EXTRACT_ONLY?=	${PORTNAME}-${PORTVERSION}${CABAL_EXTRACT_SUFX}
.  endif

_USES_extract=	701:cabal-post-extract
_USES_patch=	701:cabal-post-patch
_USES_stage=	751:cabal-post-install-script

BUILD_TARGET?=	${EXECUTABLES:S/^/exe:&/}

.  if defined(USE_LOCALE)
LOCALE_ENV=	LANG=${USE_LOCALE} LC_ALL=${USE_LOCALE}
.  endif

_use_cabal=	${USE_CABAL:O:u}

.  for package in ${_use_cabal}
_PKG_GROUP=		${package:C/[\.-]//g}
_PKG_WITHOUT_REV=	${package:C/_[0-9]+//}
_REV=			${package:C/[^_]*//:S/_//}

MASTER_SITES+=	https://hackage.haskell.org/package/:${package:C/[\.-]//g} \
		http://hackage.haskell.org/package/:${package:C/[\.-]//g}
DISTFILES+=	${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${CABAL_EXTRACT_SUFX}:${package:C/[\.-]//g}
.    if !defined(CABAL_BOOTSTRAP)
EXTRACT_ONLY+=	${package:C/_[0-9]+//}/${package:C/_[0-9]+//}${CABAL_EXTRACT_SUFX}
.    endif

.    if ${package:C/[^_]*//:S/_//} != ""
DISTFILES+=	${package:C/_[0-9]+//}/revision/${package:C/[^_]*//:S/_//}.cabal:${package:C/[\.-]//g}
.    endif

.  endfor

# Fetches and unpacks package source from Hackage using only PORTNAME and PORTVERSION.
cabal-extract: ${WRKDIR}
	${RM} -rf ${CABAL_HOME}/.cabal
	${SETENV} HOME=${CABAL_HOME} cabal new-update
	cd ${WRKDIR} && \
		${SETENV} ${LOCALE_ENV} HOME=${CABAL_HOME} cabal get ${PORTNAME}-${PORTVERSION}

# Fetches and unpacks dependencies sources for a cabal-extract'ed package.
# Builds them as side-effect.
cabal-extract-deps:
.  if ${cabal_ARGS:Mhpack}
	cd ${WRKSRC} && ${SETENV} HOME=${CABAL_HOME} hpack
.  endif
	cd ${WRKSRC} && \
		${SETENV} ${LOCALE_ENV} HOME=${CABAL_HOME} cabal new-configure --flags="${CABAL_FLAGS}" ${CONFIGURE_ARGS}
	cd ${WRKSRC} && \
		${SETENV} ${LOCALE_ENV} HOME=${CABAL_HOME} cabal new-build --dependencies-only

# Generates USE_CABAL= ... line ready to be pasted into the port based on artifacts of cabal-extract-deps.
make-use-cabal:
	@echo ====================
	@echo -n USE_CABAL=
	@find ${CABAL_HOME} -name '*.conf' -exec basename {} + | sed -E 's|-[0-9a-z]{64}\.conf||' | sort | sed 's/$$/ \\/'
	@find ${CABAL_HOME} -name 'hsc2hs*.tar.gz' -exec basename {} + | sed -E 's|\.tar\.gz||' | sed 's/$$/ \\/'
	@find ${CABAL_HOME} -name 'alex*.tar.gz' -exec basename {} + | sed -E 's|\.tar\.gz||' | sed 's/$$/ \\/'
	@find ${CABAL_HOME} -name 'happy*.tar.gz' -exec basename {} + | sed -E 's|\.tar\.gz||' | sed 's/$$/ \\/'

# Re-generates USE_CABAL items to have revision numbers.
make-use-cabal-revs:
.  for package in ${_use_cabal}
	@(${SETENV} HTTP_ACCEPT="application/json" fetch -q -o - http://hackage.haskell.org/package/${package:C/_[0-9]+//}/revisions/ | sed -Ee 's/.*":([0-9]+)}\]/${package:C/_[0-9]+//}_\1 /' -e 's/_0//')
	@echo '\'
.  endfor

.  if !defined(CABAL_BOOTSTRAP)

cabal-post-extract:
.    for package in ${_use_cabal}
.      if ${package:C/[^_]*//:S/_//} != ""
		cp ${DISTDIR}/${DIST_SUBDIR}/${package:C/_[0-9]+//}/revision/${package:C/[^_]*//:S/_//}.cabal `find ${WRKDIR}/${package:C/_[0-9]+//} -name '*.cabal' -depth 1`
.      endif
	cd ${WRKDIR} && \
		mv ${package:C/_[0-9]+//} ${WRKSRC}/
.    endfor
	mkdir -p ${CABAL_HOME}/.cabal
	touch ${CABAL_HOME}/.cabal/config

cabal-post-patch:
.    if ${cabal_ARGS:Mhpack}
	cd ${WRKSRC} && ${SETENV} HOME=${CABAL_HOME} hpack
.    endif

.    if !target(do-build)
do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} HOME=${CABAL_HOME} cabal new-build --offline --disable-benchmarks --disable-tests --flags "${CABAL_FLAGS}" ${BUILD_ARGS} ${BUILD_TARGET}
.    endif

.    if !target(do-install)
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}
.      for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} \
		$$(find ${WRKSRC}/dist-newstyle -name ${exe} -type f -perm +111) \
		${STAGEDIR}${PREFIX}/${CABAL_LIBEXEC}/${exe}
	${ECHO} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO} '' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO} 'export ${exe:S/-/_/}_datadir=${DATADIR}' >> ${STAGEDIR}${PREFIX}/bin/${exe}
.         for dep in ${${exe}_DATADIR_VARS}
	${ECHO} 'export ${dep:S/-/_/}_datadir=${DATADIR}' >> ${STAGEDIR}${PREFIX}/bin/${exe}
.         endfor
	${ECHO} '' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${ECHO} '${PREFIX}/${CABAL_LIBEXEC}/${exe} "$$@"' >> ${STAGEDIR}${PREFIX}/bin/${exe}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${exe}
.      endfor
.    endif

.    if !defined(SKIP_CABAL_PLIST)
cabal-post-install-script:
.      for exe in ${EXECUTABLES}
		${ECHO_CMD} 'bin/${exe}' >> ${TMPPLIST}
		${ECHO_CMD} '${CABAL_LIBEXEC}/${exe}' >> ${TMPPLIST}
.      endfor
.    endif

.  endif # !defined(CABAL_BOOTSTRAP)

.endif
