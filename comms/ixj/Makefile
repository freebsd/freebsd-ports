# New ports collection makefile for:	ixj
# Date Created:				Mon Jan 14 2002
# Whom:					Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ixj
PORTVERSION=	1.1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://telepresence.dmem.strath.ac.uk/pub/openh323/
DISTNAME=	ixj_freebsd-${PORTVERSION}

MAINTAINER=	roger@freebsd.org

ONLY_FOR_ARCHS=	i386

WRKSRC=         ${WRKDIR}/ixj_freebsd
USE_REINPLACE=	yes
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
	@${CAT} ${PKGMESSAGE}

header-install: patch
	@${MKDIR} ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/ixjuser.h ${PREFIX}/include/sys
	@${INSTALL_DATA} ${WRKSRC}/telephony.h ${PREFIX}/include/sys

.include <bsd.port.mk>
