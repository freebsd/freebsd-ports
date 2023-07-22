# Handle dependency on security/py-cryptogrpaphy[-legacy]
#
# Feature:	pycrptography
# Usage:	USES=pycryptography
# Valid ARGS:	<none>, build, run
# 		<none>:   default same as build,run
# 		build:    add BUILD_DEPENDS
# 		run:      add RUN_DEPENDS
# 		test:     add TEST_DEPENDS
#
# MAINTAINER: portmgr@FreeBSD.org
#

.if ! defined(_INCLUDE_USES_PYCRYPTOGRAPHY_MK)
_INCLUDE_USES_PYCRYPTOGRAPHY_MK=	YES

# valid arguments:
_PYCRYPTOGRAPHY_MK_VALID_MODES=		build run test

# Suffixes
_PYCRYPTOGRAPHY_MK_SUFFIX_rust=		#
_PYCRYPTOGRAPHY_MK_SUFFIX_legacy=	-legacy

# Dependency
_PYCRYPTOGRAPHY_MK_SUFFIX=	${_PYCRYPTOGRAPHY_MK_SUFFIX_${PYCRYPTOGRAPHY_DEFAULT}}
_PYCRYPTOGRAPHY_MK_PKG=		${PYTHON_PKGNAMEPREFIX}cryptography${_PYCRYPTOGRAPHY_MK_SUFFIX}
_PYCRYPTOGRAPHY_MK_PORT=	security/py-cryptography${_PYCRYPTOGRAPHY_MK_SUFFIX}
_PYCRYPTOGRAPHY_MK_DEPENDENCY=	${_PYCRYPTOGRAPHY_MK_PKG}>0:${_PYCRYPTOGRAPHY_MK_PORT}@${PY_FLAVOR}

# === parse version arguments ===
_PYGRYPTOGRAPHY_MK_MODES=	# empty
.  for _mode in ${_PYCRYPTOGRAPHY_MK_VALID_MODES}
.    if ${pycryptography_ARGS:M${_mode}}
_PYCRYPTOGRAPHY_MK_MODES+=	${_mode}
.    endif
.  endfor
.  if empty(_PYGRYPTOGRAPHY_MK_MODES)
_PYCRYPTOGRAPHY_MK_MODES=	build run
.  endif

# == add actual dependencies ===
.  for _mode in ${_PYCRYPTOGRAPHY_MK_MODES}
${_mode:tu}_DEPENDS+=	${_PYCRYPTOGRAPHY_MK_DEPENDENCY}
.  endfor

.endif
