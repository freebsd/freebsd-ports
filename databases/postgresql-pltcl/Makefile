# New ports collection makefile for:	PostgreSQL PL/Tcl
# Date created:		January 14, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	postgresql
PORTVERSION!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V PORTVERSION
PORTREVISION?=	0
CATEGORIES=	databases tcl83
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V MASTER_SITE_SUBDIR
PKGNAMESUFFIX=	-pltcl
DISTFILES!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V DISTFILES
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	A module for using Tcl to write SQL functions

LIB_DEPENDS=	tcl${TCLVERSION:S/.//}:${PORTSDIR}/lang/tcl${TCLVERSION:S/.//}
RUN_DEPENDS=	postgres:${PORTSDIR}/${POSTGRESQL_PORT}

MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo

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
