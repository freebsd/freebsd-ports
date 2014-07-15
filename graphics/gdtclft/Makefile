# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	Gdtclft
PORTVERSION=	2.2.5
PORTREVISION=	13
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

MANN=		gdtclft.n
MANCOMPRESSED=	no
GDTCLDIR=	lib/tcl${TCL_VER}/gdtclft
PLIST_DIRS=	${GDTCLDIR}
PLIST_FILES=	${GDTCLDIR}/pkgIndex.tcl
PLIST_FILES+=	${GDTCLDIR}/libGdtclft2.so
.if !defined(NO_STAGE)
PLIST_FILES+=	${__MANPAGES}
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's,[[:space:]]+$$,,' ${WRKSRC}/${MANN}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MANN} ${STAGEDIR}${PREFIX}/man/mann/

.include <bsd.port.mk>
