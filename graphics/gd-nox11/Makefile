# New ports collection makefile for:	gnustep-art
# Date created:		29.Mar.2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

CATEGORIES=	graphics
PKGNAMESUFFIX=		-nox11

MAINTAINER=	dinoex@FreeBSD.org

WITHOUT_X11=		yes
MASTERDIR?=	${.CURDIR}/../gd

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
