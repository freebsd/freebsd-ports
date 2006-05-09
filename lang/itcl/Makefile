# New ports collection makefile for:	itcl
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itcl
PORTVERSION=	${MAJOR}.${MINOR}.1
PORTREVISION=	1
CATEGORIES=	lang tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=incrtcl
DISTNAME=	itcl${PORTVERSION}
EXTRACT_SUFX=	_src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	[incr Tcl] (A.K.A. "itcl")

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84

WRKSRC=		${WRKDIR}/${DISTNAME}/itcl
INSTALLS_SHLIB=	yes
PKGINSTALL=	${PORTSDIR}/lang/tcl84/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl84/pkg-deinstall.tclsh
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

EXTRACT_AFTER_ARGS=| ${TAR} -xf - itcl${PORTVERSION}/itcl

.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

SHLIB_MAJOR=	1
SHLIB_MINOR=	1
MAJOR=	3
MINOR=	2
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITCL_LIB=	libitcl${MAJOR}${MINOR}.so
MAKEFILE=	${FILESDIR}/Makefile.lib

MANCOMPRESSED=	no
MANN=		body.n class.n code.n configbody.n delete.n ensemble.n find.n
MANN+=		itcl.n itcl_class.n itcl_info.n itclvars.n local.n scope.n

ITCL_LIB_FILE=	${ITCL_LIB}.${SHLIB_MAJOR}

post-patch:
	${REINPLACE_CMD} \
		-e 's,package require Itcl,load [glob \
			${WRKSRC}/${ITCL_LIB}.${SHLIB_MAJOR}*],;' \
		${WRKSRC}/tests/*.test

post-build test:
	cd ${WRKSRC} && ${SETENV} ITCL_LIBRARY=${WRKSRC}/library \
		${PREFIX}/bin/tclsh8.4 tests/all.tcl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.n ${PREFIX}/man/mann/
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

.include <bsd.port.mk>
