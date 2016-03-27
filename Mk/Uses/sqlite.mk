# $FreeBSD$
#
# Provide support for SQLite
# Feature:	sqlite
# Usage:	USES=	sqlite[:version]
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_SQLITE_MK)
_INCLUDE_USES_SQLITE_MK=	yes

.if !empty(sqlite_ARGS)
SQLITE_VER=	${sqlite_ARGS}
.endif
SQLITE_VER?=	3

.if ${SQLITE_VER} == 3
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite${SQLITE_VER}
.elif ${SQLITE_VER} == 2
LIB_DEPENDS+=	libsqlite.so:databases/sqlite${SQLITE_VER}
.else
IGNORE=		cannot install: unknown SQLite version: ${SQLITE_VER}
.endif

.endif
