# New ports collection makefile for:	tclgetopts
# Date created:				4 May 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tcltls
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	SF/tls/tls/${PORTVERSION}
DISTNAME=	tls${PORTVERSION}-src

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	SSL extensions for TCL; dynamicly loadable

LIB_DEPENDS+=	tcl${TCLVND}:${PORTSDIR}/lang/tcl${TCLVND}

USE_TCL=	83+
USE_OPENSSL=	yes

WRKSRC=	${WRKDIR}/tls${PORTVERSION}

PLIST_SUB+=	TCL_VER=${TCL_VER} DISTNAME="${DISTNAME}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		SHLIB_NAME=libtls.so.1 \
		PORTVERSION="${PORTVERSION}" SED="${SED}"
REINPLACE_ARGS=	-i ""
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu` all
PLIST_SUB=	TLS_VERSION=${PORTVERSION}

post-patch:
	${REINPLACE_CMD} -e \
		's,package require tls.*,load ${WRKSRC}/libtls.so;\
			source ${WRKSRC}/tls.tcl,' \
		${WRKSRC}/tests/*.test
	# The tests in ciphers.test are meaningless so far:
	${MV} ${WRKSRC}/tests/ciphers.test ${WRKSRC}/tests/ciphers.test.broken

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/tls
	${INSTALL_DATA} ${WRKSRC}/tls.htm ${PREFIX}/share/doc/tls/
.endif

post-build:
	#
	#
	# Please, try performing `make test' now and report any failures
	# to the ${PORTNAME} developers:
	#	http://sourceforge.net/tracker/?group_id=13248&atid=113248
	# and/or ${MAINTAINER}.
	#
	#

test:
	cd ${WRKSRC}/tests && env TCL_LIBRARY="${WRKSRC}" \
		tclsh${TCL_VER} all.tcl

TCLVND=		${TCL_VER:S/.//}

.include <bsd.port.mk>

PLIST_SUBP!=	${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} environ
PLIST_SUB+=	${PLIST_SUBP}
