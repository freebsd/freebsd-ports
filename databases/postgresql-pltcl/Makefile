# New ports collection makefile for:	PostgreSQL PL/Tcl
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql-pltcl
CATEGORIES=	databases tcl83

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../postgresql7/Makefile>

LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//}
RUN_DEPENDS=	postgres:${PORTSDIR}/databases/postgresql7

# you can use "make TCLVERSION=8.4" or similar for your favourite tcl version
TCLVERSION?=	8.3
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
