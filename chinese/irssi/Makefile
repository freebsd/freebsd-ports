# New ports collection makefile for:	zh-tw-irssi
# Date created:				April 26 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	chinese

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A zh-tw cursor movement friendly, wrapping clean irssi

MASTERDIR=	${.CURDIR}/../../irc/irssi

EXTRA_PATCHES=	${.CURDIR}/files/patch-irssi.conf \
		${.CURDIR}/files/patch-src::fe-text::gui-entry.c \
		${.CURDIR}/files/patch-src::fe-text::gui-entry.h \
		${.CURDIR}/files/patch-src::fe-text::gui-readline.c

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}tw-
