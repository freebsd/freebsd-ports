# New ports collection makefile for:	tkgeomap
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkgeomap
PORTVERSION=	2.11.6
CATEGORIES=	astro tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read, manipulate and display geo data

LIB_DEPENDS=	tclgeomap.0:${PORTSDIR}/astro/tclgeomap

CONFIGURE_ARGS=	--with-tclgeomap-include=${LOCALBASE}/include/tclgeomap --with-x \
		--with-tcl=${TCL_LIBDIR} --with-tclinclude=${TCL_INCLUDEDIR} \
		--with-tk=${TK_LIBDIR} --with-tkinclude=${TK_INCLUDEDIR} \
		--x-libraries=${LOCALBASE}/lib --x-includes=${LOCALBASE}/include
CONFIGURE_ENV=	TCLGEOMAP_LIB=${LOCALBASE}/lib/tclgeomap
USE_TK=		82+
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
TKPKG=		${PORTNAME}
PLIST_SUB=	INC=include/${TKPKG} LIB=lib/${TKPKG}
USE_LDCONFIG=	yes

MANN=	igeomap.n tkgeomap.n tkgeomap_procs.n wdgeomap.n

post-install:
	@${LN} -sf ${PREFIX}/lib/lib${TKPKG}.so ${PREFIX}/lib/lib${PORTNAME}.so.0

post-patch:
	@${REINPLACE_CMD} -e '/=.*PACKAGE_VERSION/s|$${PACKAGE_VERSION}||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^package/!s|@PACKAGE_VERSION@||g' ${WRKSRC}/pkgIndex.tcl.in
	@${REINPLACE_CMD} -e '2s|.*|exit 0|' ${WRKSRC}/mkLinks

.include <bsd.port.mk>
