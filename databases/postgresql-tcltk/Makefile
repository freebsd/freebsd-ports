# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql-tcltk
CATEGORIES=	databases tcl83 tk83

MAINTAINER=	girgen@partitur.se

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//} \
		pq:${PORTSDIR}/databases/postgresql7

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.3
PLIST_SUB+=	TCLVERSION=${TCLVERSION}
CONFIGURE_ARGS=	--with-tcl \
		--with-tclconfig=${TCLCONFIG} \
		--with-includes=${INCDIRS}

TCL_INCDIR=	${LOCALBASE}/include/tcl${TCLVERSION}
TCLCONFIG=	${LOCALBASE}/lib/tcl${TCLVERSION}
MAKE_ENV+=	TCL_INCDIR=${TCL_INCDIR}
CONFIGURE_ENV+=	LIBS="-lm -L${LOCALBASE}/lib -ltcl${TCLVERSION:S/.//}" \
		CFLAGS=-DPGTCL_USE_TCLOBJ

.if defined(WITHOUT_X11)
WITHOUT_TK=	yes
.endif

.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=	--without-tk
INCDIRS=	${TCL_INCDIR}
PLIST_SUB+=	TK="@comment "
.else
CONFIGURE_ARGS+=	--with-tkconfig="${TKCONFIG}"
TK_INCDIR=	${LOCALBASE}/include/tk${TCLVERSION}
CONFIGURE_ENV+=	WISH=${LOCALBASE}/bin/wish${TCLVERSION}
LIB_DEPENDS+=	tk${TCLVERSION:S/.//}:${PORTSDIR}/x11-toolkits/tk${TCLVERSION:S/.//}
TKCONFIG=	${LOCALBASE}/lib/tk${TCLVERSION}
INCDIRS=	${TCL_INCDIR}:${TK_INCDIR}
PLIST_SUB+=	TK=""
.endif

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
