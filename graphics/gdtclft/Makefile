# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	Gdtclft
PORTVERSION=	2.2.5
PORTREVISION=	14
CATEGORIES=	graphics tcl
MASTER_SITES=	
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL interface to the Thomas Boutell's Gd library

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USES=		tcl:84+ uidfix

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
			TCL_SHLIB_VER=${TCL_SHLIB_VER} \
			INSTALL_DATA="${INSTALL_DATA}" STAGEDIR="${STAGEDIR}"
ALL_TARGET=	all

MANNPAGE=	gdtclft.n
GDTCLDIR=	lib/tcl${TCL_VER}/gdtclft
PLIST_DIRS=	${GDTCLDIR}
PLIST_FILES=	${GDTCLDIR}/pkgIndex.tcl
PLIST_FILES+=	${GDTCLDIR}/libGdtclft2.so
PLIST_FILES+=	man/mann/${MANNPAGE}.gz

post-patch:
	${REINPLACE_CMD} -Ee 's,[[:space:]]+$$,,' ${WRKSRC}/${MANNPAGE}

post-install:
	${GZIP_CMD} -9 -f < ${WRKSRC}/${MANNPAGE} > ${STAGEDIR}${PREFIX}/man/mann/${MANNPAGE}.gz

.include <bsd.port.mk>
