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

CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
