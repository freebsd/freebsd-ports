# New ports collection makefile for:	mwave
# Date Created:				Apr 22 2001
# Whom:					R. Kevin Oberman <oberman@es.net>
#
# $FreeBSD$
#

PORTNAME=	mwavem-fbsd
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	http://oss.software.ibm.com/developer/opensource/linux/projects/mwave/releases/ \
		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	oberman@es.net

LIB_DEPENDS=	lthread.2:${PORTSDIR}/devel/linuxthreads

ONLY_FOR_ARCHS=	i386

STARTUP=	mwave.sh
USE_GMAKE=	yes
SLEEP=		/bin/sleep

.include <bsd.port.pre.mk>

pre-build:
	${PERL} -pi.orig -e "s@f /etc@f ${PREFIX}/etc@g" ${WRKSRC}/Makefile
	${PERL} -pi.orig -e "s@ko /modules@ko ${PREFIX}/share/mwave@g" ${WRKSRC}/drivers/Makefile
	${PERL} -pi.orig -e "s@install -m@install -c -m@g" \
		${WRKSRC}/manager/Makefile ${WRKSRC}/meio/Makefile ${WRKSRC}/mwmbl/Makefile \
		${WRKSRC}/mwmlw32/Makefile ${WRKSRC}/mwmpw32/Makefile ${WRKSRC}/mwmutil/Makefile \
		${WRKSRC}/mwwtt32/Makefile

pre-install:
	${MKDIR} ${PREFIX}/share/mwave

post-install:
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/${STARTUP} startup file."
	@${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP} ${PREFIX}/etc/rc.d/
	strip ${PREFIX}/sbin/mwavem

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@if ! ${LDCONFIG} -r | ${GREP} -qwF -e "-llthreads.2"; then \
	${ECHO} " "; \
	${ECHO} "****************************************************************"; \
	${ECHO} "* This port requires the linuxthreads library. Installation of *"; \
	${ECHO} "* this port requires that the full FreeBSD sources be present  *"; \
	${ECHO} "* on the system.                                               *"; \
	${ECHO} "*                                                              *"; \
	${ECHO} "* If you prefer not oading the full sources, you make install  *"; \
	${ECHO} "* the linuxthreads package from /stand/sysinstall.             *"; \
	${ECHO} "****************************************************************"; \
	${SLEEP} 10; fi;
.endif

.if ${OSVERSION} < 410000
BROKEN=		"Systems prior to 4.1 are not supported"
.endif

.include <bsd.port.post.mk>
