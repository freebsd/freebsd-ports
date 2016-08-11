# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	tclreadline
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	devel tcl
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GNU readline for TCL

USES=		libtool tcl:tea readline
CONFIGURE_ARGS=	--with-tcl-includes=${TCL_INCLUDEDIR}
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
