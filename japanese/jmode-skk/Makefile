# New ports collection makefile for:   jmode-skk
# Date created:        24 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-skk

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	XIM server for SKK input method

MASTERDIR=	${.CURDIR}/../../japanese/jmode
DESCR=		${.CURDIR}/pkg-descr

LIB_DEPENDS=	# empty
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv

CONFIGURE_ARGS=	--with-skk

.include "${MASTERDIR}/Makefile"
