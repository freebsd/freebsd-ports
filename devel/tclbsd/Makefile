# Created by: gahr
# $FreeBSD$

PORTNAME=	tclbsd
PORTVERSION=	1.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl interface to various system calls and library routines

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
PORTDOCS=	bsd.pdf

USES=		autoreconf tcl:tea
TCL_PKG=	BSD${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

PLIST_FILES=	lib/${TCL_PKG}/bsd_procs.tcl \
		lib/${TCL_PKG}/lib${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		man/mann/bsd.n.gz

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bsd.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
