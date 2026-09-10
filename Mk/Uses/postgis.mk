# Provide support for PostGIS
#
# Feature:	postgis
# Usage:	USES=	postgis[:version] pgsql
#
# version	PostGIS version to depend on.  Valid versions are 33, 34,
#		35, 36 and 37.  If omitted, POSTGIS_DEFAULT is used.
#
# WANT_POSTGIS may contain build and/or run to select the dependency type.
# The default is run.
#
# postgis must appear before pgsql in USES so that the PostgreSQL version
# constraint required by the selected PostGIS version is applied first.
#
# MAINTAINER: lbartoletti@FreeBSD.org

.if !defined(_INCLUDE_USES_POSTGIS_MK)
_INCLUDE_USES_POSTGIS_MK=	yes

_VALID_POSTGIS_VER=	33 34 35 36 37

.  if defined(_INCLUDE_USES_PGSQL_MK)
BROKEN=		USES=postgis must appear before USES=pgsql
.  endif

.  if empty(postgis_ARGS)
POSTGIS_VER=	${POSTGIS_DEFAULT}
.  elif ${postgis_ARGS:[#]} != 1 || empty(_VALID_POSTGIS_VER:M${postgis_ARGS})
IGNORE=		Invalid PostGIS version ${postgis_ARGS}; valid versions are ${_VALID_POSTGIS_VER}
.  else
POSTGIS_VER=	${postgis_ARGS}
.  endif

.  if empty(_VALID_POSTGIS_VER:M${POSTGIS_DEFAULT})
IGNORE=		Invalid POSTGIS default version ${POSTGIS_DEFAULT}; valid versions are ${_VALID_POSTGIS_VER}
.  endif

_POSTGIS_PGSQL_RANGE_33=	14-17
_POSTGIS_PGSQL_RANGE_34=	14-17
_POSTGIS_PGSQL_RANGE_35=	14-18
_POSTGIS_PGSQL_RANGE_36=	14-18
_POSTGIS_PGSQL_RANGE_37=	14-19

.  if defined(pgsql_ARGS) && !empty(pgsql_ARGS)
BROKEN=		USES=postgis supplies the PostgreSQL version constraint; do not add arguments to USES=pgsql
.  else
pgsql_ARGS=	${_POSTGIS_PGSQL_RANGE_${POSTGIS_VER}}
.  endif

WANT_POSTGIS?=	run
_POSTGIS_DEP=	${LOCALBASE}/share/postgresql/extension/postgis.control:databases/postgis${POSTGIS_VER}

.  if ${WANT_POSTGIS:Mbuild}
BUILD_DEPENDS+=	${_POSTGIS_DEP}
.  endif
.  if ${WANT_POSTGIS:Mrun}
RUN_DEPENDS+=	${_POSTGIS_DEP}
.  endif
.  if empty(WANT_POSTGIS:Mbuild) && empty(WANT_POSTGIS:Mrun)
BROKEN=		Invalid WANT_POSTGIS value: ${WANT_POSTGIS}; valid values are build and run
.  endif

.endif
