# New ports collection makefile for:	ltmdm
# Date Created:				Nov 11, 2001
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ltmdm
PORTVERSION=	1.2
CATEGORIES=	comms
MASTER_SITES=	http://www.csociety.org/~will/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/ \
		http://www.gsoft.com.au/~doconnor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darius@dons.net.au

ONLY_FOR_ARCHS=	i386
BUILD_WRKSRC=	${WRKSRC}/sys/modules/ltmdm
NO_WRKSUBDIR=	yes

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO} "This port requires the kernel source be available"; \
	${ECHO} "*************************************************"; \
	exit 1
.endif

do-install:
	@${PERL} -pi.orig -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/ltmdm.sh
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sys/modules/ltmdm/ltmdm.ko ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ltmdm.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
