# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

MASTERDIR?=	${.CURDIR}/../../lang/gcc32

WANT_SHAREDLIBS=	yes
WANT_THREADS_SUPPORT=	yes
PKGNAMESUFFIX=		-objc

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
