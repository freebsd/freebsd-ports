# New ports collection makefile for:  BitchX
# Date created:                   Mon Jan  8 2001
# Whom:                           clive
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTREVISION=	5
CATEGORIES=	chinese

MAINTAINER=	clive@FreeBSD.org
COMMENT=	A zh-tw cursor movement friendly, wrapping clean BitchX

MASTERDIR=	${.CURDIR}/../../irc/bitchx
EXTRA_PATCHES=	${.CURDIR}/files/patch-source::input.c \
		${.CURDIR}/files/patch-include::config.h \
		${.CURDIR}/files/patch-source::screen.c

WITH_LATIN=	YES
# Cursor movement and words wrapping aren't hacked if compiled with gnome.
WITHOUT_GNOME=	YES
# If without gnome, esound support isn't needed.
WITHOUT_ESOUND=	YES

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-
