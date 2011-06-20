# New ports collection makefile for:	povray-meta
# Date created:		2011-06-19
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	povray-meta
PORTVERSION=	0.1
CATEGORIES=	graphics
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Meta port for all povray ports

NO_BUILD=	yes
PLIST_FILES=	bin/povray

POV_VERSIONS_ALL=	31 36 37
#By default only the following version will be installed and
#link bin/povray -> bin/povray${DEFAULT_VER} will be created.
DEFAULT_VER?=	36
#Additional version can be installed by defining WITH_POVRAY${ver}.
#To change version linked by default define WITH_DEFAULT${ver}.
#Please, note that only one of WITH_DEFAULT* can be set at once.

OPT_POVRAY${DEFAULT_VER}=	on
OPT_DEFAULT${DEFAULT_VER}=	on

.for ver in ${POV_VERSIONS_ALL}
POVRAY${ver}_BIN=	${LOCALBASE}/bin/povray${ver}
POVRAY${ver}_PORT=	graphics/povray${ver}
OPT_POVRAY${ver}?=	off
OPT_DEFAULT${ver}?=	off
OPTIONS+=	POVRAY${ver} "Install graphics/povray${ver}" ${OPT_POVRAY${ver}}
OPTIONS+=	DEFAULT${ver} "Create link bin/povray -> bin/povray${ver}" ${OPT_DEFAULT${ver}}
.endfor

.include <bsd.port.options.mk>

.for ver in ${POV_VERSIONS_ALL}
. if defined(WITH_DEFAULT${ver})
WITH_POVRAY${ver}=	yes
.  if defined(POV_VERSION)
IGNORE=	can't be build: only one default povray can be chosen
.  else
POV_VERSION=	${ver}
.  endif
. endif
. if defined(WITH_POVRAY${ver})
RUN_DEPENDS+=	${POVRAY${ver}_BIN}:${PORTSDIR}/${POVRAY${ver}_PORT}
. endif
.endfor

.if !defined(POV_VERSION)
IGNORE=	can't be build: one default povray must be chosen
.endif

do-install:
	${LN} -s ${POVRAY${POV_VERSION}_BIN} ${PREFIX}/bin/povray

.include <bsd.port.mk>
