# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkgeomap
PORTVERSION=	2.11.6
CATEGORIES=	astro tk
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Read, manipulate, and display geo data

LICENSE=	GPLv2

LIB_DEPENDS=	libtclgeomap.so:astro/tclgeomap

USES+=		tk:tea
CONFIGURE_ARGS=	--with-tclgeomap-include=${LOCALBASE}/include/tclgeomap --with-x \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
MAKE_ENV+=	TCLGEOMAP_LIB="-L ${LOCALBASE}/lib -ltclgeomap"
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/=.*PACKAGE_VERSION/s|$${PACKAGE_VERSION}||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^package/!s|@PACKAGE_VERSION@||g' ${WRKSRC}/pkgIndex.tcl.in
	@${REINPLACE_CMD} -e '2s|.*|exit 0|' ${WRKSRC}/mkLinks

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/tkgeomap
	${FIND} ${WRKSRC}/.. -name "*.h" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/include/tkgeomap \;
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkgeomap
	${INSTALL_DATA} ${WRKSRC}/../library/tkgeomap_procs.tcl ${STAGEDIR}${PREFIX}/lib/tkgeomap
	${INSTALL_DATA} ${WRKSRC}/../library/wdgeomap.tcl ${STAGEDIR}${PREFIX}/lib/tkgeomap
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/tkgeomap
	${INSTALL_DATA} ${WRKSRC}/libtkgeomap.so ${STAGEDIR}${PREFIX}/lib/libtkgeomap.so.0
	${LN} -sf libtkgeomap.so.0 ${STAGEDIR}${PREFIX}/lib/libtkgeomap.so
	${FIND} ${WRKSRC}/../doc -name "*.n" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/man/mann \;
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtkgeomap.so.0

.include <bsd.port.mk>
