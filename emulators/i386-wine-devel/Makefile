# Created by: David Naylor (dbn@FreeBSD.org)
# $FreeBSD$

# Special bootstrapper to allow:
#  - i386 specific port to be slave to ${PORTSDIR}/emulators/wine-devel
#  - amd64 specific port to be normal port (based on binary package)

.if !defined(ARCH)
ARCH!=		uname -p
.endif

.if ${ARCH} == i386
.include "${.CURDIR}/Makefile.i386"
.else
.include "${.CURDIR}/Makefile.inc"
.endif
