# ex:ts=8
# New ports collection makefile for:	tin
# Date created:		2 Dev 1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../news/tin

MAINTAINER=     yssu@CCCA.NCTU.edu.tw

EXTRA_PATCHES=	${.CURDIR}/patches/patch-charset.c \
		${.CURDIR}/patches/patch-cook.c \
		${.CURDIR}/patches/patch-init.c

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+=	--disable-curses \
			--without-ncurses \
			--with-mime-default-charset=big5
