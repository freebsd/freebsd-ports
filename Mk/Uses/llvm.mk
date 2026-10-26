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
# * environment
#         export:         do export CC, CXX,... variables [default]
#                         (adds a BUILD_DEPENDS on the clang component)
#         noexport:       do not export CC,CXX,... variables
#
# * components (LLVM is split into one port per sub-project, see
#   devel/llvm/Makefile.component; the core LLVM port is always added)
#         clang lld lldb mlir polly flang flang-rt compiler-rt openmp:
#                         also depend on that component, in the same
#                         mode(s) as the core LLVM port
#
# An example usage might be:
#         USES=   llvm
#   or
#         USES=   llvm:13,build
#   or
#         USES=   llvm:min=14,lib
#   or
#         USES=   llvm:20,lib,clang,noexport
#
# The following variables are exposed to be used in the ports tree at the moment:
#         * LLVM_VERSION  version chosen from the arguments to llvm.mk
#         * LLVM_PORT     chosen llvm port
#         * LLVM_CONFIG   llvm-config of the chosen port
#         * LLVM_LIBLLVM  libLLVM.so of the chosen port
#         * LLVM_PREFIX   installation prefix of the chosen port
#         * CLANG_PORT    clang port of the chosen version
#         * CLANG_RESOURCE_DIR  clang resource directory of the chosen
#                         version (${LLVM_PREFIX}/lib/clang/<version>)
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_LLVM_MK)
_INCLUDE_USES_LLVM_MK=	YES

_LLVM_MK_VALID_VERSIONS=	12 13 14 15 16 17 18 19 20 21 22 23
_LLVM_MK_VALID_CONSTRAINTS=	min max
_LLVM_MK_VALID_MODES=		build run lib
_LLVM_MK_VALID_EXPORTS=		export noexport
_LLVM_MK_VALID_COMPONENTS=	clang lld lldb mlir polly flang flang-rt \
				compiler-rt openmp

