# New ports collection makefile for:	bmp-festalon
# Date created:				15 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	bmp-

COMMENT=	A beep-media-player plugin for playing .nsf and .hes audio files

MASTERDIR=	${.CURDIR}/../festalon

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_X_PREFIX=	yes

CONFIGURE_ARGS+=	--enable-interface=bmp

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PLIST_FILES=	lib/bmp/Input/libfestalon_bmp.a \
		lib/bmp/Input/libfestalon_bmp.la \
		lib/bmp/Input/libfestalon_bmp.so \
		lib/bmp/Input/libfestalon_bmp.so.0

.include "${MASTERDIR}/Makefile"
