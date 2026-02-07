# The STACK_AUTOINIT feature mimics the corresponding FreeBSD basesystem feature.
#
# This enables a compiler specific option to automatically initialize
# local (automatic) variables to prevent the use of uninitialized memory.
#
# Variables that can be used:
#
# WITH_STACK_AUTOINIT		Enable for all ports.
# WITH_STACK_AUTOINIT_PORTS	Enable for specified category/port-name
# STACK_AUTOINIT_TYPE		Valid options: zero (default), pattern, uninitialized
#

.if !defined(_STACK_AUTOINIT_MK_INCLUDED)
_STACK_AUTOINIT_MK_INCLUDED=		yes
STACK_AUTOINIT_Include_MAINTAINER=	netchild@FreeBSD.org

STACK_AUTOINIT_TYPE?=	zero

.  if !defined(STATIC_AUTOINIT_UNSAFE)
CFLAGS+=	-ftrivial-auto-var-init=${STACK_AUTOINIT_TYPE}
CXXFLAGS+=	-ftrivial-auto-var-init=${STACK_AUTOINIT_TYPE}
.  endif
.endif
