# New ports collection makefile for:    p-interp
# Date created:         21 Aug 2001
# Whom:                 Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	p-interp
PORTVERSION=	0.5
CATEGORIES=	emulators
MASTER_SITES=	http://www.klebsch.de/ \
		ftp://ftp.apple.asimov.net/pub/apple_II/images/utility/programming/apple_pascal/:disks \
		ftp://ftp1.au.apple.asimov.net/pub/apple2/images/utility/programming/apple_pascal/:disks

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apple_pascal_0.dsk.gz:disks apple_pascal_1.dsk.gz:disks \
		apple_pascal_2.dsk.gz:disks apple_pascal_3.dsk.gz:disks
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A UCSD (Apple) Pascal p-code interpreter environment

BUILD_DEPENDS=	gccmakedep:${X_IMAKE_PORT}

USE_XLIB=	yes

RESTRICTED=	"Redistribution rights for Apple Pascal disk images are unclear"

MAN1=	ucsd.1 svolio.1 svolcvt.1

.include <bsd.port.pre.mk>

post-extract:
		@${CP} ${DISTDIR}/apple_pascal_?.dsk.gz ${WRKDIR}/${DISTNAME}
		@${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}/apple_pascal_?.dsk.gz

pre-build:
		cd ${WRKDIR}/${DISTNAME} && ${MAKE} depend

post-build:
		cd ${WRKDIR}/${DISTNAME} && ${MAKE} work.svol

pre-install:
		${MKDIR} ${PREFIX}/share/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/COPYING ${PREFIX}/share/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/system.svol ${PREFIX}/share/p-interp
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/work.svol ${PREFIX}/share/p-interp

.include <bsd.port.post.mk>
