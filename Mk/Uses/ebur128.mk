# Handle dependency on audio/[lib]ebur128
# Feature:	ebur128
# Usage:	USES=ebur128:ARGS
# Valid ARGS:	<none>, build, lib, run, test
# 		<none>:   (default) same as lib
# 		build:    add BUILD_DEPENDS
#		lib:      add LIB_DEPENDS
# 		run:      add RUN_DEPENDS
# 		test:     add TEST_DEPENDS
#
# MAINTAINER: ports@FreeBSD.org
#

.if !defined(_INCLUDE_USES_EBUR128_MK)
_INCLUDE_USES_EBUR128_MK=	YES

#=== Check for invalid arguments ===
.  if !empty(ebur128_ARGS:Nbuild:Nlib:Nrun:Ntest)
IGNORE=	Invalid USES=ebur128 - unsupported argument(s): ${ebur128_ARGS}
.  endif

#=== Dependency selection ===
_ebur128_depends=	build lib run test
_ebur128_depend=	#
.  for _depend in ${_ebur128_depends:O:u}
.    if ${ebur128_ARGS:M${_depend}}
_ebur128_depend+=	${_depend}
.    endif
.  endfor

.  if empty(_ebur128_depend)
_ebur128_depend=	lib
.  endif

#=== Prefixes ===
_ebur128_prefix_rust=	#
_ebur128_prefix_legacy=	lib
_ebur128_prefix=	${_ebur128_prefix_${EBUR128_DEFAULT}}

#=== Dependency setup ===
_EBUR128_PORT=		audio/${_ebur128_prefix}ebur128
_EBUR128_LIB=		libebur128.so
_EBUR128_PKG=		${_ebur128_prefix}ebur128

_EBUR128_BUILD_DEPENDS=	${_EBUR128_PKG}>=0:${_EBUR128_PORT}
_EBUR128_LIB_DEPENDS=	${_EBUR128_LIB}:${_EBUR128_PORT}
_EBUR128_RUN_DEPENDS=	${_EBUR128_PKG}>=0:${_EBUR128_PORT}
_EBUR128_TEST_DEPENDS=	${_EBUR128_PKG}>=0:${_EBUR128_PORT}

#=== Actual dependency creation ===
.  for _depend in ${_ebur128_depend}
${_depend:tu}_DEPENDS+=	${_EBUR128_${_depend:tu}_DEPENDS}
.  endfor

.endif
