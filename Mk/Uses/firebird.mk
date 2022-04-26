# Provide support for Firebird
# Feature:	firebird
# Usage:	USES=	firebird[:version]
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_FIREBIRD_MK)
_INCLUDE_USES_FIREBIRD_MK=	yes

.  if !empty(firebird_ARGS)
FIREBIRD_VER=	${firebird_ARGS}
.  else
FIREBIRD_VER=	${FIREBIRD_DEFAULT}
.  endif

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
VALID_FIREBIRD_VER=        2.5 3.0 4.0

.  for v in ${FIREBIRD_DEFAULT}
.    if ! ${VALID_FIREBIRD_VER:M$v}
IGNORE=		Invalid Firebird default version ${FIREBIRD_DEFAULT}; valid versions are ${VALID_FIREBIRD_VER}
.    endif
.  endfor

.  for w in ${FIREBIRD_VER}
.    if ! ${VALID_FIREBIRD_VER:M$w}
IGNORE=		Invalid Firebird version ${FIREBIRD_VER}; valid versions are ${VALID_FIREBIRD_VER}
.    endif
.  endfor

LIB_DEPENDS+=	libfbclient.so:databases/firebird${FIREBIRD_VER:S/.//}-client

.endif
