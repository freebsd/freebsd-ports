# New ports collection makefile for:  BitchX
# Date created:                   Mon Jan  8 2001
# Whom:                           clive
#
# $FreeBSD$
#

MASTERDIR=      ${.CURDIR}/../../irc/bitchx
EXTRA_PATCHES=	${.CURDIR}/files/patch-source::input.c \
		${.CURDIR}/files/patch-include::config.h \
		${.CURDIR}/files/patch-source::screen.c

WITH_LATIN=	yes

.include "${MASTERDIR}/Makefile"

PORTNAME=	BitchX
PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-
CATEGORIES=	chinese irc

MAINTAINER=	clive@FreeBSD.org

