# New ports collection makefile for:	PostgreSQL Tcl/Tk
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES?=	databases tcl${TCLVERSION:C/[^0-9]//g}
PKGNAMESUFFIX=	-tcltk

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A TCL interface to the database PostgreSQL, including a tk GUI

TCLPORTDIR?=	${PORTSDIR}/lang/tcl
TKPORTDIR?=	${PORTSDIR}/x11-toolkits/tk
LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${TCLPORTDIR}${TCLVERSION:C/[^0-9]//g}

USE_PGSQL=	yes
MASTERDIR=	${.CURDIR}/../../databases/postgresql74-server

CONFLICTS=	${PORTNAME}${PKGNAMESUFFIX}-7.[0-3]*

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.4
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

.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=	--without-tk
INCDIRS=	${TCL_INCDIR}
PLIST_SUB+=	TK="@comment "
.else
CONFIGURE_ARGS+=	--with-tkconfig="${TKCONFIG}"
TK_INCDIR=	${LOCALBASE}/include/tk${TCLVERSION}
CONFIGURE_ENV+=	WISH=${LOCALBASE}/bin/wish${TCLVERSION}
LIB_DEPENDS+=	tk${TCLVERSION:S/.//}:${TKPORTDIR}${TCLVERSION:C/[^0-9]//g}
TKCONFIG=	${LOCALBASE}/lib/tk${TCLVERSION}
INCDIRS=	${TCL_INCDIR}:${TK_INCDIR}
PLIST_SUB+=	TK=""
CATEGORIES+=	tk${TCLVERSION:C/[^0-9]//g}
.endif

BUILD_DIRS=	src/port ${INSTALL_DIRS}
INSTALL_DIRS=	src/bin/pgtclsh src/interfaces/libpgtcl
SLAVE_ONLY=	yes

post-install:
# Preparing a loadable TCL-package (pkgIndex.tcl)
	@${MKDIR} ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pkgIndex.tcl.in \
		> ${PREFIX}/lib/tcl${TCLVERSION}/Pgtcl1.3/pkgIndex.tcl

.include "${MASTERDIR}/Makefile"
