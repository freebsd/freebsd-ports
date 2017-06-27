# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel tcl

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware
USES=		autoreconf libtool tcl:tea readline:port
CONFIGURE_ARGS+=--with-tcl-includes=${TCL_INCLUDEDIR} \
		--with-readline-includes=${LOCALBASE}/include \
		--with-readline-library="-L${LOCALBASE}/lib -lreadline"
USE_LDCONFIG=	yes
TCL_PKG=	${PORTNAME}${PORTVERSION}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
