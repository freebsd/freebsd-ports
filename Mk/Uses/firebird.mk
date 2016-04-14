# $FreeBSD$
#
# Provide support for Firebird
# Feature:	firebird
# Usage:	USES=	firebird[:version]
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_FIREBIRD_MK)
_INCLUDE_USES_FIREBIRD_MK=	yes
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if !empty(firebird_ARGS)
FIREBIRD_VER=	${firebird_ARGS}
.endif

FIREBIRD_VER?=	${FIREBIRD_DEFAULT:S/.//}

# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
.if ${FIREBIRD_VER} == 25
LIB_DEPENDS+=	libfbclient.so:databases/firebird25-client
.else
IGNORE=		cannot install: unknown Firebird version: ${FIREBIRD_VER}
.endif
.endif
