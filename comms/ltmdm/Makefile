# New ports collection makefile for:	ltmdm
# Date Created:				Nov 11, 2001
# Whom:					Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	ltmdm
PORTVERSION=	1.4
PORTREVISION=	18
CATEGORIES=	comms kld
MASTER_SITES=	http://www.dons.net.au/~darius/
EXTRACT_SUFX=	.tgz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Driver for the Lucent LT Winmodem chipset

DEVDIR=		${DESTDIR}/dev
MODULES_WITH_WORLD?=	yes
ONLY_FOR_ARCHS=	i386
BUILD_WRKSRC=	${WRKSRC}/sys/modules/ltmdm
NO_WRKSUBDIR=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
RESTRICTED=	"Unknown license type for binary object file ltmdmobj.o"

LTMDM_DEV_MAJOR?=	228
LTMDM_OBJ_VERSION?=	600

.if defined(WITH_595_OBJ)
MAKE_ARGS+=	LTMDM_OBJ_VERSION=595
.endif

MAKE_ARGS+=	LTMDM_DEV_MAJOR=${LTMDM_DEV_MAJOR}
MAKE_ARGS+=	LTMDM_OBJ_VERSION=${LTMDM_OBJ_VERSION}
#MAKE_ENV+=	WERROR=
STRIP=		# do not strip kernel module

PORTDOCS=	README.TXT README-en.TXT INSTALL.TXT INSTALL-en.TXT
SYSDIR?=	${SRC_BASE}/sys

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
MAJOR=		${LTMDM_DEV_MAJOR}
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
PLIST_SUB+=	MAJOR=${MAJOR}
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif
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
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ltmdm.ko ${KMODDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.if ${OSVERSION} < 500000
	@${RM} -f ${DEVDIR}/cual0 ${DEVDIR}/cuail0 ${DEVDIR}/cuall0
	@umask 7
	@mknod ${DEVDIR}/cual0 c ${MAJOR} 128 uucp:dialer
	@mknod ${DEVDIR}/cuail0 c ${MAJOR} 160 uucp:dialer
	@mknod ${DEVDIR}/cuall0 c ${MAJOR} 192 uucp:dialer
	@${RM} -f ${DEVDIR}/ttyl0 ${DEVDIR}/ttyil0 ${DEVDIR}/ttyll0
	@umask 77
	@mknod ${DEVDIR}/ttyl0 c ${MAJOR} 0 uucp:dialer
	@mknod ${DEVDIR}/ttyil0 c ${MAJOR} 32 uucp:dialer
	@mknod ${DEVDIR}/ttyll0 c ${MAJOR} 64 uucp:dialer
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
