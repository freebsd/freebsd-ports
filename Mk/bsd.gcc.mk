#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.gcc.mk - Support for smarter USE_GCC usage.
#
# Created by: Edwin Groothuis <edwin@freebsd.org>
#
# For port developers:
# If your port needs a specific version of GCC, you can easily specify
# that with the "USE_GCC=" statement. If you need a certain minimal version,
# but don't care if about the upperversion, just the + sign behind
# the version.
#
# For example:
#	USE_GCC=	3.3		# port requires gcc 3.3 to build with.
#	USE_GCC=	3.1+	# port requires gcc 3.1 or later to build with.
#
# If you are wondering what your port exactly does, use "make test-gcc"
# to see some debugging.
#
# $FreeBSD$
#

GCC_Include_MAINTAINER=		portmgr@FreeBSD.org

#
# All GCC versions supported by the ports framework.
# Please keep them in ascending order.
#
GCCVERSIONS=	020702 020801 029500 030100 030200 030301 030402 040000 040100

#
# Versions of GCC shipped.
# The first field if the OSVERSION in which it appeared in the base system.
# The second field is the OSVERSION in which it disappeared from
# the base system.
# The third field is the version as USE_GCC would use.
#
GCCVERSION_020702=	000000 000000 2.7
GCCVERSION_020801=	000000 400012 2.8
GCCVERSION_029500=	400012 500035 2.95
GCCVERSION_030100=	500035 500039 3.1
GCCVERSION_030200=	500039 501103 3.2
GCCVERSION_030301=	501103 502126 3.3
GCCVERSION_030402=	502126 999999 3.4
GCCVERSION_040000=	999999 999999 4.0
GCCVERSION_040100=	999999 999999 4.1

#
# No configurable parts below this.
#

#
# See if we can use a later version
#
_USE_GCC:=	${USE_GCC:S/+//}
.if ${USE_GCC} != ${_USE_GCC}
_GCC_ORLATER:=	true
.endif

#
# Extract the fields from GCCVERSION_ and check if USE_GCC points to a valid
# version.
#
.for v in ${GCCVERSIONS}
. for j in ${GCCVERSION_${v}}
.  if !defined(_GCCVERSION_${v}_L)
_GCCVERSION_${v}_L=	${j}
.  elif !defined(_GCCVERSION_${v}_R)
_GCCVERSION_${v}_R=	${j}
.  elif !defined(_GCCVERSION_${v}_V)
_GCCVERSION_${v}_V=	${j}
.   if ${_USE_GCC}==${j}
_GCCVERSION_OKAY=	true;
.   endif
.  endif
. endfor
.endfor

.if !defined(_GCCVERSION_OKAY)
BROKEN=	"Unknown version of GCC specified (USE_GCC=${USE_GCC})"
.endif

#
# Determine current GCCVERSION
#
.for v in ${GCCVERSIONS}
. if exists(${LOCALBASE}/bin/gcc${_GCCVERSION_${v}_V:S/.//})
_GCC_FOUND${v}=	port
. endif
. if ${OSVERSION} >= ${_GCCVERSION_${v}_L} && ${OSVERSION} < ${_GCCVERSION_${v}_R}
_GCCVERSION:=		${v}
_GCC_FOUND${v}:=	base
. endif
.endfor
.if !defined(_GCCVERSION)
BROKEN=		"Couldn't find your current GCCVERSION (OSVERSION=${OSVERSION})"
.endif

#
# If the GCC package defined in USE_GCC does not exist, but a later
# version is allowed (for example 3.1+), see if there is a later.
# First check if the base installed version is good enough, otherwise
# get the first available version.
#
.if defined(_GCC_ORLATER)
. for v in ${GCCVERSIONS}
.  if ${_USE_GCC} == ${_GCCVERSION_${v}_V}
_GCC_MIN1:=	true
.  endif
.  if defined(_GCC_MIN1) && defined(_GCC_FOUND${v}) && ${_GCC_FOUND${v}}=="base" && !defined(_GCC_FOUND)
_GCC_FOUND:=	${_GCCVERSION_${v}_V}
.  endif
. endfor
. for v in ${GCCVERSIONS}
.  if ${_USE_GCC} == ${_GCCVERSION_${v}_V}
_GCC_MIN2:=	true
.  endif
.  if defined(_GCC_MIN2) && defined(_GCC_FOUND${v}) && !defined(_GCC_FOUND)
_GCC_FOUND:=	${_GCCVERSION_${v}_V}
.  endif
. endfor
.endif
.if defined(_GCC_FOUND)
_USE_GCC:=${_GCC_FOUND}
.endif

#
# Determine if the installed OS already has this GCCVERSION, and if not
# then set BUILD_DEPENDS, CC, CXX and F77
#
.for v in ${GCCVERSIONS}
. if ${_USE_GCC} == ${_GCCVERSION_${v}_V}
.  if ${OSVERSION} < ${_GCCVERSION_${v}_L} || ${OSVERSION} > ${_GCCVERSION_${v}_R}
V:=				${_GCCVERSION_${v}_V:S/.//}
CC:=			gcc${V}
CXX:=			g++${V}
F77:=			g77-${V}
_GCC_BUILD_DEPENDS:=	${CC}
.  endif
. endif
.endfor
.undef V

.if defined(_GCC_BUILD_DEPENDS)
BUILD_DEPENDS+=	${_GCC_BUILD_DEPENDS}:${PORTSDIR}/lang/${_GCC_BUILD_DEPENDS}
.endif

MAKE_ENV+=	CC="${CC}" CXX="${CXX}"

test-gcc:
	@echo USE_GCC=${USE_GCC}
.if defined(_GCC_ORLATER)
	@echo Port can use later versions.
.else
	@echo Port cannot use later versions.
.endif
.for v in ${GCCVERSIONS}
	@echo -n "GCC version: ${_GCCVERSION_${v}_V} "
.if defined(_GCC_FOUND${v})
	@echo -n "(${_GCC_FOUND${v}}) "
.endif
	@echo "- OSVERSION from ${_GCCVERSION_${v}_L} to ${_GCCVERSION_${v}_R}"
#	@echo ${v} - ${_GCC_FOUND${v}} - ${_GCCVERSION_${v}_L} to ${_GCCVERSION_${v}_R} - ${_GCCVERSION_${v}_V}
.endfor
	@echo Using GCC vesion ${_USE_GCC}
	@echo CC:${CC} - CXX:${CXX} - F77:${F77} - BUILD_DEPENDS:${BUILD_DEPENDS}
