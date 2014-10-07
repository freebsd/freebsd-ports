# Created by: gahr
# $FreeBSD$

PORTNAME=	tclbsd
PORTVERSION=	1.6
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl interface to various system calls and library routines

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
PORTDOCS=	bsd.pdf

USES=		tcl
USE_AUTOTOOLS=	autoconf

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	1601307

CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR}

PLIST_FILES=	lib/BSD${PORTVERSION}/bsd_procs.tcl \
		lib/BSD${PORTVERSION}/libBSD${PORTVERSION}.so \
		lib/BSD${PORTVERSION}/pkgIndex.tcl \
		man/mann/bsd.n.gz

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bsd.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
