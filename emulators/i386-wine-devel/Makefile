# Created by: David Naylor (dbn@FreeBSD.org)
# $FreeBSD$

# Special bootstrapper to allow:
#  - i386 specific port to be slave to ${PORTSDIR}/emulators/wine-devel
#  - amd64 specific port to be normal port (based on binary package)

PORTNAME=	wine
# define a dummy DISTVERSION to avoid errors with poudriere bulk -a
# on architectures unsupported by this port
DISTVERSION?=	0
PKGNAMEPREFIX=	i386-
PKGNAMESUFFIX=	-devel
CATEGORIES=	emulators

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	32-bit Microsoft Windows compatibility environment for 64-bit FreeBSD

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.mk>
