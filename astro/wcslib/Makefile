# Created by: Tony Maher <tonymaher@optusnet.com.au>
# $FreeBSD$

PORTNAME=	wcslib
PORTVERSION=	4.13.4
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	Library for parsing/generating FITS headers

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

# See makedefs.in which describes why you want to set the extra support.
# For most users it will not be required.

OPTIONS_DEFINE=	CFITSIO PGPLOT
CFITSIO_DESC=	Add cfitsio support (for tests only)
PGPLOT_DESC=	Add pgplot support (for tests only)

.include <bsd.port.options.mk>

# The configure script unconditionally searches for the cftisio library
# and uses it if found.

.if ${PORT_OPTIONS:MCFITSIO} || exists(${LOCALBASE}/lib/libcfitsio.so)
PLIST_SUB+=		HPXCVT=""
LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio
.else
PLIST_SUB+=		HPXCVT="@comment "
.endif

.if ${PORT_OPTIONS:MPGPLOT}
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#%%PKGDIR%%#${STAGEDIR}${PREFIX}/libdata#g' \
		${WRKSRC}/GNUmakefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README COPYING COPYING.LESSER wcslib.pdf ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/html && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
