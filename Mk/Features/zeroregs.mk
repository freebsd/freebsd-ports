# Zero call-used registers at function return to increase program
# security by either mitigating Return-Oriented Programming (ROP)
# attacks or preventing information leakage through registers.
# This depends upon support from the compiler for a given architecture.
#
# Variables that can be used:
#
# WITH_ZEROREGS		Enable for all ports.
# WITH_ZEROREGS_PORTS	Enable for specified category/port-name
# ZEROREGS_TYPE		See
# 			https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#index-zero_005fcall_005fused_005fregs-function-attribute
# 			for options
#                       Default: used
#

.if !defined(_ZEROREGS_MK_INCLUDED)
_ZEROREGS_MK_INCLUDED=		yes
ZEROREGS_Include_MAINTAINER=	netchild@FreeBSD.org

ZEROREGS_TYPE?=	used

.  if !defined(ZEROREGS_UNSAFE)
CFLAGS+=	-fzero-call-used-regs=${ZEROREGS_TYPE}
CXXFLAGS+=	-fzero-call-used-regs=${ZEROREGS_TYPE}
.  endif
.endif

