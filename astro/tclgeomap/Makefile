# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tclgeomap
PORTVERSION=	2.11.6
CATEGORIES=	astro tcl
MASTER_SITES=	SF/tkgeomap/${PORTNAME}/${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Read, manipulate, and display geo data

LICENSE=	GPLv2

USES+=		tcl:tea
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/=.*PACKAGE_VERSION/s|$${PACKAGE_VERSION}||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^package/!s|@PACKAGE_VERSION@||g' ${WRKSRC}/pkgIndex.tcl.in
	@${REINPLACE_CMD} -e '2s|.*|exit 0|' ${WRKSRC}/mkLinks

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/tclgeomap
	${FIND} ${WRKSRC}/.. -name "*.h" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/include/tclgeomap \;
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tclgeomap
	${INSTALL_DATA} ${WRKSRC}/../library/tclgeomap_procs.tcl ${STAGEDIR}${PREFIX}/lib/tclgeomap
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/tclgeomap
	${INSTALL_DATA} ${WRKSRC}/libtclgeomap.so ${STAGEDIR}${PREFIX}/lib/libtclgeomap.so.0
	${LN} -sf libtclgeomap.so.0 ${STAGEDIR}${PREFIX}/lib/libtclgeomap.so
	${FIND} ${WRKSRC}/../doc -name "*.3" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/man/man3 \;
	${FIND} ${WRKSRC}/../doc -name "*.n" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/man/mann \;
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtclgeomap.so.0

.include <bsd.port.mk>
