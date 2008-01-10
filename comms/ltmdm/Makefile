# New ports collection makefile for:	ltmdm
# Date Created:				Nov 11, 2001
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ltmdm
PORTVERSION=	1.4
PORTREVISION=	19
CATEGORIES=	comms kld
MASTER_SITES=	http://www.dons.net.au/~darius/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for the Lucent LT Winmodem chipset

DEVDIR=		/dev
MODULES_WITH_WORLD?=	yes
ONLY_FOR_ARCHS=	i386
BUILD_WRKSRC=	${WRKSRC}/sys/modules/ltmdm
NO_WRKSUBDIR=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
RESTRICTED=	Unknown license type for binary object file ltmdmobj.o

LTMDM_DEV_MAJOR?=	228
LTMDM_OBJ_VERSION?=	600

.if defined(WITH_595_OBJ)
MAKE_ARGS+=	LTMDM_OBJ_VERSION=595
.endif

MAKE_ARGS+=	LTMDM_DEV_MAJOR=${LTMDM_DEV_MAJOR}
MAKE_ARGS+=	LTMDM_OBJ_VERSION=${LTMDM_OBJ_VERSION}
#MAKE_ENV+=	WERROR=

PORTDOCS=	README.TXT README-en.TXT INSTALL.TXT INSTALL-en.TXT
SYSDIR?=	${SRC_BASE}/sys

PLIST_SUB+=	KMODDIR=${KMODDIR}

pre-fetch:
.if !exists(${SYSDIR}/Makefile)
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
	@${INSTALL_KLD} ${BUILD_WRKSRC}/ltmdm.ko ${KMODDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
