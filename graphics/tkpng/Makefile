# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkpng
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PNG support for Tcl/Tk

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.terms

USES+=		tk
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tkinclude=${TK_INCLUDEDIR} \
		--exec-prefix=${PREFIX} \
		--enable-shared

TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG} TKLIBVER=${TKLIBVER}

PLIST_FILES=	lib/${TKPKG}/lib${TKPKG}.so \
		lib/${TKPKG}/pkgIndex.tcl
PLIST_DIRS=	lib/${TKPKG}

.include <bsd.port.mk>
