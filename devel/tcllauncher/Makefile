PORTNAME=	tcllauncher
PORTVERSION=	1.10
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Launcher program for Tcl applications
WWW=		https://github.com/flightaware/tcllauncher/

LICENSE=	MIT

LIB_DEPENDS=	libtclx8.4.so:lang/tclX

USES+=		tcl:tea autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

TCL_PKG=	Tcllauncher${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		lib/${TCL_PKG}/tcllauncher.tcl \
		lib/${TCL_PKG}/tcllauncher-support.tcl \
		lib/${TCL_PKG}/pkgIndex.tcl \
		share/man/mann/${PORTNAME}.n.gz

.include <bsd.port.mk>
