# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	1.0.32
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		tcl${TCL_VER:S/.//}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}
BUILD_DEPENDS=	lemon:${PORTSDIR}/devel/lemon

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2
MAKE_ENV+=	TCL_VER=${TCL_VER}
TCL_VER?=	8.3

GDBM_TOOLS=	gdbmdump gdbmstat

post-build:	test
.for p in ${GDBM_TOOLS}
	cd ${WRKSRC}/tool && ${MAKE} CFLAGS="${CFLAGS} -I${PREFIX}/include" \
		LDADD="-L${PREFIX}/lib -lgdbm" PROG=$p NOMAN=1 \
		-f bsd.prog.mk
.endfor
	cd ${WRKSRC} && ${MAKE} VPATH=${WRKSRC}/src \
		CFLAGS="${CFLAGS} -I${WRKSRC} -I${WRKSRC}/src" \
		LDADD="-L${WRKSRC} -lsqlite" PROG=sqlite SRCS=shell.c NOMAN=1 \
		-f bsd.prog.mk
.ifndef NOPORTDOCS
	cd ${WRKSRC}/www && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_ARGS} -f ${FILESDIR}/Makefile.docs
.endif

post-install:
.for p in ${GDBM_TOOLS}
	cd ${WRKSRC}/tool && ${MAKE} BINDIR="${PREFIX}/bin" \
		PROG=$p NOMAN=1 -f bsd.prog.mk install
.endfor
	cd ${WRKSRC} && ${MAKE} PROG=sqlite NOMAN=1 BINDIR="${PREFIX}/bin" \
		-f bsd.prog.mk install
	${MKDIR} ${PREFIX}/lib/sqlite
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/sqlite
	${INSTALL_DATA} ${WRKSRC}/www/*.html ${WRKSRC}/www/*.png \
		${PREFIX}/share/doc/sqlite
.endif

test:
	# -------------------------------------------------------
	# Running the vendor's tests -- there should be 0 errors.
	# -------------------------------------------------------
	cd ${WRKSRC} && ${PREFIX}/bin/tclsh${TCL_VER} ${WRKSRC}/test/all.test \
		${WRKSRC}/libsqlite.so
	# -------------------------------------------------------

.include <bsd.port.mk>
