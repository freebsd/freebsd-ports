# Created by: max
# $FreeBSD$
BUILD_MODE=	shdbg
MASTERDIR=	${.CURDIR}/../../devel/sfslite
COMMENT=	sfslite with dmalloc and without optimization

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"

LIB_DEPENDS+=	dmalloc:${PORTSDIR}/devel/dmalloc
PKG_INSTALL=	${MASTERDIR}/pkg-install

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
