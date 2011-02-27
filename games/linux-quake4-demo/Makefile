# New ports collection makefile for:	linux-quake4-demo
# Date created:				19 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	quake4
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	IDSOFTWARE/${PORTNAME}/demo GENTOO/distfiles
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX}${PORTVERSION}${PKGNAMESUFFIX}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 4 for Linux Demo

USE_LINUX=	yes
USE_LINUX_APPS=	sdl12
NO_WRKSUBDIR=	yes
NO_CDROM=	Redistribution is limited, see license
NO_PACKAGE=	Package will be 337MB, set FORCE_PACKAGE if you really want it

Q4DIR=		lib/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	Q4DIR="${Q4DIR}"

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
.for FILE in quake4 q4ded
	@${SED} \
		-e 's|@Q4DIR@|${PREFIX}/${Q4DIR}|' \
		-e 's|@APP@|${FILE}.x86|' \
		${FILESDIR}/run.sh.in > ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh
.endfor

do-install:
	${MKDIR} ${PREFIX}/${Q4DIR}/q4base
.for FILE in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAMEPREFIX}${FILE}.sh \
		${PREFIX}/bin/${PKGNAMEPREFIX}${FILE}-demo
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/${FILE}.x86 \
		${PREFIX}/${Q4DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/q4base/* ${PREFIX}/${Q4DIR}/q4base

.include <bsd.port.mk>
