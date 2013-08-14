# Created by: 'Big Bad Bob' Frazier <bobf@mrp3.com>
# $FreeBSD$

PORTNAME=	uarduno
PORTVERSION=	1.02
CATEGORIES=	comms kld
MASTER_SITES=	http://mrp3.com/

MAINTAINER=	bobf@mrp3.com
COMMENT=	FreeBSD Kernel Driver for the Arduino Uno USB interface

NO_PACKAGE=	You must (re)build this port with your kernel source

# need to enforce installation into kernel module directory
MAKE_ENV+=	KMODDIR=${KMODDIR}
PREFIX=		${KMODDIR}

.include <bsd.port.pre.mk>

SRCPREFIX?=	${SRC_BASE}

# disable mtree or you'll get a /boot/kernel/... directory hierarchy put there
NO_MTREE= yes

# some test targets need a predictable source directory
WRKSRC=		${WRKDIR}/uarduno

PLIST_FILES=	uarduno.ko \
		"@unexec kldxref ${KMODDIR}"

# no license required
LICENSE=		BSD
NO_LICENSES_INSTALL=	yes
NO_LICENSES_DIALOGS=	yes

#
# version 7xxxx and 8xxxx are very different
# so make sure I correctly identify them
#
CFLAGS+=	-DKERNELVER=${OSVERSION}

.if ${OSVERSION} < 800000
# Simple check for 7.x kernel source (find usb.c)
.if ! exists(${SRCPREFIX}/sys/dev/usb/usb.c)
IGNORE=	this port will not build without the latest 7.x kernel source
.endif
.else
# 8.x and later kernels (partially tested in 9.x, mabye add to kernel?)
# simple check for 8.x and later kernel source (find usb_core.c)
.if ! exists(${SRCPREFIX}/sys/dev/usb/usb_core.c)
IGNORE=	this port will not build without the latest kernel source
.endif
.endif

# post-patch target, copy 'ids.txt' as 'ids.h' (user-modifiable file)
post-patch:
	@${CP} ${FILESDIR}/ids.txt ${WRKSRC}/ids.h

# post-install target, make sure kernel module is unloaded
post-install:
	@if kldstat -q -m uhub/uarduno ; then \
	 echo "" ; echo " +++ Unloading uarduno.ko (related devices will need to be re-attached)" ; kldunload uarduno ; fi
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

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

.include <bsd.port.post.mk>
