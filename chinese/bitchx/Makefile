# Created by: clive
# $FreeBSD$

PORTNAME=	BitchX
PORTREVISION=	5
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A zh-tw cursor movement friendly, wrapping clean BitchX

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

MASTERDIR=	${.CURDIR}/../../irc/bitchx
EXTRA_PATCHES=	${.CURDIR}/files/patch-source::input.c \
		${.CURDIR}/files/patch-include::config.h \
		${.CURDIR}/files/patch-source::screen.c

BROKEN=		patch reject

WITH_LATIN=	YES
# Cursor movement and words wrapping aren't hacked if compiled with gnome.
WITHOUT_GNOME=	YES
# If without gnome, esound support isn't needed.
WITHOUT_ESOUND=	YES

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
