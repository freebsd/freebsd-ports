# New ports collection makefile for:	gnatdroid-sysroot
# Date created:				2011-07-20
# Whom:					John Marino <draco@marino>
#
# $FreeBSD$
#

PORTNAME=	sysroot
PORTVERSION=	9
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	android-9-arm

MAINTAINER=	draco@marino.st
COMMENT=	Android-9 sysroot for C/Ada Android cross-compiler

USE_BZIP2=	YES
NO_BUILD=	YES
NO_MTREE=	YES

WRKSRC=		${WRKDIR}/android-${PORTVERSION}-arm
PREFIX=		${LOCALBASE}/android9

do-install:
	(cd ${WRKSRC} && ${FIND} usr/ -type d -exec ${MKDIR} ${PREFIX}/{} \;)
	(cd ${WRKSRC} && ${FIND} usr/ -type f -exec \
	   ${INSTALL} -p -o root -g wheel ${WRKSRC}/{} ${PREFIX}/{} \;)

.include <bsd.port.mk>
