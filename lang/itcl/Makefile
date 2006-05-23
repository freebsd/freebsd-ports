# New ports collection makefile for:	itcl
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itcl
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	lang tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=incrtcl
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	[incr Tcl] (A.K.A. "itcl")

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84

INSTALLS_SHLIB=	yes
PKGINSTALL=	${PORTSDIR}/lang/tcl84/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl84/pkg-deinstall.tclsh
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=	${PORTVERSION:R}
MINOR=	${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITCL_LIB=	libitcl.so
MAKEFILE=	${FILESDIR}/Makefile.lib

MANCOMPRESSED=	no
MANN=		body.n class.n code.n configbody.n delete.n ensemble.n find.n
MANN+=		is.n itcl.n itclvars.n local.n scope.n
MAN3=		RegisterC.3 Stack.3

ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}

post-build test:
	cd ${WRKSRC} && ${SETENV} ITCL_LIBRARY=${WRKSRC}/library \
		${PREFIX}/bin/tclsh8.4 tests/all.tcl -load "load ./${ITCL_LIB}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.n ${PREFIX}/man/mann/
	${INSTALL_DATA} ${WRKSRC}/doc/*.3 ${PREFIX}/man/man3/

.include <bsd.port.mk>
