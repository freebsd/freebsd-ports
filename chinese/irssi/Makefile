# New ports collection makefile for:	zh-tw-irssi
# Date created:				April 26 2001
# Whom:					vanilla
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../irc/irssi
EXTRA_PATCHES=	${.CURDIR}/files/patch-irssi.conf \
		${.CURDIR}/files/patch-src::fe-text::gui-entry.c \
		${.CURDIR}/files/patch-src::fe-text::gui-entry.h \
		${.CURDIR}/files/patch-src::fe-text::term-terminfo.c \
		${.CURDIR}/files/patch-src::fe-text::textbuffer-view.c \
		${.CURDIR}/files/patch-src::fe-text::utf8.h

PORTREVISION=	1
CATEGORIES=	chinese

MAINTAINER=	vanilla@FreeBSD.org

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-
COMMENT=	${.CURDIR}/pkg-comment
