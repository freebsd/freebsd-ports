# New ports collection makefile for:	thunderbird-lightning
# Date created:		2006-10-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/deskutils/lightning-xpi/Makefile,v 1.4 2006/10/14 00:16:08 ahze Exp $

PORTNAME=	lightning
PORTVERSION=	${ARCH_PORTVERSION}
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	beat
PKGNAMESUFFIX=	-xpi
DISTNAME=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD${OS_VER}-${ARCH}
EXTRACT_SUFX=	.xpi

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	An integrated calendar for Thunderbird

CONFLICTS=	lightning-0.[0-9]*
NO_BUILD=	yes
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	 -d ${WRKSRC}
PLIST?=		${WRKDIR}/plist
LIGHTNING_DIR=	lib/thunderbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}
USE_GECKO=	thunderbird
_IGNORE_MSG=	precompiled binaries, contact gecko@FreeBSD.org for build information.

.include <bsd.port.pre.mk>

ARCH_PORTVERSION?=	0.9

.if ${ARCH}=="i386"
. if ${OSVERSION} < 600000
OS_VER=	5
ARCH_PORTVERSION=	0.7
. elif ${OSVERSION} >= 600000 && ${OSVERSION} < 700000
OS_VER=	6
. elif ${OSVERSION} >= 700000 && ${OSVERSION} < 800000
OS_VER=	7
. elif ${OSVERSION} >= 800000
OS_VER=	8
. else
IGNORE=	${_IGNORE_MSG}
. endif
.elif ${ARCH}=="sparc64"
. if ${OSVERSION} >= 600000 && ${OSVERSION} < 700000
OS_VER=	6
ARCH_PORTVERSION=	0.5
. elif ${OSVERSION} >= 700000
OS_VER=	7
ARCH_PORTVERSION=	0.5
. else
IGNORE=	${_IGNORE_MSG}
. endif
.elif ${ARCH}=="amd64"
. if ${OSVERSION} < 600000
OS_VER=	5
ARCH_PORTVERSION=	0.7
. elif ${OSVERSION} >= 600000 && ${OSVERSION} < 700000
OS_VER=	6
. elif ${OSVERSION} >= 700000 && ${OSVERSION} < 800000
OS_VER=	7
. elif ${OSVERSION} >= 800000
OS_VER=	8
. endif
.else
IGNORE=	${_IGNORE_MSG}
.endif

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|${LIGHTNING_DIR}/|' >> ${PLIST} && \
		${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${LIGHTNING_DIR}/|' >> ${PLIST}
	${ECHO} "@dirrm ${LIGHTNING_DIR}" >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${LIGHTNING_DIR}
	${CHMOD} 0755 ${PREFIX}/${LIGHTNING_DIR}
	@(cd ${WRKSRC} && ${PAX} -U ${LIBOWN} -G ${LIBGRP} -vrw . ${PREFIX}/${LIGHTNING_DIR})

.include <bsd.port.post.mk>
