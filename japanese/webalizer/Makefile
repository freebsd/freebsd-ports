# New ports collection makefile for:	webalizer2
# Date created:		28.Jan 2002
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

CATEGORIES=	japanese
PKGNAMEPREFIX?=	ja-

MAINTAINER=	dinoex@FreeBSD.org

WEBALIZER_LANG=	japanese
MASTERDIR?=	${.CURDIR}/../../www/webalizer

OPTIONS=	WEBALIZER_CONV "Use character code convert patch" off

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
