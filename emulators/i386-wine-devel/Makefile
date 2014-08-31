# Created by: David Naylor (dbn@FreeBSD.org)
# $FreeBSD: head/emulators/i386-wine-devel/Makefile 332648 2013-11-03 21:13:34Z dbn $

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
