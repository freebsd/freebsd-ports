# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=		lang
PKGNAMESUFFIX=		-objc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Compiler Collection 3.2.3 with threads and shared libs

WANT_SHAREDLIBS=	yes
WANT_THREADS_SUPPORT=	yes
MASTERDIR?=		${.CURDIR}/../gcc32
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib ${TARGLIB}
LDFLAGS+=		-L${LOCALBASE}/lib

# does not build on:
NOT_FOR_ARCHS=		amd64

CONFLICTS?=		gcc-3.2*

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
