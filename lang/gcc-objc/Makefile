# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=		lang
PKGNAMESUFFIX=		-objc

MAINTAINER=	dinoex@FreeBSD.org
.if defined(GNUSTEP_WITH_GCC32)
COMMENT=	GNU Compiler Collection 3.2.3 with threads and shared libs
.else
COMMENT=	GNU Compiler Collection 3.3 with threads and shared libs
.endif

WANT_SHAREDLIBS=	yes
WANT_THREADS_SUPPORT=	yes
WITHOUT_LIBJAVA=	yes
.if defined(GNUSTEP_WITH_GCC32)
MASTERDIR?=		${.CURDIR}/../gcc32
.else
MASTERDIR?=		${.CURDIR}/../gcc33
.endif
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib ${TARGLIB}
LDFLAGS+=		-L${LOCALBASE}/lib

.if defined(GNUSTEP_WITH_GCC32)
CONFLICTS?=		gcc-3.2*
.else
CONFLICTS?=		gcc-3.3*
.endif

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
