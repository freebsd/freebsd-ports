PORTNAME=	tcllauncher
PORTVERSION=	1.10
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Launcher program for Tcl applications

LICENSE=	MIT

LIB_DEPENDS=	libtclx8.4.so:lang/tclX

USES+=		tcl:tea autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

TCL_PKG=	Tcllauncher${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		lib/${TCL_PKG}/tcllauncher.tcl \
		lib/${TCL_PKG}/tcllauncher-support.tcl \
		lib/${TCL_PKG}/pkgIndex.tcl \
		man/mann/${PORTNAME}.n.gz

.include <bsd.port.mk>
