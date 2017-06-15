# Created by: 'Big Bad Bob' Frazier <bobf@mrp3.com>
# $FreeBSD$

PORTNAME=	uarduno
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://mrp3.com/

MAINTAINER=	bobf@mrp3.com
COMMENT=	FreeBSD Kernel Driver for the Arduino Uno USB interface

LICENSE=	BSD4CLAUSE

USES=		kmod uidfix

# some test targets need a predictable source directory
WRKSRC=		${WRKDIR}/uarduno

PLIST_FILES=	${KMODDIR}/uarduno.ko

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
	${MAKE_CMD} patch
	${MAKE_CMD} -C ${WRKSRC} my-clean
	${TAR} -c -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR} uarduno
	${MAKE_CMD} makesum

# partial clean for incremental build and test
uarduno-part-clean:
	-${RM} ${WRKDIR}/.patch_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.configure_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.build_done.uarduno._boot_kernel
	-${RM} ${WRKDIR}/.install_done.uarduno._boot_kernel
	${MAKE_CMD} -C ${WRKSRC} my-clean
	${MAKE_CMD} patch

.include <bsd.port.mk>
