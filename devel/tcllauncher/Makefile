# Created by: gahr
# $FreeBSD$

PORTNAME=	tcllauncher
PORTVERSION=	1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Launcher program for Tcl applications

LICENSE=	MIT

LIB_DEPENDS=	libtclx8.4.so:${PORTSDIR}/lang/tclX

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USES+=		tcl
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}

LIBDIR=		lib/Tcllauncher${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${LIBDIR}/tcllauncher.tcl \
		${LIBDIR}/tcllauncher-support.tcl \
		${LIBDIR}/pkgIndex.tcl \
		man/mann/${PORTNAME}.n.gz

.include <bsd.port.mk>
