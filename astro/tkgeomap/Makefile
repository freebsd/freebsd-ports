# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkgeomap
PORTVERSION=	2.11.6
CATEGORIES=	astro tk
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Read, manipulate, and display geo data

LIB_DEPENDS=	libtclgeomap.so:${PORTSDIR}/astro/tclgeomap
NO_STAGE=	yes

CONFIGURE_ARGS=	--with-tclgeomap-include=${LOCALBASE}/include/tclgeomap --with-x \
		--with-tcl=${TCL_LIBDIR} --with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tk=${TK_LIBDIR} --with-tkinclude=${TK_INCLUDEDIR} \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
MAKE_ENV+=	TCLGEOMAP_LIB="-L ${LOCALBASE}/lib -ltclgeomap"
USES+=		tk
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST_SUB=	INC=include/${PORTNAME} LIB=lib/${PORTNAME}
USE_LDCONFIG=	yes

MANN=	igeomap.n tkgeomap.n tkgeomap_procs.n wdgeomap.n

post-install:
	@${LN} -sf ${PREFIX}/lib/lib${PORTNAME}.so ${PREFIX}/lib/lib${PORTNAME}.so.0

post-patch:
	@${REINPLACE_CMD} -e '/=.*PACKAGE_VERSION/s|$${PACKAGE_VERSION}||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^package/!s|@PACKAGE_VERSION@||g' ${WRKSRC}/pkgIndex.tcl.in
	@${REINPLACE_CMD} -e '2s|.*|exit 0|' ${WRKSRC}/mkLinks

.include <bsd.port.mk>
