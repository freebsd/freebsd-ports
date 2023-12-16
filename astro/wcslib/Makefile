PORTNAME=	wcslib
PORTVERSION=	8.2.1
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library for parsing/generating FITS headers
WWW=		https://www.atnf.csiro.au/people/mcalabre/WCS/index.html

LICENSE=	GPLv3

USES=		tar:bzip2 gmake fortran

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --docdir=${DOCSDIR}

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
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
PGPLOT_CONFIGURE_WITH=	pgplot
PGPLOT_LIB_DEPENDS=	libpgplot.so:graphics/pgplot \
			libpng.so:graphics/png
PGPLOT_USE=		XORG=x11
PGPLOT_USES=		xorg

post-patch:
	@${REINPLACE_CMD} -e 's#%%PKGDIR%%#${STAGEDIR}${PREFIX}/libdata#g' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
