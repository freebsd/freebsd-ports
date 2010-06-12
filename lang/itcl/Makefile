# New ports collection makefile for:	itcl
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itcl
PORTVERSION=	3.4b1
CATEGORIES=	lang tcl
MASTER_SITES=	SF/incrtcl/%5BIncr%20Tcl_Tk%5D-source/3.4
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	erik@smluc.org
COMMENT=	Object-oriented extension to Tcl [incr Tcl]

USE_TCL=	84+

USE_LDCONFIG=	yes
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
		USE_TCL=${USE_TCL} TCL_INCLUDEDIR=${TCL_INCLUDEDIR}

MAKE_JOBS_SAFE=	yes
SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=	${PORTVERSION:R}
MINOR=	${PORTVERSION:E:C/[a-z].*//}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITCL_LIB=	libitcl.so
MAKEFILE=	${FILESDIR}/Makefile.lib
WRKSRC=		${WRKDIR}/itcl3.4

MANCOMPRESSED=	no
MANN=		body.n class.n code.n configbody.n delete.n ensemble.n find.n
MANN+=		is.n itcl.n itclvars.n local.n scope.n
MAN3=		RegisterC.3 Stack.3 Class.3 List.3 Object.3 Preserve.3

ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}

.include <bsd.port.pre.mk>

post-build test:
	cd ${WRKSRC} && ${SETENV} ITCL_LIBRARY=${WRKSRC}/library \
		${TCLSH} tests/all.tcl -load "load ./${ITCL_LIB}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.n ${PREFIX}/man/mann/
	${INSTALL_DATA} ${WRKSRC}/doc/*.3 ${PREFIX}/man/man3/

.include <bsd.port.post.mk>
