# Allows to determine the compiler being used
#
# Feature:	compiler
# Usage:	USES=compiler or USES=compiler:ARGS
# Valid ARGS:	env (default, implicit) c++0x c++11-lib c++11-lang c11 c17 nestedfct features
#
# c++0x:	The port needs a compiler understanding C++0X
# c++11-lang:	The port needs a compiler understanding C++11
# c++14-lang:	The port needs a compiler understanding C++14
# c++17-lang:	The port needs a compiler understanding C++17
# c++20-lang:	The port needs a compiler understanding C++20
# c++2b-lang:	The port needs a compiler understanding C++2b
# gcc-c++11-lib:The port needs g++ compiler with a C++11 library
# c++11-lib:	The port needs a compiler understanding C++11 and with a C++11 ready standard library
# c11:		The port needs a compiler understanding C11
# c17:		The port needs a compiler understanding C17
# nestedfct:	The port needs a compiler understanding nested functions
# features:	The port will determine the features supported by the default compiler
#
# Variable to test after <bsd.port.pre.mk>
#
# COMPILER_TYPE:	can be gcc or clang
# ALT_COMPILER_TYPE:	can be gcc or clang depending on COMPILER_TYPE, only set if the base system has 2 compilers
# COMPILER_VERSION:	first 2 digits of the version: 33 for clang 3.3.*, 47 for gcc 4.7.*
# ALT_COMPILER_VERSION:	first 2 digits of the version: 33 for clang 3.3.*, 47 for gcc 4.7.* of the ALT_COMPILER_TYPE
#
# COMPILER_FEATURES:	the list of features supported by the compiler includes the standard C++ library.
# CHOSEN_COMPILER_TYPE:	can be gcc or clang (type of compiler chosen by the framework)
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_COMPILER_MK)
_INCLUDE_USES_COMPILER_MK=	yes

.  if empty(compiler_ARGS)
compiler_ARGS=	env
.  endif

VALID_ARGS=	c++11-lib c++11-lang c++14-lang c++17-lang c++20-lang \
		c++2b-lang c11 c17 features env nestedfct c++0x gcc-c++11-lib

_CC_hash:=	${CC:hash}
_CXX_hash:=	${CXX:hash}

.  if ${compiler_ARGS} == gcc-c++11-lib
_COMPILER_ARGS+=	features gcc-c++11-lib
.  elif ${compiler_ARGS} == c++11-lib
_COMPILER_ARGS+=	features c++11-lib
.  elif ${compiler_ARGS} == c++0x
_COMPILER_ARGS+=	features c++0x
.  elif ${compiler_ARGS} == c++11-lang
_COMPILER_ARGS+=	features c++11-lang
.  elif ${compiler_ARGS} == c++14-lang
_COMPILER_ARGS+=	features c++14-lang
.  elif ${compiler_ARGS} == c++17-lang
_COMPILER_ARGS+=	features c++17-lang
.  elif ${compiler_ARGS} == c++20-lang
_COMPILER_ARGS+=	features c++20-lang
.  elif ${compiler_ARGS} == c++2b-lang
_COMPILER_ARGS+=	features c++2b-lang
.  elif ${compiler_ARGS} == c11
_COMPILER_ARGS+=	features c11
.  elif ${compiler_ARGS} == c17
_COMPILER_ARGS+=	features c17
.  elif ${compiler_ARGS} == features
_COMPILER_ARGS+=	features
.  elif ${compiler_ARGS} == env
_COMPILER_ARGS+=	env
.  elif ${compiler_ARGS} == nestedfct
_COMPILER_ARGS+=	env nestedfct
.  else
IGNORE=	Invalid argument "${compiler_ARGS}", valid arguments are: ${VALID_ARGS}
_COMPILER_ARGS=	#
.  endif

.  if ${_COMPILER_ARGS:Mc++*} || ${_COMPILER_ARGS:Mc11} || ${_COMPILER_ARGS:Mc17}
_COMPILER_ARGS+=	features
.  endif

.  if defined(_CCVERSION_${_CC_hash})
_CCVERSION=	${_CCVERSION_${_CC_hash}}
.  else
_CCVERSION!=	${CC} --version
_CCVERSION_${_CC_hash}=	${_CCVERSION}
PORTS_ENV_VARS+=	_CCVERSION_${_CC_hash}
.  endif
COMPILER_VERSION=	${_CCVERSION:M[0-9]*.[0-9]*:[1]:C/([0-9]+)\.([0-9]+)\..*/\1\2/}
.  if ${_CCVERSION:Mclang}
COMPILER_TYPE=	clang
.  else
COMPILER_TYPE=	gcc
.  endif

ALT_COMPILER_VERSION=	0
ALT_COMPILER_TYPE=	none
_ALTCCVERSION=		none
.  if defined(_ALTCCVERSION_${_CC_hash})
_ALTCCVERSION=	${_ALTCCVERSION_${_CC_hash}}
.  else
.    if ${COMPILER_TYPE} == gcc && exists(/usr/bin/clang)
.      if ${ARCH} == amd64 || ${ARCH} == i386 # clang often non-default for a reason
_ALTCCVERSION!=	/usr/bin/clang --version
.      endif
.    elif ${COMPILER_TYPE} == clang && exists(/usr/bin/gcc)
_ALTCCVERSION!=	/usr/bin/gcc --version
.    endif
_ALTCCVERSION_${_CC_hash}=	${_ALTCCVERSION}
PORTS_ENV_VARS+=		_ALTCCVERSION_${_CC_hash}
.  endif

