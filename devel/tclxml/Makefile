# New ports collection makefile for:	tclxml
# Date created:				2 May 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tclxml
PORTVERSION=	3.1
CATEGORIES=	devel tcl
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tclxml

MAINTAINER?=	dyeske@gmail.com
COMMENT=	API for parsing XML documents using Tcl

RUN_DEPENDS?=	dtplite:${PORTSDIR}/devel/tcllib

USE_TCL=	82+
GNU_CONFIGURE=	yes
USE_LDCONFIG?=	${PREFIX}/lib/Tclxml${PORTVERSION}
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
PLIST=		${PKGDIR}${PKGNAMESUFFIX}/pkg-plist
PATCHDIR=	${PKGDIR}${PKGNAMESUFFIX}/files/
PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
