# New ports collection makefile for:	rtc
# Date created:		28 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rtc
PORTVERSION=	2000.03.28
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd-emulation@FreeBSD.org

WRKSRC=		${WRKDIR}/files

LINUX_DIR=	/compat/linux
KMODDIR=	${PREFIX}/modules

CDEV_MAJOR=	202
DEVFILE=	/dev/rtc

STARTUP=	rtc.sh
MAKE_ARGS=	KMODDIR="${KMODDIR}" CDEV_MAJOR="${CDEV_MAJOR}"
PLIST_SUB=	DEVFILE="${DEVFILE}" CDEV_MAJOR="${CDEV_MAJOR}" RTC_H_DIR="${RTC_H_DIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
BROKEN=         "Systems prior to 400013 is out of support"
.endif

.if !exists(/sys/Makefile)
BROKEN=         "Kernel source files required"
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

post-install:
	${RM} -f ${DEVFILE}
	mknod ${DEVFILE} c ${CDEV_MAJOR} 0
	${INSTALL_DATA} ${WRKSRC}/rtc.h ${PREFIX}/include/
	${MKDIR} ${PREFIX}/share/examples/rtc
	${INSTALL_DATA} ${WRKSRC}/test.c ${PREFIX}/share/examples/rtc/
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file.";
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP} ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
