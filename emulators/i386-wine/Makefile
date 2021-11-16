# Created by: David Naylor (dbn@FreeBSD.org)

# Special bootstrapper to allow:
#  - i386 specific port to be slave to ${PORTSDIR}/emulators/wine
#  - amd64 specific port to be normal port (based on binary package)

PORTNAME=	wine
# define a dummy DISTVERSION to avoid errors with poudriere bulk -a
# on architectures unsupported by this port
DISTVERSION?=	0
# define PORTREVISION with ?= to allow it to be overriden by
# wine's PORTREVISION when cross building
PORTREVISION=	0
PKGNAMEPREFIX=	i386-
CATEGORIES=	emulators

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	32-bit Microsoft Windows compatibility environment for 64-bit FreeBSD

ONLY_FOR_ARCHS=	i386 amd64

CONFLICTS_INSTALL=	wine-[0-9]* wine-devel-[0-9]*

USES=		cpe
CPE_VENDOR=	winehq

PKGINSTALL=	${.CURDIR}/files/pkg-install
PKGDEINSTALL=	${PKGINSTALL}

distinfo-update:
	${RM} ${.CURDIR}/distinfo ${.CURDIR}/distinfo~
.for osrel in 12 13 14
	${MAKE} fetch OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${MAKE} makesum OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${CAT} ${.CURDIR}/distinfo >> ${.CURDIR}/distinfo~
	${RM} ${.CURDIR}/distinfo
.endfor
	${SED} -e '2,$${' -e '/^TIMESTAMP/d' -e '}' distinfo~ > ${.CURDIR}/distinfo
	${RM} ${.CURDIR}/distinfo~

.include <bsd.port.mk>
