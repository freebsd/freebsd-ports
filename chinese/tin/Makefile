# ex:ts=8
# New ports collection makefile for:	tin
# Date created:		2 Dev 1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MAINTAINER=	leeym@FreeBSD.org

EXTRA_PATCHES=	${.CURDIR}/files/patch-attrib.c \
		${.CURDIR}/files/patch-cook.c \
		${.CURDIR}/files/patch-mail.c \
		${.CURDIR}/files/patch-init.c \
		${.CURDIR}/files/patch-tin_defaults

MASTERDIR=	${.CURDIR}/../../news/tin

CONFIGURE_ARGS=	--disable-locale

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+=--with-screen=termcap --with-mime-default-charset=Big5
