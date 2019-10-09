# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rtc
PORTVERSION=	2004.02.24.1
PORTREVISION=	8
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Kernel module which provides /dev/rtc device support

BROKEN_FreeBSD_12=	fails to compile: rtc.c:166:2: implicit declaration of function 'MALLOC' is invalid in C99
BROKEN_FreeBSD_13=	fails to compile: rtc.c:166:2: implicit declaration of function 'MALLOC' is invalid in C99

WRKSRC=		${WRKDIR}/files

KMODDIR=	${PREFIX}/modules

CDEV_MAJOR=	202
DEVDIR=		${LINUXBASE}/dev

STARTUP=	rtc.sh
MAKE_ARGS=	KMODDIR="${KMODDIR}" CDEV_MAJOR="${CDEV_MAJOR}"
PLIST_SUB=	DEVDIR="${DEVDIR}" CDEV_MAJOR="${CDEV_MAJOR}" \
		RTC_H_DIR="${RTC_H_DIR}"

USES=		kmod linux uidfix

do-extract:
	@${MKDIR} ${WRKSRC}
	@${SED}	-e 's,@@PREFIX@@,${PREFIX},' \
		${FILESDIR}/${STARTUP} > ${WRKDIR}/${STARTUP}
	@cd ${FILESDIR} && ${CP} Makefile *.[ch] ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/rtc.h ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.c ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file.";
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP} ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
