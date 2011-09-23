# New ports collection makefile for:  sfslite-dbg
# Date created:        22 September 2005
# Whom:                max
#
# $FreeBSD$
#
BUILD_MODE=	shdbg
MASTERDIR=	${.CURDIR}/../../devel/sfslite
COMMENT=	sfslite with dmalloc and without optimization

.include "${MASTERDIR}/Makefile"

LIB_DEPENDS+=	dmalloc:${PORTSDIR}/devel/dmalloc
PKG_INSTALL=	${MASTERDIR}/pkg-install

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
