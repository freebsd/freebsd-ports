# Created by: 'Big Bad Bob' Frazier <bobf@mrp3.com>
# $FreeBSD$

PORTNAME=	uarduno
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://mrp3.com/

MAINTAINER=	bobf@mrp3.com
COMMENT=	FreeBSD Kernel Driver for the Arduino Uno USB interface

# no license required
LICENSE=		BSD2CLAUSE

NO_LICENSES_INSTALL=	yes
NO_LICENSES_DIALOGS=	yes

USES=		kmod uidfix

# some test targets need a predictable source directory
WRKSRC=		${WRKDIR}/uarduno

PLIST_FILES=	"${KMODDIR}/uarduno.ko"

#
# make sure I correctly identify the OS version
#
CFLAGS+=	-DKERNELVER=${OSVERSION}

# post-patch target, copy 'ids.txt' as 'ids.h' (user-modifiable file)
post-patch:
	@${CP} ${FILESDIR}/ids.txt ${WRKSRC}/ids.h

#
# these next 2 targets are for developer use
#
# building a source tarball and related files
uarduno-src-tarball:
	${MAKE} patch
	${MAKE} -C ${WRKSRC} my-clean
	tar -c -f ${PORTSDIR}/distfiles/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR} uarduno
	${MAKE} makesum

# partial clean for incremental build and test
uarduno-part-clean:
	-${RM} ${WRKDIR}/.patch_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.configure_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.build_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.install_done.uarduno._boot_kernel
	${MAKE} -C ${WRKSRC} my-clean
	${MAKE} patch

.include <bsd.port.mk>
