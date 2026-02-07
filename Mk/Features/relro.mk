# RELRO Support
#
# Tells the linker to emit RELocation Read-Only (RELRO) protection for certain
# sections of your ELF file. In short, it makes parts of the binary read-only
# after relocations have been applied at program startup, helping to prevent
# GOT- and PLT-based overwrite attacks.

.if !defined(_RELRO_MK_INCLUDED)
_RELRO_MK_INCLUDED=	yes
RELRO_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(RELRO_UNSAFE)
LDFLAGS+=	-Wl,-zrelro
.  endif
.endif
