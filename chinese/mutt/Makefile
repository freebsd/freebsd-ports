# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../mail/mutt

MAINTAINER=	ycheng@sinica.edu.tw

EXTRA_PATCHES=	${.CURDIR}/files/patch-init.h  \
		${.CURDIR}/files/patch-parse.c  \
		${.CURDIR}/files/patch-pgp.c  \
		${.CURDIR}/files/patch-sendlib.c 

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+= --enable-locales-fix
