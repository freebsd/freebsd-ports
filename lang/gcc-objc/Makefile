# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=		lang
PKGNAMESUFFIX=		-objc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Compiler Collection ${COMMENT2} with threads and shared libs

WANT_SHAREDLIBS=	yes
WITHOUT_LIBJAVA=	yes
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib ${TARGLIB}
LDFLAGS+=		-L${LOCALBASE}/lib

.if !defined(GNUSTEP_WITH_GCC32) && !defined(GNUSTEP_WITH_GCC33) && !defined(GNUSTEP_WITH_GCC34)
GNUSTEP_WITH_GCC33=	yes
.endif

.if defined(GNUSTEP_WITH_GCC32)
MASTERDIR?=		${.CURDIR}/../gcc32
CONFLICTS?=		gcc-3.2*
COMMENT2=		3.2.x
WANT_THREADS_SUPPORT=	yes
.endif
.if defined(GNUSTEP_WITH_GCC33)
MASTERDIR?=		${.CURDIR}/../gcc33
CONFLICTS?=		gcc-3.3*
COMMENT2=		3.3.x
.endif
.if defined(GNUSTEP_WITH_GCC34)
MASTERDIR?=		${.CURDIR}/../gcc34
CONFLICTS?=		gcc-3.4*
COMMENT2=		3.4.x
.endif

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

MAKE_ENV+=		LD_LIBRARY_PATH=.:${WRKSRC}/gcc

.include "${MASTERDIR}/Makefile"
