# $FreeBSD$
# SSP Support

SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(SSP_UNSAFE) && \
    (${ARCH} == i386 || ${ARCH} == amd64)
# Overridable as a user may want to use -fstack-protector-all
SSP_CFLAGS?=	-fstack-protector
CFLAGS+=	${SSP_CFLAGS}
LDFLAGS+=	-fstack-protector
# -lssp_nonshared is needed on i386 where /usr/lib/libc.so is not an ldscript
# This is currently unused XXX
.	if defined(SSP_NEED_NONSHARED)
LDFLAGS+=	-lssp_nonshared
.	endif
.endif
