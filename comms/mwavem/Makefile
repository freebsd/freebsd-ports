# New ports collection makefile for:	mwave
# Date Created:				Apr 22 2001
# Whom:					R. Kevin Oberman <oberman@es.net>
#
# $FreeBSD$
#

PORTNAME=	mwavem-fbsd
PORTVERSION=	1.2
PORTREVISION=	0
CATEGORIES=	comms
MASTER_SITES=	ftp://www-126.ibm.com/pub/acpmodem/ \
		http://www.escape.com/~simonw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oberman@es.net

LIB_DEPENDS=	lthread.2:${PORTSDIR}/devel/linuxthreads

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
STARTUP=	mwavem.sh
USE_GMAKE=	yes
SLEEP=		/bin/sleep

.include <bsd.port.pre.mk>

pre-build:
	${PERL} -pi.orig -e "s@/etc/mwavem@${PREFIX}/etc/mwavem@g" ${WRKSRC}/modem.c
	${PERL} -pi.orig -e "s@ko /modules@ko ${PREFIX}/share/mwave@g" ${WRKSRC}/drivers/Makefile

pre-install:
	${MKDIR} ${DATADIR}

post-install:
	@${RM} -f /dev/mwave
	@${ECHO} "Creating /dev/mwave"
	mknod /dev/mwave c 96 0
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP} ${PREFIX}/etc/rc.d/
	@${ECHO} "******************************************************************************"; \
	${ECHO} "*                       Driver loading information                           *"; \
	${ECHO} "*                                                                            *"; \
	${ECHO} "* This package includes a device driver in a kernel module. While it is      *"; \
	${ECHO} "* installed in ${PREFIX}/share/mwave, this results in the initial device    *"; \
	${ECHO} "* probe not seeing the device and possibly reporting errors for the sio      *"; \
	${ECHO} "* device which may be ignored.                                               *"; \
	${ECHO} "*                                                                            *"; \
	${ECHO} "* It may also result in the serial device being probed at a 8250 instead of  *"; \
	${ECHO} "* a 16550A as the probe may occur before he device is fully initialized. If  *"; \
	${ECHO} "* this happens you must re-boot to get the modem to work.                    *"; \
	${ECHO} "*                                                                            *"; \
	${ECHO} "* You can eliminate this problem by copying ${PREFIX}/share/mwave/mwavedd.ko*"; \
	${ECHO} "* into /modules. Then add the line:                                          *"; \
	${ECHO} "* mwavedd_load=\"YES\"                                                         *"; \
	${ECHO} "* to /boot/loader.conf. This will load the driver at the start of the        *"; \
	${ECHO} "* bootstrap and it will probe in a normal manner.                            *"; \
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
BROKEN=		"Systems prior to 4.1 are not supported"
.endif

.include <bsd.port.post.mk>
