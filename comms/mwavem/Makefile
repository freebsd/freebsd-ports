# New ports collection makefile for:	mwave
# Date Created:				Apr 22 2001
# Whom:					R. Kevin Oberman <oberman@es.net>
#
# $FreeBSD$
#

PORTNAME=	mwavem-fbsd
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	acpmodem
EXTRACT_SUFX=	.tgz

MAINTAINER=	oberman@es.net
COMMENT=	Loadable module and user excutable to support IBM Mwave ACP modem

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
STARTUP=	mwavem.sh
USE_GMAKE=	yes
SLEEP=		/bin/sleep

.include <bsd.port.pre.mk>

LTHREADVERSION=2
.if ${OSVERSION} >= 500035
LTHREADVERSION=	3
.endif
.if ${CC:Mgcc30}!=""
LTHREADVERSION=	3
.endif
.if ${CC:Mgcc31}!=""
LTHREADVERSION=	3
.endif
.if ${CC:Mgcc32}!=""
LTHREADVERSION=	3
.endif
LIB_DEPENDS=	lthread.${LTHREADVERSION}:${PORTSDIR}/devel/linuxthreads

.if ${OSVERSION} >= 500000
EXTRA_PATCHES!= ${ECHO_CMD} ${PKGDIR}/files.5/patch-*
.endif

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C code)"
.endif

pre-build:
	${REINPLACE_CMD} -e "s@ /modules@ ${PREFIX}/share/mwavem@g" \
		${WRKSRC}/src/drivers/Makefile
	${REINPLACE_CMD} -e "s@#include .malloc.h.@@g" \
		${WRKSRC}/src/mwmbl/mwblapi.c \
		${WRKSRC}/src/mwwtt32/mwwttbl.c

pre-install:
	${MKDIR} ${DATADIR}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${RM} -f /dev/mwave
	@${ECHO} "Creating /dev/mwave"
	mknod /dev/mwave c 96 0
.endif
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP} ${PREFIX}/etc/rc.d/
	@${ECHO} "******************************************************************************"; \
	${ECHO} "*                       Driver loading information                           *"; \
	${ECHO} "*                                                                            *"; \
	${ECHO} "* This package includes a device driver in a kernel module. While it is      *"; \
	${ECHO} "* installed in ${PREFIX}/share/mwavem, this results in the initial device   *"; \
	${ECHO} "* probe not seeing the device and possibly reporting errors for the sio      *"; \
	${ECHO} "* device which may be ignored.                                               *"; \
	${ECHO} "*                                                                            *"; \
	${ECHO} "* You may choose to standardize the module loading by copying                *"; \
	${ECHO} "* ${PREFIX}/share/mwavem/mwave.ko into /modules. Then add the               *"; \
	${ECHO} "* mwavedd_load=\"YES\" to /boot/loader.conf. This will load the driver         *"; \
	${ECHO} "* at the start of the bootstrap and it will probe in a normal manner.        *"; \
	${ECHO} "******************************************************************************"; \
	${ECHO} "*                        Known problem!                                      *"; \
	${ECHO} "* If the sio device connected to the modem probe as an 8250 device, the      *"; \
	${ECHO} "* modem will not work. Make sure that the mwavem process is running and      *"; \
	${ECHO} "* reboot the system. It should probe correctly and the modem should be       *"; \
	${ECHO} "* opertional.                                                                *"; \
	${ECHO} "******************************************************************************"; \
	${ECHO} " "
	@${SLEEP} 5

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@if ! ${LDCONFIG} -r | ${GREP} -qwF -e "-llthreads.2"; then \
	${ECHO} " "; \
	${ECHO} "****************************************************************"; \
	${ECHO} "* This port requires the linuxthreads library. Installation of *"; \
	${ECHO} "* this port requires that the full FreeBSD sources be present  *"; \
	${ECHO} "* on the system.                                               *"; \
	${ECHO} "*                                                              *"; \
	${ECHO} "* If you prefer not loading the full sources, you make install *"; \
	${ECHO} "* the linuxthreads package from /stand/sysinstall.             *"; \
	${ECHO} "****************************************************************"; \
	${SLEEP} 10; fi;
.endif

.if ${OSVERSION} < 410000
IGNORE=		Systems prior to 4.1 are not supported
.endif
.if ${OSVERSION} >= 500000
IGNORE=		Only works with FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
