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
VALID_FIREBIRD_VER=        3.0 4.0

.  if ! ${VALID_FIREBIRD_VER:M${FIREBIRD_DEFAULT}}
IGNORE=		Invalid Firebird default version ${FIREBIRD_DEFAULT}; valid versions are ${VALID_FIREBIRD_VER}
.  elif ! ${VALID_FIREBIRD_VER:M${FIREBIRD_VER}}
IGNORE=		Invalid Firebird version ${FIREBIRD_VER}; valid versions are ${VALID_FIREBIRD_VER}
.  endif

LIB_DEPENDS+=	libfbclient.so:databases/firebird${FIREBIRD_VER:S/.//}-client

.endif
