# New ports collection makefile for:	PostgreSQL
# Date created:		7 Jun 2000
# Whom:			Tomokatsu Saito <saito@a2z.co.jp>
#
# $FreeBSD$
#

PORTNAME=	postgresql-tcltk
CATEGORIES=	japanese databases

MAINTAINER=	saito@a2z.co.jp

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../../databases/postgresql7/Makefile>

LIB_DEPENDS=	tcl80jp.1:${PORTSDIR}/japanese/tcl80 \
		pq:${PORTSDIR}/databases/postgresql7

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.0jp
PLIST_SUB+=	TCLVERSION=${TCLVERSION}
CONFIGURE_ARGS=	--with-tcl \
		--with-tclconfig=${TCLCONFIG} \
		--with-includes=${INCDIRS}

TCL_INCDIR=	${LOCALBASE}/include/tcl${TCLVERSION}
TCLCONFIG=	${LOCALBASE}/lib/tcl${TCLVERSION}
MAKE_ENV+=	TCL_INCDIR=${TCL_INCDIR}

CONFIGURE_ARGS+= --with-tkconfig="${TKCONFIG}"
TK_INCDIR=	${LOCALBASE}/include/tk${TCLVERSION}
CONFIGURE_ENV+=	WISH=${LOCALBASE}/bin/wish${TCLVERSION}
LIB_DEPENDS+=	tcl80jp:${PORTSDIR}/japanese/tcl80 \
		tk80jp:${PORTSDIR}/japanese/tk80
TKCONFIG=	${LOCALBASE}/lib/tk${TCLVERSION}
INCDIRS=	${TCL_INCDIR}:${TK_INCDIR}
PLIST_SUB+=	TK=""

do-build:
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/bin/pgtclsh
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/interfaces/libpgtcl
.if !defined(WITHOUT_TK)
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/bin/pgaccess
.endif

do-install:
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/bin/pgtclsh install
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/interfaces/libpgtcl install
.if !defined(WITHOUT_TK)
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/bin/pgaccess install
.endif
# Preparing a loadable TCL-package (pkgIndex.tcl)
	@${MKDIR} ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pkgIndex.tcl.in \
		> ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3/pkgIndex.tcl

.include <bsd.port.mk>
