# New ports collection makefile for:	gnustep-objc
# Date created:		28.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=		lang
PKGNAMESUFFIX=		-objc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Compiler Collection 3.3 with threads and shared libs

WANT_SHAREDLIBS=	yes
WANT_THREADS_SUPPORT=	yes
WITHOUT_LIBJAVA=	yes
MASTERDIR?=		${.CURDIR}/../gcc33
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		%%PREFIX%%/lib ${TARGLIB}
LDFLAGS+=		-L${LOCALBASE}/lib

CONFLICTS?=		gcc-3.3*

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
