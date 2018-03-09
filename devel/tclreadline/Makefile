# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL

LICENSE=	BSD3CLAUSE

USES=		autoreconf libtool tcl readline:port
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-tcl-includes=${TCL_INCLUDEDIR} \
		--with-readline-includes=${LOCALBASE}/include \
		--with-readline-library="-L${LOCALBASE}/lib -lreadline"

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USE_LDCONFIG=	yes
TCL_PKG=	${PORTNAME}${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} TCL_PKG=${TCL_PKG}

.include <bsd.port.mk>
