# New ports collection makefile for:	ltmdm
# Date Created:				Nov 11, 2001
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ltmdm
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.dons.net.au/~darius/ \
		http://www.csociety.org/~will/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/

EXTRACT_SUFX=	.tgz

MAINTAINER=	darius@dons.net.au

ONLY_FOR_ARCHS=	i386
BUILD_WRKSRC=	${WRKSRC}/sys/modules/ltmdm
NO_WRKSUBDIR=	yes
.if defined(USE_595_OBJ)
MAKE_ARGS+=	LTMDM_OBJ_VERSION=595
.else
MAKE_ARGS+=	LTMDM_OBJ_VERSION=600
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif
.if !defined(USE_595_OBJ)
	@${ECHO} "*************************************************";
	@${ECHO} "If you have a K56Flex modem define USE_595_OBJ   ";
	@${ECHO} "Otheriwse your modem will not work               ";
	@${ECHO} "*************************************************";
.endif

do-install:
	@${PERL} -pi.orig -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/ltmdm.sh
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sys/modules/ltmdm/ltmdm.ko ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ltmdm.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README-en.TXT ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/INSTALL.TXT ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/INSTALL-en.TXT ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500000
do-patch:
	@${CAT} files/current-fix | ${PATCH}
.endif

.include <bsd.port.post.mk>
