# $FreeBSD$
#
# Handle dependency on OpenAL
#
# Feature:	openal
# Usage:	USES=openal or USES=openal:ARGS
# Valid ARGS:	al, soft (default), si, alut
#
# User-specified OpenAL wish:
# Usage:	WANT_OPENAL=ARG
# Valid ARG:	soft (default), si
#
# MAINTAINER: portmgr@FreeBSD.org

.if !defined(_INCLUDE_USES_OPENAL_MK)
_INCLUDE_USES_OPENAL_MK=	yes

_valid_ARGS=	al si soft alut

_si_DEPENDS=	libopenal.so.0:audio/openal
_soft_DEPENDS=	libopenal.so.1:audio/openal-soft
_alut_DEPENDS=	libalut.so.0:audio/freealut

_OPENAL_LIBS=	si soft
_DEFAULT_OPENAL=	soft

.if exists(${LOCALBASE}/lib/libopenal.a)
_HAVE_OPENAL=	si
.elif exists(${LOCALBASE}/bin/openal-info)
_HAVE_OPENAL=	soft
.endif

# Be friendly
.if empty(openal_ARGS)
openal_ARGS=	${_DEFAULT_OPENAL}
.endif

# Sanity checks
.if defined(WANT_OPENAL) && defined(_HAVE_OPENAL) && ${_HAVE_OPENAL} != ${WANT_OPENAL}
IGNORE=	OpenAL mismatch: ${_HAVE_OPENAL} is installed, but ${WANT_OPENAL} desired
.endif

.for _arg in ${openal_ARGS}
.    if ! ${_valid_ARGS:M${_arg}}
IGNORE=	Incorrect 'USES+= openal:${openal_ARGS}' usage: argument [${_arg}] is not recognized
.    endif
.    if ${_OPENAL_LIBS:M${_arg}} && ${openal_ARGS:Mal}
IGNORE=	Incorrect 'USES+= openal:${openal_ARGS}' usage: argument [${_arg}] cannot be used together with al
.    endif
.    if ${_OPENAL_LIBS:M${_arg}} && defined(_HAVE_OPENAL) && ${_HAVE_OPENAL} != ${_arg}
IGNORE=	OpenAL mismatch: port wants to use ${_arg} while you have ${_HAVE_OPENAL}
.    endif
.    if ${_OPENAL_LIBS:M${_arg}} && defined(WANT_OPENAL) && ${WANT_OPENAL} != ${_arg}
IGNORE=	OpenAL mismatch: port wants to use ${_arg} while you wish to use ${WANT_OPENAL}
.    endif
.    if ${_OPENAL_LIBS:M${_arg}}
.      for _carg in ${_OPENAL_LIBS:N${_arg}}
.        if ${openal_ARGS:M${_carg}}
IGNORE=	Incorrect 'USES+= openal:${openal_ARGS}' usage: arguments [${_arg}] and [${_carg}] cannot be used together
.        endif
.      endfor
.    endif
.endfor

# Proceed
_USE_OPENAL=

.if ${openal_ARGS:Mal}
.if defined(_HAVE_OPENAL)
_USE_OPENAL=	${_HAVE_OPENAL}
.elif defined(WANT_OPENAL)
_USE_OPENAL=	${WANT_OPENAL}
.else
_USE_OPENAL=	${_DEFAULT_OPENAL}
.endif
.endif

.for _arg in ${openal_ARGS:Nal}
_USE_OPENAL+=	${_arg}
.endfor

.for _arg in ${_USE_OPENAL}
LIB_DEPENDS+=	${_${_arg}_DEPENDS}
.endfor

.endif
