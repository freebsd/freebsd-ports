# New ports collection makefile for:	rtc
# Date created:		28 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rtc
PORTVERSION=	2003.01.28.1
PORTREVISION=	1	
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Kernel module which provides /dev/rtc device support

WRKSRC=		${WRKDIR}/files

USE_LINUX=	yes

KMODDIR=	${PREFIX}/modules

CDEV_MAJOR=	202
DEVDIR=		${LINUXBASE}/dev

STARTUP=	rtc.sh
MAKE_ARGS=	KMODDIR="${KMODDIR}" CDEV_MAJOR="${CDEV_MAJOR}"
PLIST_SUB=	DEVDIR="${DEVDIR}" CDEV_MAJOR="${CDEV_MAJOR}" RTC_H_DIR="${RTC_H_DIR}"

SRC_BASE?=	/usr/src

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
IGNORE=		"Systems prior to 400013 are out of support"
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		"Kernel source files required"
.endif

do-fetch:
	@${ECHO} "I don't fetch anything..."

do-extract:
	@${MKDIR} ${WRKSRC}
	@${SED}	-e 's,@@PREFIX@@,${PREFIX},' \
		${FILESDIR}/${STARTUP} > ${WRKDIR}/${STARTUP}
	@cd ${FILESDIR} && ${CP} Makefile *.[ch] ${WRKSRC}/

pre-install:
	${MKDIR} ${KMODDIR}
	${MKDIR} ${DEVDIR}

post-install:
	${RM} -f ${DEVDIR}/rtc
	mknod ${DEVDIR}/rtc c ${CDEV_MAJOR} 0
	${INSTALL_DATA} ${WRKSRC}/rtc.h ${PREFIX}/include/
	${MKDIR} ${PREFIX}/share/examples/rtc
	${INSTALL_DATA} ${WRKSRC}/test.c ${PREFIX}/share/examples/rtc/
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file.";
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP} ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
