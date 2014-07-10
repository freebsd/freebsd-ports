# Created by: gahr
# $FreeBSD$

PORTNAME=	yajl-tcl
PORTVERSION=	1.5
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libyajl.so:${PORTSDIR}/devel/yajl

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	803e33a

USES+=		tcl:85+
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

PLIST_FILES=	lib/yajltcl${PORTVERSION}/libyajltcl.so.1 \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl
PLIST_DIRS=	lib/yajltcl${PORTVERSION}

.include <bsd.port.mk>
