# New ports collection makefile for:	ltmdm
# Date Created:				Nov 11, 2001
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ltmdm
PORTVERSION=	1.4
PORTREVISION=	10
CATEGORIES=	comms
MASTER_SITES=	http://www.dons.net.au/~darius/ \
		http://soupnazi.org/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for the Lucent LT Winmodem chipset

ONLY_FOR_ARCHS=	i386
BUILD_WRKSRC=	${WRKSRC}/sys/modules/ltmdm
NO_WRKSUBDIR=	yes

LTMDM_DEV_MAJOR		?= 228
LTMDM_OBJ_VERSION	?= 600

.if defined(WITH_595_OBJ)
MAKE_ARGS	= LTMDM_OBJ_VERSION=595
.endif

MAKE_ARGS+=	LTMDM_DEV_MAJOR=${LTMDM_DEV_MAJOR}
MAKE_ARGS+=	LTMDM_OBJ_VERSION=${LTMDM_OBJ_VERSION}

PORTDOCS=	README.TXT README-en.TXT INSTALL.TXT INSTALL-en.TXT

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif
.if !defined(WITH_595_OBJ)
	@${ECHO} "*************************************************";
	@${ECHO} "If your ISP supports K56flex protocol only and   ";
	@${ECHO} " doesn't support V90, define WITH_595_OBJ.       ";
	@${ECHO} "Otheriwse your modem will not connect            ";
	@${ECHO} "*************************************************";
.endif

do-install:
	@${SED} "s:%%PREFIX%%:${PREFIX}:;s:%%MAJOR%%:${LTMDM_DEV_MAJOR}:" \
		< ${FILESDIR}/ltmdm.sh > ${WRKSRC}/ltmdm.sh
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sys/modules/ltmdm/ltmdm.ko ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/ltmdm.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
