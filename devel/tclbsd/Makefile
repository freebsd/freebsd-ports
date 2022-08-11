PORTNAME=	tclbsd
PORTVERSION=	1.9.2
PORTREVISION=	0
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/lib${TCL_PKG}.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bsd.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
