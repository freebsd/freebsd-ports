# New ports collection makefile for:	tclgetopts
# Date created:				4 May 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tcltls
PORTVERSION=	1.5.0
CATEGORIES=	devel tcl83 tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tls
DISTNAME=	tls${PORTVERSION}-src

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	SSL extensions for TCL; dynamicly loadable

LIB_DEPENDS+=	tcl${TCLVND}:${PORTSDIR}/lang/tcl${TCLVND}

USE_OPENSSL=	Yes

WRKSRC=	${WRKDIR}/tls${PORTVERSION:R}

PLIST_SUB+=	TCL_VER=${TCL_VER} DISTNAME="${DISTNAME}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		OPENSSLINC="${OPENSSLINC}" OPENSSLLIB="${OPENSSLLIB}" \
		OPENSSLDIR="${OPENSSLDIR}" CFLAGS="${CFLAGS}" \
		SHLIB_NAME=libtls.so.1 \
		PORTVERSION="${PORTVERSION}" SED="${SED}"
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
ALL_TARGET=	all

post-patch:
	${REINPLACE_CMD} -e \
		's,package require tls.*,load ${WRKSRC}/libtls.so;\
			source ${WRKSRC}/tls.tcl,' \
		${WRKSRC}/tests/*.test
	# The tests in ciphers.test are meaningless so far:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken

post-install:
	${MKDIR} ${PREFIX}/share/doc/tls
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${PREFIX}/share/doc/tls/

post-build test:
	cd ${WRKSRC}/tests && env TCL_LIBRARY="${WRKSRC}" \
		tclsh${TCL_VER} all.tcl

TCL_VER?=	8.4
TCLVND=		${TCL_VER:S/.//}

.include <bsd.port.mk>

PLIST_SUBP!=	${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} environ
PLIST_SUB+=	${PLIST_SUBP}
