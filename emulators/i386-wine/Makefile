# Created by: David Naylor (dbn@FreeBSD.org)
# $FreeBSD$

# Special bootstrapper to allow:
#  - i386 specific port to be slave to ${PORTSDIR}/emulators/wine
#  - amd64 specific port to be normal port (based on binary package)

PORTNAME=	wine
# define a dummy DISTVERSION to avoid errors with poudriere bulk -a
# on architectures unsupported by this port
DISTVERSION?=	0
PORTREVISION=	1
PKGNAMEPREFIX=	i386-
CATEGORIES=	emulators

MAINTAINER=	nc@FreeBSD.org
COMMENT=	32-bit Microsoft Windows compatibility environment for 64-bit FreeBSD

ONLY_FOR_ARCHS=	i386 amd64

CONFLICTS_INSTALL=	wine-[0-9]* wine-devel-[0-9]* i386-wine-devel-[0-9]*

PKGINSTALL=	${.CURDIR}/files/pkg-install
PKGDEINSTALL=	${PKGINSTALL}

distinfo-update:
	${RM} ${.CURDIR}/distinfo ${.CURDIR}/distinfo~
.for osrel in 11 12 13
	${MAKE} fetch OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${MAKE} makesum OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${CAT} ${.CURDIR}/distinfo >> ${.CURDIR}/distinfo~
	${RM} ${.CURDIR}/distinfo
.endfor
	${SED} -e '2,$${' -e '/^TIMESTAMP/d' -e '}' distinfo~ > ${.CURDIR}/distinfo
	${RM} ${.CURDIR}/distinfo~

.include <bsd.port.mk>
