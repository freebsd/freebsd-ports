# New ports collection makefile for:	zh-tw-irssi
# Date created:				April 26 2001
# Whom:					vanilla
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../irc/irssi
EXTRA_PATCHES=	${.CURDIR}/files/patch-config.h.in \
		${.CURDIR}/files/patch-configure.in \
		${.CURDIR}/files/patch-src_fe-text_gui-entry.c \
		${.CURDIR}/files/patch-src_fe-text_screen.h \
		${.CURDIR}/files/patch-src_fe-text_window.c

PORTREVISION=	3
CATEGORIES=	chinese

MAINTAINER=	vanilla@FreeBSD.org

USE_AUTOCONF=	yes
CONFIGURE_ARGS+=	--with-big5

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-
COMMENT=	${.CURDIR}/pkg-comment
