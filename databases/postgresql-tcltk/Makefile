# New ports collection makefile for:	PostgreSQL JDBC
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	postgresql
PORTVERSION!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V PORTVERSION
PORTREVISION?=	0
CATEGORIES=	databases tcl83 tk83
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V MASTER_SITE_SUBDIR
PKGNAMESUFFIX=	-tcltk
DISTFILES!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V DISTFILES
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	An TCL interface to the database PostgreSQL, including a tk GUI

LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//} \
		pq:${PORTSDIR}/${POSTGRESQL_PORT}

MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo

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

do-install:
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/bin/pgtclsh install
	@ cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GMAKE} -C src/interfaces/libpgtcl install
# Preparing a loadable TCL-package (pkgIndex.tcl)
	@${MKDIR} ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pkgIndex.tcl.in \
		> ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3/pkgIndex.tcl

.include <bsd.port.mk>
