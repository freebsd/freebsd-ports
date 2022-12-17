# Provides support to depend on LLVM
#
# It chooses the llvm port to be used based on the following constraint:
#	1) no constraints given						=> ${LLVM_DEFAULT}
#	2) exact constraint given					=> ${exact}
#	2) max constraint given && ${max} < ${LLVM_DEFAULT}		=> ${max}
#	3) min constraint given && ${LLVM_DEFAULT} < ${LLVM_DEFAULT}	=> ${LLVM_DEFAULT}

# Usage:
# 	USES=	llvm			- default version chosen
# 	USES=	llvm:15			- exact constraint
# 	USES=	llvm:min=9		- min constraint: max(min,default)
# 	USES=	llvm:max=10		- max constraint: min(max,default)
# 	USES=	llvm:min=10,max=11	- all constraint: max(min(max,default),default)

.if !defined(_INCLUDE_USES_LLVM_MK)
_INCLUDE_USES_LLVM_MK=	YES

_LLVM_MK_VALID_VERSIONS=	7 8 9 10 11 12 13 14 15
_LLVM_MK_VALID_CONSTRAINTS=	min max
_LLVM_MK_VALID_MODES=		build run lib

# === parse mode arguments ===
_LLVM_MK_MODES=	# empty
.  for _mode in ${_LLVM_MK_VALID_MODES}
.    if ${llvm_ARGS:M${_mode}}
_LLVM_MK_MODES+=	${_mode}
.    endif
.  endfor
.  if empty(_LLVM_MK_MODES)
_LLVM_MK_MODES=	build
.  endif

# === parse version arguments ===
_LLVM_MK_VERSION=	# empty
.  for _ver in ${_LLVM_MK_VALID_VERSIONS}
.    if ${llvm_ARGS:M${_ver}}
.      if !empty(_LLVM_MK_VERSION)
BROKEN=		USES=llvm:${llvm_ARGS} contains multiple version definitions
.      else
_LLVM_MK_VERSION=	${_ver}
.      endif
.    endif
.  endfor
.  if empty(_LLVM_MK_VERSION)
_LLVM_MK_VERSION=	${LLVM_DEFAULT}
.  endif

# === handle constraints ===
.  for _constraint in ${_LLVM_MK_VALID_CONSTRAINTS}
_version=	${llvm_ARGS:M${_constraint}=[0-9]*:S/${_constraint}=//}
.    if !empty(_version)
_LLVM_MK_CONSTRAINT_${_constraint}=	${_version}
.    endif
.  endfor

.  if !empty(_LLVM_MK_CONSTRAINT_min)
.    if ${_LLVM_MK_CONSTRAINT_min} > ${_LLVM_MK_VERSION}
_LLVM_MK_VERSION=	${_LLVM_MK_CONSTRAINT_min}
.    endif
.  endif

.  if !empty(_LLVM_MK_CONSTRAINT_max)
.    if ${_LLVM_MK_CONSTRAINT_max} < ${_LLVM_MK_VERSION}
_LLVM_MK_VERSION=	${_LLVM_MK_CONSTRAINT_max}
.    endif
.  endif

# === define helpers for the dependencies ===
.  for _ver in ${_LLVM_MK_VALID_VERSIONS:N1[0-9]}
_LLVM_MK_SUFFIX_${_ver}=	${_ver}0
.  endfor

.  for _ver in ${_LLVM_MK_VALID_VERSIONS}
_LLVM_MK_SUFFIX_${_ver}?=	${_ver}
.  endfor

# === define variables to depend on and export ===
_LLVM_MK_PORT=		devel/llvm${_LLVM_MK_SUFFIX_${_LLVM_MK_VERSION}}
_LLVM_MK_LIBLLVM=	libLLVM-${_LLVM_MK_VERSION}.so
_LLVM_MK_PATH=		llvm-config${_LLVM_MK_SUFFIX_${_LLVM_MK_VERSION}}
_LLVM_MK_PREFIX=	${PREFIX}/llvm${_LLVM_MK_SUFFIX_${_LLVM_MK_VERSION}}

# == add actual dependencies ===
_LLVM_MK_PATH_lib=	${_LLVM_MK_LIBLLVM}
.  for _mode in ${_LLVM_MK_MODES}
_LLVM_MK_PATH_${_mode}?=	${_LLVM_MK_PATH}
${_mode:tu}_DEPENDS+=	${_LLVM_MK_PATH_${_mode}}:${_LLVM_MK_PORT}
.  endfor

# == export config ===
LLVM_PORT=		${_LLVM_MK_PORT}
LLVM_CONFIG=		${_LLVM_MK_PATH}
LLVM_LIBLLVM=		${_LLVM_MK_LIBLLVM}
LLVM_VERSION=		${_LLVM_MK_VERSION}
LLVM_PREFIX=		${_LLVM_MK_PREFIX}

.endif
