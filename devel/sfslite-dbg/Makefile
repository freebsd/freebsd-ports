# New ports collection makefile for:  sfslite-dbg
# Date created:        22 September 2005
# Whom:                max
#
# $FreeBSD$
#
BUILD_MODE=      shdbg
MASTERDIR=       ${.CURDIR}/../../devel/sfslite
COMMENT=	sfslite with dmalloc and without optimization

LIB_DEPENDS+=	 dmalloc:${PORTSDIR}/devel/dmalloc
PKG_INSTALL=     ${MASTERDIR}/pkg-install

BROKEN=		does not install
DEPRECATED=	Has been broken for more than 6 months
EXPIRATION_DATE=2008-09-19

.include "${MASTERDIR}/Makefile"
