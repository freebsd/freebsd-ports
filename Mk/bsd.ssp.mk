# $FreeBSD$
# SSP Support

SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

# See: http://svnweb.freebsd.org/base/head/lib/libc/libc.ldscript?revision=251668&view=markup
.if ${OSVERSION} < 1000036 && ${ARCH} == i386

# Disabled on i386 for now on releases without the ldscript as too many ports
# do not respect LDFLAGS and fail to build due to not adding in -lssp_nonshared when needed
# despite dependencies working fine, which breaks a lot. Can enable once LDFLAGS is more
# supported. XXX
SSP_UNSAFE=		yes

# i386 needs -lssp_nonshared, see svn link above for more information
SSP_NEED_NONSHARED=	yes
.endif

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
