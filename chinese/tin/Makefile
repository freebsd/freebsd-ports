# ex:ts=8
# New ports collection makefile for:	tin
# Date created:		2 Dev 1997
# Whom:			Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../news/tin

MAINTAINER=	yssu@CCCA.NCTU.edu.tw

BROKEN=		Fails to patch

EXTRA_PATCHES=	${.CURDIR}/files/patch-attrib.c \
		${.CURDIR}/files/patch-cook.c \
		${.CURDIR}/files/patch-mail.c \
		${.CURDIR}/files/patch-init.c \
		${.CURDIR}/files/patch-tin_defaults

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+=	--disable-locale --with-screen=termcap \
			--with-mime-default-charset=Big5
