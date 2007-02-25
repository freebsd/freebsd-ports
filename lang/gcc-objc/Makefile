# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTEPOCH?=		3
CATEGORIES=		lang
PKGNAMESUFFIX=		-objc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Compiler Collection ${COMMENT2} with threads and shared libs

WITHOUT_JAVA=		yes

DEPRECATED=	please use objc from lang/gcc41
EXPIRATION_DATE=	2007-03-30

.if !defined(GNUSTEP_WITH_GCC32) && !defined(GNUSTEP_WITH_GCC33) && !defined(GNUSTEP_WITH_GCC34)
GNUSTEP_WITH_GCC32=	yes
.endif

.if defined(GNUSTEP_WITH_GCC32)
MASTERDIR?=		${.CURDIR}/../gcc32
CONFLICTS?=		gcc-3.2*
COMMENT2=		3.2.x
WANT_SHAREDLIBS=	yes
WANT_THREADS_SUPPORT=	yes
.endif
.if defined(GNUSTEP_WITH_GCC33)
MASTERDIR?=		${.CURDIR}/../gcc33
CONFLICTS?=		gcc-3.3*
COMMENT2=		3.3.x
BROKEN=			libobjc.so missing
.endif
.if defined(GNUSTEP_WITH_GCC34)
MASTERDIR?=		${.CURDIR}/../gcc34
CONFLICTS?=		gcc-3.4*
COMMENT2=		3.4.x
BROKEN=			libobjc.so missing
.endif

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
