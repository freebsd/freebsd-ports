# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	9
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	android-9-arm

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Android-9 sysroot for C/Ada Android cross-compiler

USE_BZIP2=	YES
NO_BUILD=	YES
NO_MTREE=	YES

WRKSRC=		${WRKDIR}/android-${PORTVERSION}-arm
PREFIX=		${LOCALBASE}/android9

do-install:
	(cd ${WRKSRC} && ${FIND} usr/ -type d -exec ${MKDIR} ${STAGEDIR}${PREFIX}/{} \;)
	(cd ${WRKSRC} && ${FIND} usr/ -type f -exec \
	   ${INSTALL} -p -o root -g wheel ${WRKSRC}/{} ${STAGEDIR}${PREFIX}/{} \;)

.include <bsd.port.mk>