# === verify that there are no invalid arguments ===
.  for _arg in ${llvm_ARGS}
.    if !${_LLVM_MK_VALID_VERSIONS:M${_arg}} && \
        !${_LLVM_MK_VALID_MODES:M${_arg}} && \
        ${_arg:C/^(${_LLVM_MK_VALID_CONSTRAINTS:tW:S/ /|/g})=(${_LLVM_MK_VALID_VERSIONS:tW:S/ /|/g})$//} != "" && \
        !${_LLVM_MK_VALID_EXPORTS:M${_arg}} && \
        !${_LLVM_MK_VALID_COMPONENTS:M${_arg}}
BROKEN=		USES=llvm:${llvm_ARGS:tW:S/ /,/g} contains an invalid argument: "${_arg}"
.    endif
.  endfor

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
BROKEN=		USES=llvm:${llvm_ARGS:tW:S/ /,/g} contains multiple version definitions
.      else
_LLVM_MK_VERSION=	${_ver}
.      endif
.    endif
.  endfor
.  if empty(_LLVM_MK_VERSION)
_LLVM_MK_VERSION=	${LLVM_DEFAULT}
.  endif

# === parse environment arguments ===
_LLVM_MK_EXPORT=	# empty
.  for _export in ${_LLVM_MK_VALID_EXPORTS}
.    if ${llvm_ARGS:M${_export}}
.      if !empty(_LLVM_MK_EXPORT)
BROKEN=		USES=llvm:${llvm_ARGS:tW:S/ /,/g} contains multiple export definitions
.      else
_LLVM_MK_EXPORT=	${_export}
.      endif
.    endif
.  endfor
.  if empty(_LLVM_MK_EXPORT)
_LLVM_MK_EXPORT=	export
.  endif

# === parse component arguments ===
_LLVM_MK_COMPONENTS=	# empty
.  for _comp in ${_LLVM_MK_VALID_COMPONENTS}
.    if ${llvm_ARGS:M${_comp}}
_LLVM_MK_COMPONENTS+=	${_comp}
.    endif
.  endfor

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
.  for _ver in ${_LLVM_MK_VALID_VERSIONS}
_LLVM_MK_SUFFIX_${_ver}?=	${_ver}
.  endfor

# === define variables to depend on and export ===
_LLVM_MK_SUFFIX=	${_LLVM_MK_SUFFIX_${_LLVM_MK_VERSION}}
_LLVM_MK_PORT=		devel/llvm${_LLVM_MK_SUFFIX}
_LLVM_MK_LIBLLVM=	libLLVM-${_LLVM_MK_VERSION}.so
_LLVM_MK_PATH=		llvm-config${_LLVM_MK_SUFFIX}
_LLVM_MK_PREFIX=	${PREFIX}/llvm${_LLVM_MK_SUFFIX}
# clang < 16 named its resource directory after the full version
_LLVM_MK_RESOURCE_VER_12=	12.0.1
_LLVM_MK_RESOURCE_VER_13=	13.0.1
_LLVM_MK_RESOURCE_VER_14=	14.0.6
_LLVM_MK_RESOURCE_VER_15=	15.0.7
_LLVM_MK_RESOURCE_DIR=	${_LLVM_MK_PREFIX}/lib/clang/${_LLVM_MK_RESOURCE_VER_${_LLVM_MK_VERSION}:U${_LLVM_MK_VERSION}}

# component -> port origin and a file it installs
_LLVM_MK_CPORT_clang=		lang/clang
_LLVM_MK_CFILE_clang=		${_LLVM_MK_PREFIX}/bin/clang
_LLVM_MK_CPORT_lld=		devel/lld
_LLVM_MK_CFILE_lld=		${_LLVM_MK_PREFIX}/bin/ld.lld
_LLVM_MK_CPORT_lldb=		devel/lldb
_LLVM_MK_CFILE_lldb=		${_LLVM_MK_PREFIX}/bin/lldb
_LLVM_MK_CPORT_mlir=		devel/mlir
_LLVM_MK_CFILE_mlir=		${_LLVM_MK_PREFIX}/lib/cmake/mlir/MLIRConfig.cmake
_LLVM_MK_CPORT_polly=		devel/polly
_LLVM_MK_CFILE_polly=		${_LLVM_MK_PREFIX}/lib/LLVMPolly.so
_LLVM_MK_CPORT_flang=		lang/flang
_LLVM_MK_CFILE_flang=		${_LLVM_MK_PREFIX}/bin/flang
_LLVM_MK_CPORT_flang-rt=	devel/flang-rt
_LLVM_MK_CFILE_flang-rt=	${_LLVM_MK_RESOURCE_DIR}/lib/${CONFIGURE_TARGET:U${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}}/libflang_rt.runtime.a
_LLVM_MK_CPORT_compiler-rt=	devel/compiler-rt
_LLVM_MK_CFILE_compiler-rt=	${_LLVM_MK_RESOURCE_DIR}/include/sanitizer/common_interface_defs.h
_LLVM_MK_CPORT_openmp=		devel/openmp
_LLVM_MK_CFILE_openmp=		${_LLVM_MK_PREFIX}/lib/libomp.so

# == add actual dependencies ===
_LLVM_MK_PATH_lib=	${_LLVM_MK_LIBLLVM}
.  for _mode in ${_LLVM_MK_MODES}
_LLVM_MK_PATH_${_mode}?=	${_LLVM_MK_PATH}
${_mode:tu}_DEPENDS+=	${_LLVM_MK_PATH_${_mode}}:${_LLVM_MK_PORT}
.    for _comp in ${_LLVM_MK_COMPONENTS}
${_mode:S/lib/run/:tu}_DEPENDS+=	${_LLVM_MK_CFILE_${_comp}}:${_LLVM_MK_CPORT_${_comp}}${_LLVM_MK_SUFFIX}
.    endfor
.  endfor
# The exported compiler is needed to build, whatever the mode.
.  if ${_LLVM_MK_EXPORT} == export && \
     !(${_LLVM_MK_MODES:Mbuild} && ${_LLVM_MK_COMPONENTS:Mclang})
BUILD_DEPENDS+=	${_LLVM_MK_CFILE_clang}:${_LLVM_MK_CPORT_clang}${_LLVM_MK_SUFFIX}
.  endif

# == export config ===
LLVM_PORT=		${_LLVM_MK_PORT}
LLVM_CONFIG=		${_LLVM_MK_PATH}
LLVM_LIBLLVM=		${_LLVM_MK_LIBLLVM}
LLVM_VERSION=		${_LLVM_MK_VERSION}
LLVM_PREFIX=		${_LLVM_MK_PREFIX}
CLANG_PORT=		${_LLVM_MK_CPORT_clang}${_LLVM_MK_SUFFIX}
CLANG_RESOURCE_DIR=	${_LLVM_MK_RESOURCE_DIR}

.  if empty(_LLVM_MK_EXPORT:Mnoexport)
CC=			${LLVM_PREFIX}/bin/clang
CXX=			${LLVM_PREFIX}/bin/clang++
CPP=			${LLVM_PREFIX}/bin/clang-cpp
.  endif

.endif
