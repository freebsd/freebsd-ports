# New ports collection makefile for:	PostgreSQL PL/Tcl
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	databases tcl${TCLVERSION:S/.//}
PKGNAMESUFFIX=	-pltcl

MAINTAINER=	girgen@pingpong.net
COMMENT=	A module for using Tcl to write SQL functions

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include "../../${POSTGRESQL_PORT}/Makefile"

LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//}
RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.4
CONFIGURE_ARGS=	--with-tcl --without-tk \
		--with-tclconfig="${TCLCONFIG}" \
		--with-includes="${TCL_INCDIR}"

TCL_INCDIR=	${LOCALBASE}/include/tcl${TCLVERSION}
TCLCONFIG=	${LOCALBASE}/lib/tcl${TCLVERSION}
MAKE_ARGS+=	-C src/pl/tcl
MAKE_ENV+=	TCL_INCDIR=${TCL_INCDIR}

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
