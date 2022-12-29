# Provides support to depend on LLVM
#
# USES=llvm supports two kinds of arguments:
#
# * mode
#         <none>:         defaults to build
#         build:          add a BUILD_DEPENDS on chosen llvm-port
#         run:            add a RUN_DEPENDS on chosen llvm-port
#         lib:            add a LIB_DEPENDS on chosen llvm-port
#
# * version
#         <none>:         defaults to ${LLVM_DEFAULT}
#         number:         use explicitly the specified version
#         min=number:     use specified min if ${LLVM_DEFAULT} is lower
#         max=number:     use specified max if ${LLVM_DEFAULT} is higher
#
# An example usage might be:
#         USES=   llvm
#   or
#         USES=   llvm:13,build
#   or
#         USES=   llvm:min=14,lib
#
# The following variables are exposed to be used in the ports tree at the moment:
#         * LLVM_VERSION  version chosen from the arguments to llvm.mk
#         * LLVM_PORT     chosen llvm port
#         * LLVM_CONFIG   llvm-config of the chosen port
#         * LLVM_LIBLLVM  libLLVM.so of the chosen port
#         * LLVM_PREFIX   installation prefix of the chosen port
#

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
.    if ${LLVM_DEFAULT:N1[0-9]*}
_LLVM_MK_VERSION=	${LLVM_DEFAULT:S/0$//}
.    else
_LLVM_MK_VERSION=	${LLVM_DEFAULT}
.    endif
.  endif

# === handle constraints ===
.  for _constraint in ${_LLVM_MK_VALID_CONSTRAINTS}
_version=	${llvm_ARGS:M${_constraint}=[0-9]*:S/${_constraint}=//}
.    if !empty(_version)
_LLVM_MK_CONSTRAINT_${_constraint}:=	${_version}
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
