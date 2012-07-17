# New ports collection Makefile for:	yajl-tcl
# Date created:				17 July 2012
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	yajl-tcl
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~gahr/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${CLONEDATE}
MASTER_SITE_SUBDIR=	gahr

MAINTAIER=	gahr@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD

USE_TCL=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}

PLIST_FILES=	lib/yajltcl1.2/libyajltcl.so.1 \
		lib/yajltcl1.2/pkgIndex.tcl \
		lib/yajltcl1.2/yajl.tcl
PLIST_DIRS=	lib/yajltcl1.2

CLONEDATE=	20120717
WRKSRC=		${WRKDIR}/${PORTNAME}

LIB_DEPENDS=	yajl:${PORTSDIR}/devel/yajl

.include <bsd.port.mk>
