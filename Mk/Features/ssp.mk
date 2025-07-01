# SSP Support
#
# The -fstack-protector-strong flag enables "stack smashing" protection on a
# wider set of functions than the default -fstack-protector, but without the
# full performance cost of -fstack-protector-all. Under the hood it inserts a
# small "canary" value on the stack just before the saved return address; at
# function exit it checks that the canary hasn't been overwritten by a buffer
# overflow. If it has been clobbered, the runtime aborts the program rather
# than returning into corrupted code.

.if !defined(_SSP_MK_INCLUDED)
_SSP_MK_INCLUDED=	yes
SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(SSP_UNSAFE) && \
    (! ${ARCH:Mmips*})
# Overridable as a user may want to use -fstack-protector-all
SSP_CFLAGS?=	-fstack-protector-strong
CFLAGS+=	${SSP_CFLAGS}
.  endif
.endif
