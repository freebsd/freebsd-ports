# handle ports requring sbrk
#
# Feature:	sbrk
# Usage:	USES=sbrk
# Valid ARGS:	<none>
#
# Software requiring the sbrk pseudo-syscall is broken on aarch64 and
# riscv64.  Mark it as such.
#
# MAINTAINER:	brooks@FreeBSD.org

.if !defined(_INCLUDE_USES_SBRK_MK)
_INCLUDE_USES_SBRK_MK=	yes

.  if empty(sbrk_ARGS)
BROKEN_aarch64=	requires sbrk
BROKEN_riscv64=	requires sbrk
.  else
IGNORE=	Incorrect 'USES+=sbrk:${sbrk_ARGS}'.  No arguments permitted
.  endif
.endif
