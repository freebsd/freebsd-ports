# New ports collection Makefile for:	yajl-tcl
# Date created:				17 July 2012
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	yajl-tcl
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/flightaware/yajl-tcl/

MAINTAIER=	gahr@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD

USE_TCL=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}

PLIST_FILES=	lib/yajltcl${PORTVERSION}/libyajltcl.so.1 \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl
PLIST_DIRS=	lib/yajltcl${PORTVERSION}

LIB_DEPENDS=	yajl:${PORTSDIR}/devel/yajl

.include <bsd.port.mk>
