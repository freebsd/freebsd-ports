# New ports collection makefile for:	xpinmame
# Date created:				Fri Mar 30 11:00:42 CEST 2001
# Whom:					stijn@win.tue.nl
#
# $FreeBSD$
#

PORTNAME=	xpinmame
PORTVERSION=	${XMAMEVERSION}+${PINMAMEVERSION}

PATCH_SITES+=	http://www.win.tue.nl/~stijn/xmame/
PATCHFILES+=	${DISTNAME}-pinmame-${PINMAMEVERSION}.patch.gz

MAINTAINER=	stijn@win.tue.nl

MASTERDIR=	${.CURDIR}/../xmame
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

MAMEMESS=	pinmame
XMAMEVERSION=	0.37b13.1
PINMAMEVERSION=	0.99b1

.include "${MASTERDIR}/Makefile"