ALT_COMPILER_VERSION=	${_ALTCCVERSION:M[0-9]*.[0-9]*:[1]:C/([0-9]+)\.([0-9]+)\..*/\1\2/}
.  if ${_ALTCCVERSION:Mclang}
ALT_COMPILER_TYPE=	clang
.  elif ${_ALTCCVERSION} != none
ALT_COMPILER_TYPE=	gcc
.  endif

CHOSEN_COMPILER_TYPE=	${COMPILER_TYPE}

.  if ${_COMPILER_ARGS:Mnestedfct}
.    if ${COMPILER_TYPE} == clang
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
.    endif
.  endif

.  if ${_COMPILER_ARGS:Mfeatures}
.    if defined(_CXXINTERNAL_${_CXX_hash})
_CXXINTERNAL=	${_CXXINTERNAL_${_CXX_hash}}
.    else
_CXXINTERNAL!=	${CXX} -\#\#\# /dev/null 2>&1
_CXXINTERNAL_${_CXX_hash}=	${_CXXINTERNAL}
PORTS_ENV_VARS+=	_CXXINTERNAL_${_CXX_hash}
.    endif
.    if ${_CXXINTERNAL:M\"-lc++\"}
COMPILER_FEATURES=	libc++
.    else
COMPILER_FEATURES=	libstdc++
.    endif

CSTD=	c89 c99 c11 c17 gnu89 gnu99 gnu11
CXXSTD=	c++98 c++0x c++11 c++14 c++17 c++20 c++2b \
	gnu++98 gnu++11 gnu++14 gnu++17 gnu++20 gnu++2b

.    for std in ${CSTD} ${CXXSTD}
_LANG=c
.      if ${CXXSTD:M${std}}
_LANG=c++
.      endif
.      if defined(CC_OUTPUT_${_CC_hash}_${std:hash})
OUTPUT_${std}=	${CC_OUTPUT_${_CC_hash}_${std:hash}}
.      else
OUTPUT_${std}!=	if ${CC} -std=${std} -c -x ${_LANG} /dev/null -o /dev/null 2>&1; then echo yes; fi; echo
CC_OUTPUT_${_CC_hash}_${std:hash}=	${OUTPUT_${std}}
PORTS_ENV_VARS+=			CC_OUTPUT_${_CC_hash}_${std:hash}
.      endif
.      if !${OUTPUT_${std}:M*error*}
COMPILER_FEATURES+=	${std}
.      endif
.    endfor
.  endif

.  if ${_COMPILER_ARGS:Mc++11-lib}
.    if !${COMPILER_FEATURES:Mc++11}
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
.    elif ${COMPILER_TYPE} == clang && ${COMPILER_FEATURES:Mlibstdc++}
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
.    endif
.  endif

.  if (${_COMPILER_ARGS:Mc++2b-lang} && !${COMPILER_FEATURES:Mc++2b}) || \
(${_COMPILER_ARGS:Mc++20-lang} && !${COMPILER_FEATURES:Mc++20}) || \
(${_COMPILER_ARGS:Mc++17-lang} && !${COMPILER_FEATURES:Mc++17}) || \
(${_COMPILER_ARGS:Mc++14-lang} && !${COMPILER_FEATURES:Mc++14}) || \
(${_COMPILER_ARGS:Mc++11-lang} && !${COMPILER_FEATURES:Mc++11}) || \
(${_COMPILER_ARGS:Mc++0x} && !${COMPILER_FEATURES:Mc++0x}) || \
(${_COMPILER_ARGS:Mc11} && !${COMPILER_FEATURES:Mc11} && !${COMPILER_FEATURES:Mc17})
.    if ${_COMPILER_ARGS:Mc++2b-lang}
_LLVM_MINVER=	14
.    elif ${_COMPILER_ARGS:Mc++20-lang}
_LLVM_MINVER=	11
.    else
_LLVM_MINVER=	0
.    endif
.    if (defined(FAVORITE_COMPILER) && ${FAVORITE_COMPILER} == gcc) || (${ARCH} != amd64 && ${ARCH} != i386) # clang not always supported on Tier-2
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
.    elif ${COMPILER_TYPE} == gcc || \
	(${COMPILER_VERSION:C/[0-9]$//}<${_LLVM_MINVER})
.      if ${ALT_COMPILER_TYPE} == clang && \
	(${ALT_COMPILER_VERSION:C/[0-9]$//}>=${_LLVM_MINVER})
CPP=	clang-cpp
CC=	clang
CXX=	clang++
CHOSEN_COMPILER_TYPE=	clang
.      else
.        if ${LLVM_DEFAULT:C/^[789]0$/0/}<${_LLVM_MINVER}
_LLVM_REQ=	${_LLVM_MINVER}
.        else
_LLVM_REQ=	${LLVM_DEFAULT}
.        endif
BUILD_DEPENDS+=	clang${_LLVM_REQ}:devel/llvm${_LLVM_REQ}
CPP=	${LOCALBASE}/bin/clang-cpp${_LLVM_REQ}
CC=	${LOCALBASE}/bin/clang${_LLVM_REQ}
CXX=	${LOCALBASE}/bin/clang++${_LLVM_REQ}
CHOSEN_COMPILER_TYPE=	clang
.      endif
.    endif
.  endif

.  if ${_COMPILER_ARGS:Mgcc-c++11-lib}
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
.    if ${COMPILER_FEATURES:Mlibc++}
CXXFLAGS+=	-stdlib=libc++
.    endif
.  endif

.endif
