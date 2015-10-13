# Created by: Tony Maher <tonymaher@optusnet.com.au>
# $FreeBSD$

PORTNAME=	wcslib
PORTVERSION=	5.10
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Library for parsing/generating FITS headers

GNU_CONFIGURE=	yes
USES=		tar:bzip2 gmake fortran
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	VERSION="${PORTVERSION}"

# See makedefs.in which describes why you want to set the extra support.
# For most users it will not be required.

OPTIONS_DEFINE=	CFITSIO PGPLOT DOCS
OPTIONS_SUB=	yes
CFITSIO_DESC=	Add cfitsio support (for tests only)
PGPLOT_DESC=	Add pgplot support (for tests only)

CFITSIO_CONFIGURE_WITH=	cfitsio
CFITSIO_LIB_DEPENDS=	libcfitsio.so:${PORTSDIR}/astro/cfitsio
PGPLOT_CONFIGURE_WITH=	pgplot
PGPLOT_LIB_DEPENDS=	libpgplot.so:${PORTSDIR}/graphics/pgplot

post-patch:
	@${REINPLACE_CMD} -e 's#%%PKGDIR%%#${STAGEDIR}${PREFIX}/libdata#g' \
		${WRKSRC}/GNUmakefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README COPYING COPYING.LESSER wcslib.pdf ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/html && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
