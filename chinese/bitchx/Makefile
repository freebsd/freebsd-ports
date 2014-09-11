# Created by: clive
# $FreeBSD$

PORTNAME=	BitchX
PORTREVISION=	7
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zh-tw cursor movement friendly, wrapping clean BitchX

MASTERDIR=	${.CURDIR}/../../irc/bitchx
EXTRA_PATCHES=	${.CURDIR}/files/patch-source__input.c \
		${.CURDIR}/files/patch-include__config.h \
		${.CURDIR}/files/patch-source__screen.c

WITH_LATIN=	YES
# Cursor movement and words wrapping aren't hacked if compiled with gnome.
WITHOUT_GNOME=	YES
# If without gnome, esound support isn't needed.
WITHOUT_ESOUND=	YES

.include "${MASTERDIR}/Makefile"
