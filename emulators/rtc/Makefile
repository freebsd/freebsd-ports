# New ports collection makefile for:	rtc
# Date created:		28 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rtc
PORTVERSION=	2000.09.22
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd-emulation@FreeBSD.org

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
BROKEN=		"Systems prior to 400013 are out of support"
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
BROKEN=		"Kernel source files required"
.endif

do-fetch:
	@${ECHO} "I don't fetch anything..."

do-extract:
	@${MKDIR} ${WRKSRC}
	@${SED}	-e 's,@@PREFIX@@,${PREFIX},' \
		${FILESDIR}/${STARTUP} > ${WRKDIR}/${STARTUP}
	@cd ${FILESDIR} && ${CP} Makefile *.[ch] ${WRKSRC}/

post-patch:
.if !exists(${SRC_BASE}/sys/compat/linux/linux_ioctl.h)
	${PERL} -i -pe 's,compat(/linux/linux_ioctl\.h),i386$$1,' \
		${WRKSRC}/rtc_linux.c
.endif
	@if ! grep -w dev2unit ${SRC_BASE}/sys/kern/kern_conf.c >/dev/null; \
	then \
		${ECHO} "dev2unit() not found in sys/kern/kern_conf.c.  Using lminor() instead."; \
		${PERL} -i -pe 's,dev2unit,lminor,' ${WRKSRC}/rtc.c; \
	fi

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
