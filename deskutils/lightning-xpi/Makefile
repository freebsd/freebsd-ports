# New ports collection makefile for:	thunderbird-lightning
# Date created:		2006-10-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/deskutils/lightning-xpi/Makefile,v 1.4 2006/10/14 00:16:08 ahze Exp $

PORTNAME=	lightning
PORTVERSION=	${ARCH_PORTVERSION}
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
PKGNAMESUFFIX=	-xpi
DISTNAME=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD${OS_VER}-${ARCH}
EXTRACT_SUFX=	.xpi

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated calendar for Thunderbird

CONFLICTS=	lightning-0.[0-9]*
NO_BUILD=	yes
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	 -d ${WRKSRC}
PLIST?=		${WRKDIR}/plist
LIGHTNING_DIR=	lib/thunderbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}
USE_GECKO=	thunderbird
_IGNORE_MSG=	precompiled binaries, contact ahze@FreeBSD.org for build information

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

ARCH_PORTVERSION?=	0.3.1

.if ${ARCH}=="i386"
. if ${OSVERSION} < 600000 && ${OSVERSION} > 500000
OS_VER=	5
. elif ${OSVERSION} > 600000
OS_VER=	6
. else
IGNORE=	${_IGNORE_MSG}
. endif
.elif ${ARCH}=="sparc64"
. if ${OSVERSION} > 600000
OS_VER=	6
ARCH_PORTVERSION=0.5
. else
IGNORE=	${_IGNORE_MSG}
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
