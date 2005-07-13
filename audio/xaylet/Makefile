# New ports collection makefile for:	xaylet
# Date created:				9 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	x

COMMENT=	A x11 player for the .ay audio file format

ALL_TARGET=	xaylet

MASTERDIR=	${.CURDIR}/../aylet

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

MAN1=		xaylet.1
PLIST_FILES=	bin/xaylet

post-patch: aylet-post-patch
	${MV} ${WRKSRC}/${PORTNAME}.1 ${WRKSRC}/xaylet.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xaylet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xaylet.1 ${MANPREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
