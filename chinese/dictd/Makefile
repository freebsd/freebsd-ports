# New ports collection makefile for:	dictd
# Date created:			19 July 2002
# Whom:				Kuang-che Wu <kcwu@ck.tp.edu.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MAINTAINER=	kcwu@ck.tp.edu.tw

MASTERDIR=	${.CURDIR}/../../net/dictd
EXTRA_PATCHES=	${.CURDIR}/files/patch-index.c \
		${.CURDIR}/files/patch-libmaa::arg.c \
		${.CURDIR}/files/patch-dictfmt.c \
		${.CURDIR}/files/patch-Makefile.in

pre-install:
	${ECHO} "bin/dictfmt" > ${PLIST}
	${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}tw-
ALL_TARGET+=	dictfmt
INSTALL_TARGET+=install.dictfmt
PLIST=		${WRKDIR}/PLIST
