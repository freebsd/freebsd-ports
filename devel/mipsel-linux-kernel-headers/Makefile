# New ports collection makefile for:	mipsel-linxu-kernel-headers
# Date created:		14 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	kernel-headers
PORTVERSION=	2.4.0.t9
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/
PKGNAMEPREFIX=	mipsel-linux-
DISTNAME=	kernel-headers-2.4.0-test9

MAINTAINER=	lev@serebryakov.spb.ru

PATCH_STRIP=	-p1
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	-${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}
	(cd ${WRKSRC} && tar --exclude '*.orig' -cf - *) \
		| (cd ${PREFIX}/${PKGNAMEPREFIX:S/-$//} && tar xf -)
	${LN} -sf ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include/asm-mips \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include/asm

.include <bsd.port.mk>
