# Created by: gahr
# $FreeBSD$

PORTNAME=	yajl-tcl
PORTVERSION=	1.3
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD

LIB_DEPENDS=	yajl:${PORTSDIR}/devel/yajl

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES+=		tcl:85+
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR}

PLIST_FILES=	lib/yajltcl${PORTVERSION}/libyajltcl.so.1 \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl
PLIST_DIRS=	lib/yajltcl${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
