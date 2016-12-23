# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
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

post-patch:
	${REINPLACE_CMD} \
	    -e '/^#define MALLOC/d; /^#define FREE/d; s|MALLOC|malloc|g; s|FREE|free|g' \
	    ${WRKSRC}/tclreadline.c
	${REINPLACE_CMD} -e 's|/usr/locanl|/usr/local|' ${WRKSRC}/tclreadlineSetup.tcl.in
	${REINPLACE_CMD} -e 's|/usr/local/bin/tclsh|${TCLSH}|g' \
	    ${WRKSRC}/tclreadlineSetup.tcl.in \
	    ${WRKSRC}/tclreadlineInit.tcl.in \
	    ${WRKSRC}/pkgIndex.tcl.in

.include <bsd.port.mk>
