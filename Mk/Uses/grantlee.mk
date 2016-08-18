# $FreeBSD$
#
# Handle dependency on grantlee
#
# Feature:	grantlee
# Usage:	USES=grantlee:ARGS
# Valid ARGS:	<version>,selfbuild
#
# version	The chooseable versions are 4 and 5.
#		USES=grantlee:4 # Use grantlee 0.x (qt4-based)
#		USES=grantlee:5 # Use grantlee 5.x (qt5-based)
#
# selfbuild	Used in devel/grantlee and devel/grantlee5 to suck in versions
#		but not LIB_DEPENDS.
#
# Using USES=grantlee:ARGS will export some usesful variables and plist subs
# Variables:
# 		GRANTLEE_VERSION	- the version of the chosen grantlee
# Subs:
#		GRANTLEE_VERSION_FULL	- full version of the chosen grantlee
#		GRANTLEE_VERSION_SHORT	- short version of the chosen grantlee
#
# Further it will also append the proper LIB_DEPENDS line.
#
# MAINTAINER: kde@FreeBSD.org
#

.if ! defined(_INCLUDE_USES_GRANTLEE_MK)
_INCLUDE_USES_GRANTLEE_MK=	YES

GRANTLEE_SUPPORTED=	4 5

GRANTLEE4_VER=	0.5.1
GRANTLEE5_VER=	5.1.0

GRANTLEE4_LIB_DEPEND=	libgrantlee_gui.so:devel/grantlee
GRANTLEE5_LIB_DEPEND=	libGrantlee_Templates.so:devel/grantlee5

_grantlee_version=	#
.  for ver in ${GRANTLEE_SUPPORTED:O:u}
.    if ${grantlee_ARGS:M${ver}}
.      if empty(_grantlee_version)
_grantlee_version=	${ver}
.      else
IGNORE=		Incorrect USES=grantlee:${grantlee_ARGS} - multiple versions defined
.      endif
.    endif
.  endfor

.  if empty(_grantlee_version)
IGNORE=		Incorrect USES=grantlee:${grantlee_ARGS} - no version defined
.  endif

# Export the version of the chosen grantlee port
GRANTLEE_VERSION=	${GRANTLEE${_grantlee_version}_VER}

# Append the correct LIB_DEPENDS
.  if empty(grantlee_ARGS:Mselfbuild)
LIB_DEPENDS+=	${GRANTLEE${_grantlee_version}_LIB_DEPEND}
.  endif

# Export the plist substitutions
PLIST_SUB+=	GRANTLEE_VERSION_FULL=${GRANTLEE_VERSION} \
		GRANTLEE_VERSION_SHORT=${GRANTLEE_VERSION:R}

.endif
