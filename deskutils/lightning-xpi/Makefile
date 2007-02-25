# New ports collection makefile for:	thunderbird-lightning
# Date created:		2006-10-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/deskutils/lightning-xpi/Makefile,v 1.4 2006/10/14 00:16:08 ahze Exp $

PORTNAME=	lightning
PORTVERSION=	${ARCH_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ahze
PKGNAMESUFFIX=	-xpi
DISTNAME=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD-${ARCH}
EXTRACT_SUFX=	.xpi

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated calendar for Thunderbird

CONFLICTS=	lightning-0.[0-9]*
ONLY_FOR_ARCHS=	i386 sparc64
NO_BUILD=	yes
USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	 -d ${WRKSRC}
PLIST?=		${WRKDIR}/plist
LIGHTNING_DIR=	lib/thunderbird/extensions/{e2fda1a4-762b-4020-b5ad-a41df1933103}
USE_GECKO=	thunderbird

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

.if ${OSVERSION} < 600000
IGNORE=	precompiled binaries for 6.x
.endif

.if ${ARCH}=="i386"
ARCH_PORTVERSION=	0.3.1
.elif ${ARCH}=="sparc64"
ARCH_PORTVERSION=	0.3
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

.if defined(MAKESUM)
.undef DISTNAME
.for arch in ${ONLY_FOR_ARCHS}
DISTFILES+=	${PORTNAME}-${PORTVERSION}-tb-FreeBSD-${arch}${EXTRACT_SUFX}
.endfor
.endif

.include <bsd.port.post.mk>
