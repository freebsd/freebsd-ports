# New ports collection makefile for:	ixj
# Date Created:				Mon Jan 14 2002
# Whom:					Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ixj
PORTVERSION=	1.1.0
CATEGORIES=	comms
MASTER_SITES=	http://ftp.osuosl.org/pub/FreeBSD/distfiles/
DISTNAME=	ixj_freebsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for Quicknet Internet PhoneJack and LineJack. Used by OpenH323

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
IGNORE=	cannot be installed since the driver has not been updated for 5.x kernels. Still uses machine/ipl.h
.endif

WRKSRC=		${WRKDIR}/ixj_freebsd
MAKEFILE=	Makefile.BSD

post-patch:
	${CP} ${FILESDIR}/ixj.sh ${WRKSRC}
	${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/ixj.sh

pre-build:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO} "This port requires the kernel source be available"; \
	${ECHO} "*************************************************"; \
	exit 1
.endif

do-install:
	@${MKDIR} ${PREFIX}/modules
	@${INSTALL_DATA} ${WRKSRC}/ixj.ko ${PREFIX}/modules
	@${MKDIR} ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/ixjuser.h ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/telephony.h ${PREFIX}/include/sys
	@${INSTALL_SCRIPT} ${WRKSRC}/ixj.sh ${PREFIX}/etc/rc.d/
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

header-install:	patch
	@${MKDIR} ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/ixjuser.h ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/telephony.h ${PREFIX}/include/sys

.include <bsd.port.post.mk>
