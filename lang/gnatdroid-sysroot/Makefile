# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	19
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	android-${PORTVERSION}-arm

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Android-${PORTVERSION} sysroot for C/Ada Android cross-compiler

USES=		tar:bzip2
NO_BUILD=	YES
NO_MTREE=	YES

WRKSRC=		${WRKDIR}/android-${PORTVERSION}-arm
PREFIX=		${LOCALBASE}/android${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} usr ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
